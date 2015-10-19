#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include <string>
#include "../graphics.hpp"
#include "../platform.hpp"
#include "../widget.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC Label: public Widget
    {
    public:
        Label();
        Label(const std::string& caption);
        const std::string &getCaption() const;
        void setCaption(const std::string& caption);
        void setAlignment(Graphics::Alignment alignment);
        Graphics::Alignment getAlignment() const;
        void adjustSize();
        virtual void draw(Graphics* graphics);

    protected:
        std::string mCaption;
        Graphics::Alignment mAlignment;
    };
}
