#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include <map>
#include <string>
#include <vector>
#include "../actionlistener.hpp"
#include "../basiccontainer.hpp"
#include "../keylistener.hpp"
#include "../mouselistener.hpp"
#include "../platform.hpp"

namespace gcn
{
    class Container;
    class Tab;

    class GCN_CORE_DECLSPEC TabbedArea:
        public ActionListener,
        public BasicContainer,
        public KeyListener,
        public MouseListener
    {
        friend class Tab;

    public:
        TabbedArea();
        virtual ~TabbedArea();
        void setOpaque(bool opaque);
        bool isOpaque() const;
        virtual void addTab(const std::string& caption, Widget* widget);
        virtual void addTab(Tab* tab, Widget* widget);
        virtual void removeTabWithIndex(unsigned int index);
        virtual void removeTab(Tab* tab);
        virtual bool isTabSelected(unsigned int index) const;
        virtual bool isTabSelected(Tab* tab);
        virtual void setSelectedTab(unsigned int index);
        virtual void setSelectedTab(Tab* tab);
        virtual int getSelectedTabIndex() const;
        Tab* getSelectedTab();
        virtual void draw(Graphics *graphics);
        virtual void logic();
        void setWidth(int width);
        void setHeight(int height);
        void setSize(int width, int height);
        void setDimension(const Rectangle& dimension);
        void action(const ActionEvent& actionEvent);
        virtual void death(const Event& event);
        virtual void keyPressed(KeyEvent& keyEvent);
        virtual void mousePressed(MouseEvent& mouseEvent);

    protected:
        void adjustSize();
        void adjustTabPositions();
        Tab* mSelectedTab;
        Container* mTabContainer;
        Container* mWidgetContainer;
        std::vector<Tab*> mTabsToDelete;
        std::vector<std::pair<Tab*, Widget*> > mTabs;
        bool mOpaque;
    };
}
