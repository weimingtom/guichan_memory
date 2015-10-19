#pragma once

#if defined(_MSC_VER) && _MSC_VER <= 1200
#pragma warning(disable:4786)
#endif

#include "../keylistener.hpp"
#include "../mouselistener.hpp"
#include "../platform.hpp"
#include "../widget.hpp"
#include <string>

namespace gcn
{
    class GCN_CORE_DECLSPEC TextField:
        public Widget,
        public MouseListener,
        public KeyListener
    {
    public:
        TextField();
        TextField(const std::string& text);
		void setText(const std::string& text);
        const std::string& getText() const;
        void adjustSize();
        void adjustHeight();
        void setCaretPosition(unsigned int position);
        unsigned int getCaretPosition() const;
        virtual void fontChanged();
        virtual void draw(Graphics* graphics);
        virtual void mousePressed(MouseEvent& mouseEvent);
        virtual void mouseDragged(MouseEvent& mouseEvent);
        virtual void keyPressed(KeyEvent& keyEvent);

    protected:
        virtual void drawCaret(Graphics* graphics, int x);
        void fixScroll();
        std::string mText;
        unsigned int mCaretPosition;
        int mXScroll;
    };
}
