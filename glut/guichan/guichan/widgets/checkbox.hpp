#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include <string>
#include "../keylistener.hpp"
#include "../mouselistener.hpp"
#include "../platform.hpp"
#include "../widget.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC CheckBox :
        public Widget,
        public MouseListener,
        public KeyListener
    {
    public:
        CheckBox();
        CheckBox(const std::string &caption, bool selected = false);
        virtual ~CheckBox() { }
        bool isSelected() const;
        void setSelected(bool selected);
        const std::string &getCaption() const;
        void setCaption(const std::string& caption);
        void adjustSize();
        virtual void draw(Graphics* graphics);
        virtual void keyPressed(KeyEvent& keyEvent);
        virtual void mouseClicked(MouseEvent& mouseEvent);
        virtual void mouseDragged(MouseEvent& mouseEvent);

    protected:
        virtual void drawBox(Graphics *graphics);
        virtual void toggleSelected();
        bool mSelected;
        std::string mCaption;
    };
}
