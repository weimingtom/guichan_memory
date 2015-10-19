#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include "../keylistener.hpp"
#include "../mouselistener.hpp"
#include "../platform.hpp"
#include "../widget.hpp"

namespace gcn
{
	class GCN_CORE_DECLSPEC Slider :
        public Widget,
        public MouseListener,
        public KeyListener
    {
    public:
        enum Orientation
        {
            HORIZONTAL = 0,
            VERTICAL
        };

		Slider(double scaleEnd = 1.0);
		Slider(double scaleStart, double scaleEnd);
		virtual ~Slider() { }
		void setScale(double scaleStart, double scaleEnd);
		double getScaleStart() const;
		void setScaleStart(double scaleStart);
		double getScaleEnd() const;
		void setScaleEnd(double scaleEnd);
        double getValue() const;
        void setValue(double value);
        void setMarkerLength(int length);
        int getMarkerLength() const;
        void setOrientation(Orientation orientation);
        Orientation getOrientation() const;
        void setStepLength(double length);
        double getStepLength() const;
        virtual void draw(Graphics* graphics);
        virtual void mousePressed(MouseEvent& mouseEvent);
        virtual void mouseDragged(MouseEvent& mouseEvent);
        virtual void mouseWheelMovedUp(MouseEvent& mouseEvent);
        virtual void mouseWheelMovedDown(MouseEvent& mouseEvent);
        virtual void keyPressed(KeyEvent& keyEvent);

    protected:
        virtual void drawMarker(gcn::Graphics* graphics);
        virtual double markerPositionToValue(int position) const;
        virtual int valueToMarkerPosition(double value) const;
        virtual int getMarkerPosition() const;
        bool mDragged;
        double mValue;
        double mStepLength;
        int mMarkerLength;
        double mScaleStart;
        double mScaleEnd;
        Orientation mOrientation;
    };
}
