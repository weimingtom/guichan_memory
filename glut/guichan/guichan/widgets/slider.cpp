#include "slider.hpp"
#include "../graphics.hpp"
#include "../key.hpp"
#include "../mouseinput.hpp"

namespace gcn
{
    Slider::Slider(double scaleEnd)
    {
        mDragged = false;

        mScaleStart = 0;
        mScaleEnd = scaleEnd;

        setFocusable(true);
        setFrameSize(1);
        setOrientation(HORIZONTAL);
        setValue(0);
        setStepLength(scaleEnd / 10);
        setMarkerLength(10);

        addMouseListener(this);
        addKeyListener(this);
    }

    Slider::Slider(double scaleStart, double scaleEnd)
    {
        mDragged = false;

        mScaleStart = scaleStart;
        mScaleEnd = scaleEnd;

        setFocusable(true);
        setFrameSize(1);
        setOrientation(HORIZONTAL);
        setValue(scaleStart);
        setStepLength((scaleEnd  - scaleStart)/ 10);
        setMarkerLength(10);

        addMouseListener(this);
        addKeyListener(this);
    }

    void Slider::setScale(double scaleStart, double scaleEnd)
    {
        mScaleStart = scaleStart;
        mScaleEnd = scaleEnd;
    }

    double Slider::getScaleStart() const
    {
        return mScaleStart;
    }

    void Slider::setScaleStart(double scaleStart)
    {
        mScaleStart = scaleStart;
    }

    double Slider::getScaleEnd() const
    {
        return mScaleEnd;
    }

    void Slider::setScaleEnd(double scaleEnd)
    {
        mScaleEnd = scaleEnd;
    }

    void Slider::draw(gcn::Graphics* graphics)
    {
        Color shadowColor = getBaseColor() - 0x101010;
        int alpha = getBaseColor().a;
         shadowColor.a = alpha;

        graphics->setColor(shadowColor);
        graphics->fillRectangle(gcn::Rectangle(0,0,getWidth(),getHeight()));

        drawMarker(graphics);
    }

    void Slider::drawMarker(gcn::Graphics* graphics)
    {
        gcn::Color faceColor = getBaseColor();
        Color highlightColor, shadowColor;
        int alpha = getBaseColor().a;
        highlightColor = faceColor + 0x303030;
        highlightColor.a = alpha;
        shadowColor = faceColor - 0x303030;
        shadowColor.a = alpha;

        graphics->setColor(faceColor);

        if (getOrientation() == HORIZONTAL)
        {
            int v = getMarkerPosition();
            graphics->fillRectangle(gcn::Rectangle(v + 1, 1, getMarkerLength() - 2, getHeight() - 2));
            graphics->setColor(highlightColor);
            graphics->drawLine(v, 0, v + getMarkerLength() - 1,0);
            graphics->drawLine(v, 0, v, getHeight() - 1);
            graphics->setColor(shadowColor);
            graphics->drawLine(v + getMarkerLength() - 1, 1, v + getMarkerLength() - 1, getHeight() - 1);
            graphics->drawLine(v + 1, getHeight() - 1, v + getMarkerLength() - 1, getHeight() - 1);

            if (isFocused())
            {
                graphics->setColor(getForegroundColor());
                graphics->drawRectangle(Rectangle(v + 2, 2, getMarkerLength() - 4, getHeight() - 4));
            }
        }
        else
        {
            int v = (getHeight() - getMarkerLength()) - getMarkerPosition();
            graphics->fillRectangle(gcn::Rectangle(1, v + 1, getWidth() - 2, getMarkerLength() - 2));
            graphics->setColor(highlightColor);
            graphics->drawLine(0, v, 0, v + getMarkerLength() - 1);
            graphics->drawLine(0, v, getWidth() - 1, v);
            graphics->setColor(shadowColor);
            graphics->drawLine(1, v + getMarkerLength() - 1, getWidth() - 1, v + getMarkerLength() - 1);
            graphics->drawLine(getWidth() - 1, v + 1, getWidth() - 1, v + getMarkerLength() - 1);

            if (isFocused())
            {
                graphics->setColor(getForegroundColor());
                graphics->drawRectangle(Rectangle(2, v + 2, getWidth() - 4, getMarkerLength() - 4));
            }
        }
    }

    void Slider::mousePressed(MouseEvent& mouseEvent)
    {
        if (mouseEvent.getButton() == gcn::MouseEvent::LEFT
            && mouseEvent.getX() >= 0
            && mouseEvent.getX() <= getWidth()
            && mouseEvent.getY() >= 0
            && mouseEvent.getY() <= getHeight())
        {
            if (getOrientation() == HORIZONTAL)
            {
                setValue(markerPositionToValue(mouseEvent.getX() - getMarkerLength() / 2));
            }
            else
            {
                setValue(markerPositionToValue(getHeight() - mouseEvent.getY() - getMarkerLength() / 2));
            }

            distributeActionEvent();
        }
    }

    void Slider::mouseDragged(MouseEvent& mouseEvent)
    {
        if (getOrientation() == HORIZONTAL)
        {
            setValue(markerPositionToValue(mouseEvent.getX() - getMarkerLength() / 2));
        }
        else
        {
            setValue(markerPositionToValue(getHeight() - mouseEvent.getY() - getMarkerLength() / 2));
        }

        distributeActionEvent();

        mouseEvent.consume();
    }

    void Slider::setValue(double value)
    {
        if (value > getScaleEnd())
        {
            mValue = getScaleEnd();
            return;
        }

        if (value < getScaleStart())
        {
            mValue = getScaleStart();
            return;
        }

        mValue = value;
    }

    double Slider::getValue() const
    {
        return mValue;
    }

    int Slider::getMarkerLength() const
    {
        return mMarkerLength;
    }

    void Slider::setMarkerLength(int length)
    {
        mMarkerLength = length;
    }

    void Slider::keyPressed(KeyEvent& keyEvent)
    {
        Key key = keyEvent.getKey();

        if (getOrientation() == HORIZONTAL)
        {
            if (key.getValue() == Key::RIGHT)
            {
                setValue(getValue() + getStepLength());
                distributeActionEvent();
                keyEvent.consume();
            }
            else if (key.getValue() == Key::LEFT)
            {
                setValue(getValue() - getStepLength());
                distributeActionEvent();
                keyEvent.consume();
            }            
        }
        else
        {
            if (key.getValue() == Key::UP)
            {
                setValue(getValue() + getStepLength());
                distributeActionEvent();
                keyEvent.consume();
            }
            else if (key.getValue() == Key::DOWN)
            {
                setValue(getValue() - getStepLength());
                distributeActionEvent();
                keyEvent.consume();
            }
        }
    }

    void Slider::setOrientation(Slider::Orientation orientation)
    {
        mOrientation = orientation;
    }

    Slider::Orientation Slider::getOrientation() const
    {
        return mOrientation;
    }

    double Slider::markerPositionToValue(int v) const
    {
        int w;
        if (getOrientation() == HORIZONTAL)
        {
            w = getWidth();
        }
        else
        {
            w = getHeight();
        }

        double pos = v / ((double)w - getMarkerLength());
        return (1.0 - pos) * getScaleStart() + pos * getScaleEnd();

    }

    int Slider::valueToMarkerPosition(double value) const
    {
        int v;
        if (getOrientation() == HORIZONTAL)
        {
            v = getWidth();
        }
        else
        {
            v = getHeight();
        }

        int w =  (int)((v - getMarkerLength())
                       * (value  - getScaleStart())
                       / (getScaleEnd() - getScaleStart()));

        if (w < 0)
        {
            return 0;
        }

        if (w > v - getMarkerLength())
        {
            return v - getMarkerLength();
        }

        return w;
    }

    void Slider::setStepLength(double length)
    {
        mStepLength = length;
    }

    double Slider::getStepLength() const
    {
        return mStepLength;
    }

    int Slider::getMarkerPosition() const
    {
        return valueToMarkerPosition(getValue());
    }

    void Slider::mouseWheelMovedUp(MouseEvent& mouseEvent)
    {
        setValue(getValue() + getStepLength());
        distributeActionEvent();

        mouseEvent.consume();
    }

    void Slider::mouseWheelMovedDown(MouseEvent& mouseEvent)
    {
        setValue(getValue() - getStepLength());
        distributeActionEvent();

        mouseEvent.consume();
    }
}
