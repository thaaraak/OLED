/*
 * main.cpp
 *
 *  Created on: Jul 25, 2020
 *      Author: xenir
 */

#include "OLED_Driver.h"
#include "OLED_GFX.h"
#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>

#include "FreeMonoBoldOblique24pt7b.h"
#include "FreeMonoOblique18pt7b.h"
#include "FreeMono18pt7b.h"
#include "FreeMono12pt7b.h"
#include "FreeSans18pt7b.h"

OLED_GFX oled = OLED_GFX();

#ifdef __cplusplus
 extern "C" {
#endif

 void lcdTestPattern(void);
 void testlines(void);
 void testfastlines(void);
 void testdrawrects(void);
 void testfillrects(uint16_t color1, uint16_t color2);
 void testfillcircles(uint8_t radius, uint16_t color);
 void testdrawcircles(uint16_t color);
 void testroundrects(void);
 void testtriangles(void);

 int cnt = 0;

 void init()
 {
	 oled.Device_Init();
 }

 void runTest()
 {
	 char buf[20];

	 oled.setFont( &FreeMono12pt7b );
	 oled.setTextColor( RED );
	 oled.setCursor( 0, 50 );

	 //oled.setFont( &FreeSans18pt7b );
	 //oled.setFont( &FreeMonoBoldOblique24pt7b );
	 //oled.drawChar( 0, 50, 'A', GREEN, RED, 1 );
	 oled.write( '1' );
	 oled.write( '4' );
	 oled.write( '.' );
	 oled.write( '0' );
	 oled.write( '7' );
	 oled.write( '4' );
	 oled.write( '.' );
	 oled.write( '0' );
	 oled.write( '0' );
//	 oled.writeFillRect( 10, 10, 30, 30, RED);
/*
	 sprintf( buf, "%-3d", cnt++ );
	 oled.Set_Color(RED);
	 oled.print_String(0, 8, (const uint8_t *) buf, FONT_8X16);
 */
 }

 void runTest1()
 {
   oled.Device_Init();

   oled.Display_Interface();
   HAL_Delay(3000);
   oled.Clear_Screen();

   oled.Set_Color(RED);
   oled.print_String(0, 0, (const uint8_t *)"Hello World !", FONT_5X8);
   oled.Set_Color(BLUE);
   oled.print_String(0, 8, (const uint8_t *) "Hello WaveShare", FONT_8X16);
   HAL_Delay(2000);
   oled.Clear_Screen();

   oled.Set_Color(WHITE);
   oled.Draw_Pixel(50,50);
   HAL_Delay(1000);

   lcdTestPattern();
   HAL_Delay(1000);

   testlines();
   HAL_Delay(1000);

   testfastlines();
   HAL_Delay(1000);

   testdrawrects();
   HAL_Delay(1000);

   testfillrects(BLUE,YELLOW);
   HAL_Delay(1000);

   oled.Clear_Screen();
   testfillcircles(63, BLUE);
   HAL_Delay(500);
   testdrawcircles(WHITE);
   HAL_Delay(1000);

   testroundrects();
   HAL_Delay(1000);

   testtriangles();
   HAL_Delay(1000);

   oled.Display_bmp();
 }

 void testlines(void)  {

   oled.Set_Color(RED);
   oled.Clear_Screen();
   for (uint16_t x=0; x <= SSD1351_WIDTH - 1; x+=6)  {
     oled.Draw_Line(0, 0, x, SSD1351_HEIGHT - 1);
     HAL_Delay(20);
   }
   for (uint16_t y=0; y < SSD1351_HEIGHT - 1; y+=6)  {
     oled.Draw_Line(0, 0, SSD1351_WIDTH - 1, y);
     HAL_Delay(20);
   }

   oled.Set_Color(YELLOW);
   oled.Clear_Screen();
   for (uint16_t x=0; x < SSD1351_WIDTH - 1; x+=6) {
     oled.Draw_Line(SSD1351_WIDTH - 1, 0, x, SSD1351_HEIGHT - 1);
     HAL_Delay(20);
   }
   for (uint16_t y=0; y < SSD1351_HEIGHT - 1; y+=6) {
     oled.Draw_Line(SSD1351_WIDTH - 1, 0, 0, y);
     HAL_Delay(20);
   }

   oled.Set_Color(BLUE);
   oled.Clear_Screen();
   for (uint16_t x=0; x < SSD1351_WIDTH - 1; x+=6) {
     oled.Draw_Line(0, SSD1351_HEIGHT - 1, x, 0);
     HAL_Delay(20);
   }
   for (uint16_t y=0; y < SSD1351_HEIGHT - 1; y+=6) {
     oled.Draw_Line(0, SSD1351_HEIGHT - 1, SSD1351_WIDTH - 1, y);
     HAL_Delay(20);
   }

   oled.Set_Color(GREEN);
   oled.Clear_Screen();
   for (uint16_t x=0; x < SSD1351_WIDTH - 1; x+=6) {
   oled.Draw_Line(SSD1351_WIDTH - 1, SSD1351_HEIGHT - 1, x, 0 );
     HAL_Delay(20);
   }
   for (uint16_t y=0; y < SSD1351_HEIGHT - 1; y+=6) {
     oled.Draw_Line(SSD1351_WIDTH - 1, SSD1351_HEIGHT - 1, 0, y);
     HAL_Delay(20);
   }
 }

 void lcdTestPattern(void)
 {
   uint32_t i,j;
   oled.Set_Coordinate(0, 0);

   for(i=0;i<128;i++)  {
     for(j=0;j<128;j++)  {
       if(i<16)  {
         oled.Set_Color(RED);
         oled.Write_Data(color_byte, 2);
       }
       else if(i<32) {
         oled.Set_Color(YELLOW);
         oled.Write_Data(color_byte, 2);
       }
       else if(i<48) {
         oled.Set_Color(GREEN);
         oled.Write_Data(color_byte, 2);
       }
       else if(i<64) {
         oled.Set_Color(CYAN);
         oled.Write_Data(color_byte, 2);
       }
       else if(i<80) {
         oled.Set_Color(BLUE);
         oled.Write_Data(color_byte, 2);
       }
       else if(i<96) {
         oled.Set_Color(MAGENTA);
         oled.Write_Data(color_byte, 2);
       }
       else if(i<112)  {
         oled.Set_Color(BLACK);
         oled.Write_Data(color_byte, 2);
       }
       else {
         oled.Set_Color(WHITE);
         oled.Write_Data(color_byte, 2);
       }
     }
   }
 }

 void testfastlines(void) {

   oled.Set_Color(WHITE);
   oled.Clear_Screen();

   for (uint16_t y=0; y < SSD1351_WIDTH - 1; y+=5) {
     oled.Draw_FastHLine(0, y, SSD1351_WIDTH - 1);
     HAL_Delay(10);
   }
   for (uint16_t x=0; x < SSD1351_HEIGHT - 1; x+=5) {
     oled.Draw_FastVLine(x, 0, SSD1351_HEIGHT - 1);
     HAL_Delay(10);
   }
 }

 void testdrawrects(void)  {
   oled.Clear_Screen();
   for (uint16_t x=0; x < SSD1351_HEIGHT - 1; x+=6)  {
     oled.Draw_Rect((SSD1351_WIDTH-1)/2 - x/2, (SSD1351_HEIGHT-1)/2 - x/2 , x, x);
     HAL_Delay(10);
   }
 }

 void testfillrects(uint16_t color1, uint16_t color2)  {

   uint16_t x = SSD1351_HEIGHT - 1;
   oled.Clear_Screen();
   oled.Set_Color(color1);
   oled.Set_FillColor(color2);
   for(; x > 6; x-=6)  {
     oled.Fill_Rect((SSD1351_WIDTH-1)/2 - x/2, (SSD1351_HEIGHT-1)/2 - x/2 , x, x);
   oled.Draw_Rect((SSD1351_WIDTH-1)/2 - x/2, (SSD1351_HEIGHT-1)/2 - x/2 , x, x);
   }
 }

 void testfillcircles(uint8_t radius, uint16_t color)  {

   oled.Set_Color(color);

   oled.Fill_Circle(64, 64, radius);
   }


 void testdrawcircles(uint16_t color)  {

   uint8_t r = 0;
   oled.Set_Color(color);

   for (; r < SSD1351_WIDTH/2; r+=4)  {
     oled.Draw_Circle(64, 64, r);
     HAL_Delay(10);
   }
 }

 void testroundrects(void) {

   int color = 100;
   int x = 0, y = 0;
   int w = SSD1351_WIDTH - 1, h = SSD1351_HEIGHT - 1;

   oled.Clear_Screen();

   for(int i = 0 ; i <= 20; i++) {

     oled.Draw_RoundRect(x, y, w, h, 5);
     x += 2;
     y += 3;
     w -= 4;
     h -= 6;
     color += 1100;
     oled.Set_Color(color);
   }
 }

 void testtriangles(void)  {
   oled.Clear_Screen();
   int color = 0xF800;
   int t;
   int w = SSD1351_WIDTH/2;
   int x = SSD1351_HEIGHT-1;
   int y = 0;
   int z = SSD1351_WIDTH;
   for(t = 0 ; t <= 15; t+=1) {
     oled.Draw_Triangle(w, y, y, x, z, x);
     x-=4;
     y+=4;
     z-=4;
     color+=100;
     oled.Set_Color(color);
   }
 }

#ifdef __cplusplus
}
#endif


