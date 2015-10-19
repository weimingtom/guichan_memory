#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include "../actionlistener.hpp"
#include "../basiccontainer.hpp"
#include "../deathlistener.hpp"
#include "../focushandler.hpp"
#include "../focuslistener.hpp"
#include "../keylistener.hpp"
#include "../listmodel.hpp"
#include "../mouselistener.hpp"
#include "../platform.hpp"
#include "../selectionlistener.hpp"
#include "listbox.hpp"
#include "scrollarea.hpp"

namespace gcn {
    class GCN_CORE_DECLSPEC DropDown :
        public ActionListener,
        public BasicContainer,
        public KeyListener,
        public MouseListener,
        public FocusListener,
        public SelectionListener
    {
    public:
        DropDown(ListModel *listModel = NULL,
                 ScrollArea *scrollArea = NULL,
                 ListBox *listBox = NULL);
        virtual ~DropDown();
        int getSelected() const;
        void setSelected(int selected);
        void setListModel(ListModel *listModel);
        ListModel *getListModel();
        void adjustHeight();
        void addSelectionListener(SelectionListener* selectionListener);
        void removeSelectionListener(SelectionListener* selectionListener);
        virtual void draw(Graphics* graphics);
        void setBaseColor(const Color& color);
        void setBackgroundColor(const Color& color);
        void setForegroundColor(const Color& color);
        void setFont(Font *font);
        void setSelectionColor(const Color& color);
        virtual Rectangle getChildrenArea();
        virtual void focusLost(const Event& event);
        virtual void action(const ActionEvent& actionEvent);
        virtual void death(const Event& event);
        virtual void keyPressed(KeyEvent& keyEvent);
        virtual void mousePressed(MouseEvent& mouseEvent);
        virtual void mouseReleased(MouseEvent& mouseEvent);
        virtual void mouseWheelMovedUp(MouseEvent& mouseEvent);
        virtual void mouseWheelMovedDown(MouseEvent& mouseEvent);
        virtual void mouseDragged(MouseEvent& mouseEvent);
        virtual void valueChanged(const SelectionEvent& event);

    protected:
        virtual void drawButton(Graphics *graphics);
        virtual void dropDown();
        virtual void foldUp();
        void distributeValueChangedEvent();
        bool mDroppedDown;
        bool mPushed;
        int mFoldedUpHeight;
        ScrollArea* mScrollArea;
        ListBox* mListBox;
        FocusHandler mInternalFocusHandler;
        bool mInternalScrollArea;
        bool mInternalListBox;
        bool mIsDragged;

        typedef std::list<SelectionListener*> SelectionListenerList;

        SelectionListenerList mSelectionListeners;

        typedef SelectionListenerList::iterator SelectionListenerIterator;
    };
}
