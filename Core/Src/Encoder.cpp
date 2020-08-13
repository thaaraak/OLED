#include "Encoder.h"


Encoder::Encoder( GPIO_TypeDef* clkBase, uint16_t clkPin, GPIO_TypeDef* dtBase, uint16_t dtPin )
{
	_clkBase = clkBase;
	_clkPin = clkPin;
	_dtBase = dtBase;
	_dtPin = dtPin;
}
  

void Encoder::clkInterrupt()
{
	int pinClkVal = HAL_GPIO_ReadPin( _clkBase, _clkPin );
	int pinDtVal = HAL_GPIO_ReadPin( _dtBase, _dtPin );

	// Check that we have both pins at detent (HIGH) and that we are expecting detent on this pin's rising edge
	if( pinClkVal == GPIO_PIN_SET && pinDtVal == GPIO_PIN_SET && clkFlag )
	{
		_encoderValue++;
	    dtFlag = 0;
	    clkFlag = 0;
	}

	// Signal that we're expecting pinB to signal the transition to detent from free rotation
	else if ( pinClkVal == GPIO_PIN_SET )
		dtFlag = 1;

}

void Encoder::dtInterrupt()
{
	int pinClkVal = HAL_GPIO_ReadPin( _clkBase, _clkPin );
	int pinDtVal = HAL_GPIO_ReadPin( _dtBase, _dtPin );

	// Check that we have both pins at detent (HIGH) and that we are expecting detent on this pin's rising edge
	if( pinClkVal == GPIO_PIN_SET && pinDtVal == GPIO_PIN_SET && dtFlag )
	{
		_encoderValue--;
	    dtFlag = 0;
	    clkFlag = 0;
	}

	// Signal that we're expecting pinB to signal the transition to detent from free rotation
	else if ( pinDtVal == GPIO_PIN_SET )
		clkFlag = 1;

}

