// 4.24.0 0xcbbf5f06
// Generated by imageconverter. Please, do not edit!

#include <images/BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_background[]; // BITMAP_BACKGROUND_ID = 0, Size: 324x245 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_background, 0, 324, 245, 0, 0, 324, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 245, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase
