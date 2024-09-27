#ifndef RECEIVER_DISPLAYVIEW_HPP
#define RECEIVER_DISPLAYVIEW_HPP

#include <gui_generated/receiver_display_screen/Receiver_displayViewBase.hpp>
#include <gui/receiver_display_screen/Receiver_displayPresenter.hpp>

class Receiver_displayView : public Receiver_displayViewBase
{
public:
    Receiver_displayView();
    virtual ~Receiver_displayView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEIVER_DISPLAYVIEW_HPP
