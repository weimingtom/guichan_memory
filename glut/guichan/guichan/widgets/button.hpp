#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include <string>
#include "../focuslistener.hpp"
#include "../graphics.hpp"
#include "../keylistener.hpp"
#include "../mouseevent.hpp"
#include "../mouselistener.hpp"
#include "../platform.hpp"
#include "../widget.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC Button : public Widget,
                                     public MouseListener,
                                     public KeyListener,
                                     public FocusListener
    {
    public:
        Button();
		Button(const std::string& caption);
		void setCaption(const std::string& caption);
		const std::string& getCaption() const;
		void setAlignment(Graphics::Alignment alignment);
		Graphics::Alignment getAlignment() const;
        void setSpacing(unsigned int spacing);
        unsigned int getSpacing() const;
        void adjustSize();
        virtual void draw(Graphics* graphics);
        virtual void focusLost(const Event& event);
        virtual void mousePressed(MouseEvent& mouseEvent);
        virtual void mouseReleased(MouseEvent& mouseEvent);
        virtual void mouseEntered(MouseEvent& mouseEvent);
        virtual void mouseExited(MouseEvent& mouseEvent);
        virtual void mouseDragged(MouseEvent& mouseEvent);
        virtual void keyPressed(KeyEvent& keyEvent);
        virtual void keyReleased(KeyEvent& keyEvent);

    protected:
        bool isPressed() const;
        std::string mCaption;
        bool mHasMouse;
        bool mKeyPressed;
        bool mMousePressed;
        Graphics::Alignment mAlignment;
        unsigned int mSpacing;
    };
}
