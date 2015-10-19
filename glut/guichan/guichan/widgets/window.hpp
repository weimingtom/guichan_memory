#pragma once

#if defined(_MSC_VER) && _MSC_VER <= 1200
#pragma warning(disable:4786)
#endif

#include <string>
#include "../mouselistener.hpp"
#include "../platform.hpp"
#include "container.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC Window : public Container,
                                     public MouseListener
    {
    public:
        Window();
        Window(const std::string& caption);
        virtual ~Window();
        void setCaption(const std::string& caption);
        const std::string& getCaption() const;
        void setAlignment(Graphics::Alignment alignment);
        Graphics::Alignment getAlignment() const;
        void setPadding(unsigned int padding);
        unsigned int getPadding() const;
        void setTitleBarHeight(unsigned int height);
        unsigned int getTitleBarHeight();
        void setMovable(bool movable);
        bool isMovable() const;
        void setOpaque(bool opaque);
        bool isOpaque();
        virtual void resizeToContent();
        virtual Rectangle getChildrenArea();
        virtual void draw(Graphics* graphics);
        virtual void mousePressed(MouseEvent& mouseEvent);
        virtual void mouseDragged(MouseEvent& mouseEvent);
        virtual void mouseReleased(MouseEvent& mouseEvent);

    protected:
        std::string mCaption;
        Graphics::Alignment mAlignment;
        unsigned int mPadding;
        unsigned int mTitleBarHeight;
        bool mMovable;
        bool mOpaque;
        int mDragOffsetX;
        int mDragOffsetY;
        bool mMoved;
    };
}
