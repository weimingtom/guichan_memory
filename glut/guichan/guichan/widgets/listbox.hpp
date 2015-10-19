#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include <list>
#include "../keylistener.hpp"
#include "../listmodel.hpp"
#include "../mouselistener.hpp"
#include "../platform.hpp"
#include "../widget.hpp"

namespace gcn
{
    class SelectionListener;

    class GCN_CORE_DECLSPEC ListBox :
        public Widget,
        public MouseListener,
        public KeyListener
    {
    public:
        ListBox();
        ListBox(ListModel *listModel);
        virtual ~ListBox() { }
        int getSelected() const;
        void setSelected(int selected);
        void setListModel(ListModel *listModel);
        ListModel *getListModel();
        void adjustSize();
        bool isWrappingEnabled() const;
        void setWrappingEnabled(bool wrappingEnabled);
        void addSelectionListener(SelectionListener* selectionListener);
        void removeSelectionListener(SelectionListener* selectionListener);
        virtual unsigned int getRowHeight() const;
        virtual void draw(Graphics* graphics);
        virtual void logic();
        virtual void keyPressed(KeyEvent& keyEvent);
        virtual void mousePressed(MouseEvent& mouseEvent);
        virtual void mouseWheelMovedUp(MouseEvent& mouseEvent);
        virtual void mouseWheelMovedDown(MouseEvent& mouseEvent);
        virtual void mouseDragged(MouseEvent& mouseEvent);

    protected:
        void distributeValueChangedEvent();
        int mSelected;
        ListModel *mListModel;
        bool mWrappingEnabled;

        typedef std::list<SelectionListener*> SelectionListenerList;

        SelectionListenerList mSelectionListeners;

        typedef SelectionListenerList::iterator SelectionListenerIterator;
    };
}
