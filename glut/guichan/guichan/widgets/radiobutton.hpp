#pragma once

#if defined(_MSC_VER) && _MSC_VER <= 1200
#pragma warning(disable:4786)
#endif

#include <map>
#include <string>
#include "../keylistener.hpp"
#include "../mouselistener.hpp"
#include "../platform.hpp"
#include "../widget.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC RadioButton :
        public Widget,
        public MouseListener,
        public KeyListener
    {
    public:
        RadioButton();
        RadioButton(const std::string &caption,
                    const std::string &group,
                    bool selected = false);
        virtual ~RadioButton();
        bool isSelected() const;
        void setSelected(bool selected);
        const std::string &getCaption() const;
        void setCaption(const std::string caption);
        void setGroup(const std::string &group);
        const std::string &getGroup() const;
        void adjustSize();
        virtual void draw(Graphics* graphics);
        virtual void keyPressed(KeyEvent& keyEvent);
        virtual void mouseClicked(MouseEvent& mouseEvent);
        virtual void mouseDragged(MouseEvent& mouseEvent);

    protected:
        virtual void drawBox(Graphics *graphics);
        bool mSelected;
        std::string mCaption;
        std::string mGroup;
        typedef std::multimap<std::string, RadioButton *> GroupMap;
        typedef GroupMap::iterator GroupIterator;
        static GroupMap mGroupMap;
    };
}
