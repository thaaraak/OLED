#include "FrequencyDisplay.h"


FrequencyDisplay::FrequencyDisplay( OLED_GFX* oled, Encoder* encoder, int frequency )
{
	_oled = oled;
	_encoder = encoder;

	_oled->Device_Init();
	_oled->setFont( &FreeMono12pt7b );
	_oled->setTextColor( RED );

	_frequency = frequency;
	_radix = 1000;
	_mode = Mode::MODE_CHANGE_FREQUENCY;
}
  
void FrequencyDisplay::change()
{
	  _oled->setCursor( 0, 50 );
	  _oled->setTextColor( RED, BLACK );

	  if ( _encoder->isUp() )
		  _frequency += _radix;
	  else
		  _frequency -= _radix;

	  int millions = _frequency / 1000000;
	  int thousands = ( _frequency - millions * 1000000 ) / 1000;
	  int units = _frequency % 1000;

	  _oled->printf( "%02d.%03d.%02d ", millions, thousands, units/10 );

}
