#ifndef RECEIVER_DISPLAYPRESENTER_HPP
#define RECEIVER_DISPLAYPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Receiver_displayView;

class Receiver_displayPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Receiver_displayPresenter(Receiver_displayView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Receiver_displayPresenter() {}

private:
    Receiver_displayPresenter();

    Receiver_displayView& view;
};

#endif // RECEIVER_DISPLAYPRESENTER_HPP
