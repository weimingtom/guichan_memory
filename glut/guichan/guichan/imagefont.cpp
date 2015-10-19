#ifdef _DEBUG
#include <stdio.h>
#endif

#include "imagefont.hpp"
#include <sstream>
#include "color.hpp"
#include "exception.hpp"
#include "graphics.hpp"
#include "image.hpp"


namespace gcn
{
    ImageFont::ImageFont(const std::string& filename,
                         const std::string& glyphs)
    {
        mFilename = filename;
        mImage = Image::load(filename, false);

        Color separator = mImage->getPixel(0, 0);
#ifdef _DEBUG
		fprintf(stderr, "[ImageFont::ImageFont][separator] : [%X, %X, %X, %X]\n", 
			separator.r, separator.g, separator.b, separator.a);
        
		//Color separator2 = mImage->getPixel(1, 4);
		//fprintf(stderr, "[ImageFont::ImageFont][separator(1, 4)] : [%X, %X, %X, %X]\n", 
		//	separator2.r, separator2.g, separator2.b, separator2.a);
#endif
        int i = 0;
        for (i = 0;
             i < mImage->getWidth() && separator == mImage->getPixel(i, 0);
             ++i)
        {
        }

        if (i >= mImage->getWidth())
        {
            throw GCN_EXCEPTION("Corrupt image.");
        }

        int j = 0;
#ifdef _DEBUG
		fprintf(stderr, "[ImageFont::ImageFont]mImage->getHeight() == %d, i == %d\n", 
			mImage->getHeight(), i);
#endif
		Color colorTemp2;
        for (j = 0; j < mImage->getHeight(); ++j)
        {
#ifdef _DEBUG
			colorTemp2 = mImage->getPixel(i, j);
#endif
            if (separator == colorTemp2/*mImage->getPixel(i, j)*/)
            {
                break;
            }
        }

        mHeight = j;
        int x = 0, y = 0;
        unsigned char k;

        for (i = 0; i < (int)glyphs.size(); ++i)
        {
            k = glyphs.at(i);
#ifdef _DEBUG
			fprintf(stderr, "[ImageFont::ImageFont][%s][%d / %d] : [%c]\n", 
				filename.c_str(), i, glyphs.size(), k);
#endif
            mGlyph[k] = scanForGlyph(k, x, y, separator);
            // Update x och y with new coordinates.
            x = mGlyph[k].x + mGlyph[k].width;
            y =  mGlyph[k].y;
        }

        mImage->convertToDisplayFormat();

        mRowSpacing = 0;
        mGlyphSpacing = 0;
    }

    ImageFont::ImageFont(Image* image,
                         const std::string& glyphs)
    {
        mFilename = "Image*";
        if (image == NULL)
        {
                GCN_EXCEPTION("Font image is NULL");
        }
        mImage = image;

        Color separator = mImage->getPixel(0, 0);

        int i = 0;
        for (i = 0;
             i < mImage->getWidth() && separator == mImage->getPixel(i, 0);
             ++i)
        {
        }

        if (i >= mImage->getWidth())
        {
            throw GCN_EXCEPTION("Corrupt image.");
        }

        int j = 0;
        for (j = 0; j < mImage->getHeight(); ++j)
        {
            if (separator == mImage->getPixel(i, j))
            {
                break;
            }
        }

        mHeight = j;
        int x = 0, y = 0;
        unsigned char k;

        for (i = 0; i < (int)glyphs.size(); ++i)
        {
            k = glyphs.at(i);
            mGlyph[k] = scanForGlyph(k, x, y, separator);
            // Update x och y with new coordinates.
            x = mGlyph[k].x + mGlyph[k].width;
            y =  mGlyph[k].y;
        }

        mImage->convertToDisplayFormat();

        mRowSpacing = 0;
        mGlyphSpacing = 0;
    }

    ImageFont::ImageFont(const std::string& filename,
                         unsigned char glyphsFrom,
                         unsigned char glyphsTo)
    {
        mFilename = filename;
        mImage = Image::load(filename, false);

        Color separator = mImage->getPixel(0, 0);

        int i = 0;
        for (i=0; separator == mImage->getPixel(i, 0)
                 && i < mImage->getWidth(); ++i)
        {
        }

        if (i >= mImage->getWidth())
        {
            throw GCN_EXCEPTION("Corrupt image.");
        }

        int j = 0;
        for (j = 0; j < mImage->getHeight(); ++j)
        {
            if (separator == mImage->getPixel(i, j))
            {
                break;
            }
        }

        mHeight = j;
        int x = 0, y = 0;

        for (i = glyphsFrom; i < glyphsTo + 1; i++)
        {
            mGlyph[i] = scanForGlyph(i, x, y, separator);
            // Update x och y with new coordinates.
            x = mGlyph[i].x + mGlyph[i].width;
            y =  mGlyph[i].y;
        }

        mImage->convertToDisplayFormat();

        mRowSpacing = 0;
        mGlyphSpacing = 0;
    }

    ImageFont::~ImageFont()
    {
        delete mImage;
    }

    int ImageFont::getWidth(unsigned char glyph) const
    {
        if (mGlyph[glyph].width == 0)
        {
            return mGlyph[(int)(' ')].width + mGlyphSpacing;
        }

        return mGlyph[glyph].width + mGlyphSpacing;
    }

    int ImageFont::getHeight() const
    {
        return mHeight + mRowSpacing;
    }

    int ImageFont::drawGlyph(Graphics* graphics,
                             unsigned char glyph,
                             int x, int y)
    {
        // This is needed for drawing the glyph in the middle
        // if we have spacing.
        int yoffset = getRowSpacing() / 2;

        if (mGlyph[glyph].width == 0)
        {
            graphics->drawRectangle(Rectangle(x,
                                              y + 1 + yoffset,
                                              mGlyph[(int)(' ')].width - 1,
                                              mGlyph[(int)(' ')].height - 2));

            return mGlyph[(int)(' ')].width + mGlyphSpacing;
        }

        graphics->drawImage(mImage,
                            mGlyph[glyph].x,
                            mGlyph[glyph].y,
                            x,
                            y + yoffset,
                            mGlyph[glyph].width,
                            mGlyph[glyph].height);

        return mGlyph[glyph].width + mGlyphSpacing;
    }

    void ImageFont::drawString(Graphics* graphics,
                               const std::string& text,
                               int x,
                               int y)
    {
        unsigned int i;

        for (i = 0; i < text.size(); ++i)
        {
            drawGlyph(graphics, text.at(i), x, y);
            x += getWidth(text.at(i));
        }
    }

    void ImageFont::setRowSpacing(int spacing)
    {
        mRowSpacing = spacing;
    }

    int ImageFont::getRowSpacing()
    {
        return mRowSpacing;
    }

    void ImageFont::setGlyphSpacing(int spacing)
    {
        mGlyphSpacing = spacing;
    }

    int ImageFont::getGlyphSpacing()
    {
        return mGlyphSpacing;
    }

    Rectangle ImageFont::scanForGlyph(unsigned char glyph,
                                      int x,
                                      int y,
                                      const Color& separator)
    {
        Color color;
        do
        {
            ++x;

            if (x >= mImage->getWidth())
            {
                y += mHeight + 1;
                x = 0;

                if (y >= mImage->getHeight())
                {
                    std::string str;
                    std::ostringstream os(str);
                    os << "Image ";
                    os << mFilename;
                    os << " with font is corrupt near character '";
                    os << glyph;
                    os << "'";
                    throw GCN_EXCEPTION(os.str());
                }
            }

            color = mImage->getPixel(x, y);

        } while (color == separator);

        int width = 0;

        do
        {
            ++width;

            if (x + width >= mImage->getWidth())
            {
                std::string str;
                std::ostringstream os(str);
                os << "Image ";
                os << mFilename;
                os << " with font is corrupt near character '";
                os << glyph;
                os << "'";
#ifdef _DEBUG
				fprintf(stderr, "[ImageFont::scanForGlyph]%s : %d >= %d\n", 
					mFilename.c_str(), x + width, mImage->getWidth());
#endif
                throw GCN_EXCEPTION(os.str());
            }

#ifdef _DEBUG
			Color colorTemp = mImage->getPixel(0, 0);
			Color colorTemp7 = mImage->getPixel(7, 0);
			Color colorTemp14 = mImage->getPixel(14, 0);
#endif
            color = mImage->getPixel(x + width, y);

        } while (color != separator);

        return Rectangle(x, y, width, mHeight);
    }

    int ImageFont::getWidth(const std::string& text) const
    {
        unsigned int i;
        int size = 0;

        for (i = 0; i < text.size(); ++i)
        {
            size += getWidth(text.at(i));
        }

        return size - mGlyphSpacing;
    }

    int ImageFont::getStringIndexAt(const std::string& text, int x) const
    {
        unsigned int i;
        int size = 0;

        for (i = 0; i < text.size(); ++i)
        {
            size += getWidth(text.at(i));

            if (size > x)
            {
                return i;
            }
        }

        return text.size();
    }
}
