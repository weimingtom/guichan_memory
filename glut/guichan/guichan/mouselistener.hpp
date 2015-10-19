#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif

#include "mouseevent.hpp"
#include "platform.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC MouseListener
    {
    public:
		virtual ~MouseListener() { }
        virtual void mouseEntered(MouseEvent& mouseEvent)
        {

        }
		
		virtual void mouseExited(MouseEvent& mouseEvent)
        {

        }
		
		virtual void mousePressed(MouseEvent& mouseEvent)
        {

        }
		
		virtual void mouseReleased(MouseEvent& mouseEvent)
        {

        }
		
		virtual void mouseClicked(MouseEvent& mouseEvent)
        {
			
        }
			
		virtual void mouseWheelMovedUp(MouseEvent& mouseEvent)
        {

        }
        
        virtual void mouseWheelMovedDown(MouseEvent& mouseEvent)
        {
		
        }
        
        virtual void mouseMoved(MouseEvent& mouseEvent)
        {

        }
        
        virtual void mouseDragged(MouseEvent& mouseEvent)
        {
			
        }
			
    protected:
        MouseListener() { }
    };
}
