#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include "container.hpp"
#include <vector>

namespace gcn
{
    namespace contrib
    {
        class AdjustingContainer : public gcn::Container
        {
        public:
            AdjustingContainer();
			virtual ~AdjustingContainer();
			virtual void setNumberOfColumns(unsigned int numberOfColumns);
			virtual void setColumnAlignment(unsigned int column, unsigned int alignment);
            virtual void setPadding(unsigned int paddingLeft,
                                    unsigned int paddingRight,
                                    unsigned int paddingTop,
                                    unsigned int paddingBottom);
            virtual void setVerticalSpacing(unsigned int verticalSpacing);
            virtual void setHorizontalSpacing(unsigned int horizontalSpacing);
            virtual void adjustContent();
            virtual void logic();
            virtual void add(Widget *widget);
            virtual void add(Widget *widget, int x, int y);
            virtual void remove(Widget *widget);
            virtual void clear();

            enum
            {
                LEFT = 0,
                CENTER,
                RIGHT
            };

        protected:
            virtual void adjustSize();

            std::vector<Widget*> mContainedWidgets;
            std::vector<unsigned int> mColumnWidths;
            std::vector<unsigned int> mColumnAlignment;
            std::vector<unsigned int> mRowHeights;
            unsigned int mWidth;
            unsigned int mHeight;
            unsigned int mNumberOfColumns;
            unsigned int mNumberOfRows;
            unsigned int mPaddingLeft;
            unsigned int mPaddingRight;
            unsigned int mPaddingTop;
            unsigned int mPaddingBottom;
            unsigned int mVerticalSpacing;
            unsigned int mHorizontalSpacing;
        };
    }
}

