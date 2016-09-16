#ifndef __UGUI_CONFIG_H
#define __UGUI_CONFIG_H

/* -------------------------------------------------------------------------------- */
/* -- CONFIG SECTION                                                             -- */
/* -------------------------------------------------------------------------------- */

//#define USE_MULTITASKING

/* Enable color mode */
#define USE_COLOR_RGB888   // RGB = 0xFF,0xFF,0xFF
//#define USE_COLOR_RGB565   // RGB = 0bRRRRRGGGGGGBBBBB

/* Enable needed fonts here */
//#define  USE_FONT_4X6
//#define  USE_FONT_5X8
//#define  USE_FONT_5X12
#define  USE_FONT_6X8
//#define  USE_FONT_6X10
//#define  USE_FONT_7X12
#define  USE_FONT_8X8
//#define  USE_FONT_8X12_CYRILLIC
//#define  USE_FONT_8X12
//#define  USE_FONT_8X12
//#define  USE_FONT_8X14
//#define  USE_FONT_10X16
//#define  USE_FONT_12X16
#define  USE_FONT_12X20
//#define  USE_FONT_16X26
//#define  USE_FONT_22X36
//#define  USE_FONT_24X40
//#define  USE_FONT_32X53
#define  USE_FONT_VECTOR_CYRILLIC

/* Specify platform-dependent integer types here */

#define __UG_FONT_DATA const

typedef unsigned char         UG_U8;
typedef char                  UG_S8;
typedef unsigned short        UG_U16;
typedef short                 UG_S16;
typedef unsigned int          UG_U32;
typedef int                   UG_S32;

typedef struct {
    UG_S16 x, y;
} UG_Point, *UG_PointPtr;


/* -------------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------------- */


/* Feature enablers */
#define USE_PRERENDER_EVENT
#define USE_POSTRENDER_EVENT

#define UG_MaxPolyPointNum 20

#endif
