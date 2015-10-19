#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include <list>
#include "../basiccontainer.hpp"
#include "../graphics.hpp"
#include "../platform.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC Container: public BasicContainer
    {
    public:
        Container();
        virtual ~Container();
        void setOpaque(bool opaque);
        bool isOpaque() const;
        virtual void add(Widget* widget);
        virtual void add(Widget* widget, int x, int y);
        virtual void remove(Widget* widget);
        virtual void clear();
        virtual Widget* findWidgetById(const std::string &id);
        virtual void draw(Graphics* graphics);

    protected:
        bool mOpaque;
    };
}
