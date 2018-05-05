#include "lcd.h"
#include "ugui.h"


/*********************************************************************
*
*       Public code,
*
*       LCD_FIXEDPALETTE == 565, 65536 colors, RRRRRGGGGGGBBBBB
*
**********************************************************************
*/

#define B_BITS 5
#define G_BITS 6
#define R_BITS 5

#define R_MASK ((1 << R_BITS) -1)
#define G_MASK ((1 << G_BITS) -1)
#define B_MASK ((1 << B_BITS) -1)

/*********************************************************************
*
*       Public code,
*
*       LCD_FIXEDPALETTE == 565, 65536 colors, BBBBBGGGGGGRRRRR
*
**********************************************************************
*/
/*********************************************************************
*
*       LCD_Color2Index_565
*/
unsigned LCD_Color2Index_565(UG_COLOR Color) {
  int r,g,b;
  r = (Color>> (8  - R_BITS)) & R_MASK;
  g = (Color>> (16 - G_BITS)) & G_MASK;
  b = (Color>> (24 - B_BITS)) & B_MASK;
  return r + (g << R_BITS) + (b << (G_BITS + R_BITS));
}

/* Hardware accelerator for UG_DrawLine (Platform: STM32F4x9) */
UG_RESULT _HW_DrawLine( UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR c )
{
	LCD_DrawLine(x1,y1,x2,y2,c);//LCD_Color2Index_565(c)
   return UG_RESULT_OK;
}

/* Hardware accelerator for UG_FillFrame (Platform: STM32F4x9) */
UG_RESULT _HW_FillFrame( UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR c )
{
	LCD_Fill(x1,y1,x2,y2,c);
   return UG_RESULT_OK;
}

void _HW_DrawPoint(UG_S16 x, UG_S16 y, UG_COLOR c)
{
	LCD_DrawPoint(x,y,c);
}
