#include "container.hpp"
#include "../exception.hpp"
#include "../graphics.hpp"

namespace gcn
{

    Container::Container()
    {
        mOpaque = true;
    }

    Container::~Container()
    {

    }

    void Container::draw(Graphics* graphics)
    {
        if (isOpaque())
        {
            graphics->setColor(getBaseColor());
            graphics->fillRectangle(Rectangle(0, 0, getWidth(), getHeight()));
        }

        drawChildren(graphics);
    }

    void Container::setOpaque(bool opaque)
    {
        mOpaque = opaque;
    }

    bool Container::isOpaque() const
    {
        return mOpaque;
    }

    void Container::add(Widget* widget)
    {
        BasicContainer::add(widget);
    }

    void Container::add(Widget* widget, int x, int y)
    {
        widget->setPosition(x, y);
        BasicContainer::add(widget);
    }

    void Container::remove(Widget* widget)
    {
        BasicContainer::remove(widget);
    }

    void Container::clear()
    {
        BasicContainer::clear();
    }

    Widget* Container::findWidgetById(const std::string &id)
    {
        return BasicContainer::findWidgetById(id);
    }
}
