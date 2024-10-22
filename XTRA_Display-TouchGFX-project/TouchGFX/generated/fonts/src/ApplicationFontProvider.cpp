/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <fonts/ApplicationFontProvider.hpp>
#include <fonts/GeneratedFont.hpp>
#include <texts/TypedTextDatabase.hpp>

touchgfx::FlashDataReader* ApplicationFontProvider::fontFlashReader = 0;

touchgfx::Font* ApplicationFontProvider::getFont(touchgfx::FontId typography)
{
    switch (typography)
    {
    case Typography::DEFAULT:
        // verdana_11_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[0]);
    case Typography::LARGE:
        // verdana_25_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[1]);
    case Typography::SMALL:
        // verdana_10_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[2]);
    case Typography::TITLE:
        // verdanab_24_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[3]);
    default:
        return 0;
    }
}
