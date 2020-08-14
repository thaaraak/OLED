#ifndef __FREQUENCY_DISPLAY_H
#define __FREQUENCY_DISPLAY_H

#include "stm32f4xx_hal.h"
#include <stdbool.h>

#include "Encoder.h"
#include "OLED_Driver.h"
#include "OLED_GFX.h"
#include "FreeMono12pt7b.h"

class FrequencyDisplay
{
  
  public:
      
    FrequencyDisplay( OLED_GFX* oled, Encoder* encoder, int frequency );

    void change();
      
  private:
    
    enum Mode
    {
          MODE_CHANGE_FREQUENCY,
          MODE_CHANGE_RADIX
    };

    OLED_GFX*	_oled;
    Encoder*	_encoder;

    int 		_frequency;
    int			_radix;
    Mode		_mode;
};


#endif
