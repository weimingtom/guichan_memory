#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include <map>
#include <string>
#include "../basiccontainer.hpp"
#include "../mouselistener.hpp"
#include "../platform.hpp"

namespace gcn
{
    class Label;
    class TabbedArea;

    class GCN_CORE_DECLSPEC Tab:
        public BasicContainer,
        public MouseListener
    {
    public:
        Tab();
        virtual ~Tab();
        void adjustSize();
        void setTabbedArea(TabbedArea* tabbedArea);
        TabbedArea* getTabbedArea();
        void setCaption(const std::string& caption);
        const std::string& getCaption() const;
        virtual void draw(Graphics *graphics);
        virtual void mouseEntered(MouseEvent& mouseEvent);
        virtual void mouseExited(MouseEvent& mouseEvent);

    protected:
        Label* mLabel;
        bool mHasMouse;
        TabbedArea* mTabbedArea;
    };
}
