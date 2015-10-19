#include "key.hpp"

namespace gcn
{
    Key::Key(int value)
            :mValue(value)
    {
    }

    bool Key::isCharacter() const
    {
        return (mValue >= 32 && mValue <= 126)
            || (mValue >= 162 && mValue <= 255)
            || (mValue == 9);
    }

    bool Key::isNumber() const
    {
        return mValue >= 48 && mValue <= 57;
    }

    bool Key::isLetter() const
    {
        return (((mValue >= 65 && mValue <= 90)
                 || (mValue >= 97 && mValue <= 122)
                 || (mValue >= 192 && mValue <= 255))
                && (mValue != 215) && (mValue != 247));
    }

    int Key::getValue() const
    {
        return mValue;
    }
		
	bool Key::operator==(const Key& key) const
	{
		return mValue == key.mValue;
	}

	bool Key::operator!=(const Key& key) const
	{
		return (mValue != key.mValue);
	}
}
