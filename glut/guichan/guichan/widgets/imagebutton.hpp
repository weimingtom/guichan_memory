#pragma once

#if defined(_MSC_VER)
#pragma warning(disable:4786)
#endif
#include "../platform.hpp"
#include "button.hpp"

namespace gcn
{
    class Image;
    
    class GCN_CORE_DECLSPEC ImageButton : public gcn::Button
    {
    public:
        ImageButton();
		ImageButton(const std::string& filename);
		ImageButton(const Image* image);
		virtual ~ImageButton();
		void setImage(const Image* image);
		const Image* getImage() const;
		void draw(gcn::Graphics* graphics);

    protected:
        const Image* mImage;
        bool mInternalImage;
    };
}
