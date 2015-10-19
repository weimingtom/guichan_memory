#pragma once

#if defined(_MSC_VER) && _MSC_VER <= 1200
#pragma warning(disable:4786)
#endif

#include <ctime>
#include <string>
#include <vector>
#include "../keylistener.hpp"
#include "../mouselistener.hpp"
#include "../platform.hpp"
#include "../widget.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC TextBox:
        public Widget,
        public MouseListener,
        public KeyListener
    {
    public:
        TextBox();
        TextBox(const std::string& text);
        void setText(const std::string& text);
        std::string getText() const;
        const std::string& getTextRow(int row) const;
        void setTextRow(int row, const std::string& text);
        unsigned int getNumberOfRows() const;
        unsigned int getCaretPosition() const;
        void setCaretPosition(unsigned int position);
        unsigned int getCaretRow() const;
        void setCaretRow(int row);
        unsigned int getCaretColumn() const;
        void setCaretColumn(int column);
        void setCaretRowColumn(int row, int column);
        virtual void scrollToCaret();
        bool isEditable() const;
        void setEditable(bool editable);
        virtual void addRow(const std::string row);
        bool isOpaque();
        void setOpaque(bool opaque);
        virtual void draw(Graphics* graphics);
        virtual void fontChanged();
        virtual void keyPressed(KeyEvent& keyEvent);
        virtual void mousePressed(MouseEvent& mouseEvent);
        virtual void mouseDragged(MouseEvent& mouseEvent);

    protected:
        virtual void drawCaret(Graphics* graphics, int x, int y);
        virtual void adjustSize();
        std::vector<std::string> mTextRows;
        int mCaretColumn;
        int mCaretRow;
        bool mEditable;
        bool mOpaque;
    };
}
