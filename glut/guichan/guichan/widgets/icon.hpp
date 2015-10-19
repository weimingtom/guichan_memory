#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include "../image.hpp"
#include "../platform.hpp"
#include "../widget.hpp"

namespace gcn
{
    class GCN_CORE_DECLSPEC Icon: public Widget
    {
    public:
        Icon();
        Icon(const std::string& filename);
        Icon(const Image* image);
        virtual ~Icon();
        void setImage(const Image* image);
        const Image* getImage() const;
        virtual void draw(Graphics* graphics);

    protected:
        const Image* mImage;
        bool mInternalImage;
    };
}
