#include "font.hpp"
#include <string>

namespace gcn
{
    int Font::getStringIndexAt(const std::string& text, int x) const
    {
        unsigned int i;
        int size = 0;

        for (i = 0; i < text.size(); ++i)
        {
            size = getWidth(text.substr(0,i));

            if (size > x)
            {
                return i;
            }
        }

        return text.size();
    }
}
