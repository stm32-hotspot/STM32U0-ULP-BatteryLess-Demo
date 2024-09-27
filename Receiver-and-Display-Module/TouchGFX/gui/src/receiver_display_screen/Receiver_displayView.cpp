#include <gui/receiver_display_screen/Receiver_displayView.hpp>

#include "update_data.h"

#include <gui/receiver_display_screen/Receiver_displayView.hpp>

Receiver_displayView::Receiver_displayView()
{

}

void Receiver_displayView::setupScreen()
{
    Receiver_displayViewBase::setupScreen();
}

void Receiver_displayView::tearDownScreen()
{
    Receiver_displayViewBase::tearDownScreen();
}

void Receiver_displayView::handleTickEvent()
{
  static MeasuredDataTypeDef DataToDisp;
  
  DataToDisp = getData();
  if(DataToDisp.new_data_flag){
      float temp_to_disp = DataToDisp.temp;
      temp_to_disp = temp_to_disp/100;
      temp_graph.addDataPoint(temp_to_disp);
      Unicode::snprintfFloat(temp_textBuffer, TEMP_TEXT_SIZE, "%f", temp_to_disp);
      temp_text.invalidate();

      lux_graph.addDataPoint(DataToDisp.lux);
      Unicode::snprintf(lux_textBuffer, LUX_TEXT_SIZE, "%d", DataToDisp.lux);
      lux_text.invalidate();  
      
      DataToDisp.new_data_flag = 0;
  }
}