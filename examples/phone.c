#include "ugui.h"
#define D_FONT FONT_10X16
#define MAX_OBJECTS 100


UG_WINDOW window1;
UG_TEXTBOX textbox1;
UG_BUTTON numpad[12];
static char *glyphs[12] = {"1", "2", "3",
													 "4", "5", "6",
													 "7", "8", "9",
													 "X", "0", "C"};
UG_OBJECT objs[MAX_OBJECTS];
static char number[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
int np;

void window1_callback(UG_MESSAGE *msg){
	if (msg->type == MSG_TYPE_OBJECT){
		if(msg->id == OBJ_TYPE_BUTTON){
			if (msg->event == OBJ_EVENT_PRESSED || msg->event == OBJ_EVENT_CLICKED){
				if ((msg->sub_id >= 0 && msg->sub_id <= 8) || msg->sub_id == 10){
					if (np < sizeof(number)-1){
						number[np++] = glyphs[msg->sub_id][0];
						UG_TextboxSetText(&window1, TXB_ID_0, number);
					}
				}
				else {
					if (msg->sub_id == 11)
						UG_TextboxSetText(&window1, TXB_ID_0, "Calling..");
					else if (msg->sub_id == 9){
						number[--np] = 0x00;
						UG_TextboxSetText(&window1, TXB_ID_0, number);
					}
				}
			}
		}
	}
}

void ui_setup(){

	UG_FontSelect(&D_FONT);
	UG_WindowCreate(&window1, objs, MAX_OBJECTS, window1_callback);

	UG_WindowSetTitleText(&window1, "Caller UI");
	UG_WindowSetTitleTextFont(&window1, &D_FONT);

	UG_TextboxCreate(&window1, &textbox1, TXB_ID_0, 10, 10, 230, 34);
	UG_TextboxSetFont(&window1, TXB_ID_0, &D_FONT);
	UG_TextboxSetText(&window1, TXB_ID_0, "enter number");
	UG_TextboxSetForeColor(&window1, TXB_ID_0, C_BLACK);

	for (int y = 0; y < 4; y++){
		for (int x = 0; x < 3; x++){
			int i = y*3 + x;
#define BTN_SIZE 55
			UG_ButtonCreate(&window1, &numpad[i], BTN_ID_0+i, 40+((x)*BTN_SIZE), 20+30+((y)*BTN_SIZE), 85+((x)*BTN_SIZE), 50+30+15+((y)*BTN_SIZE)); 
			UG_ButtonSetStyle(&window1, BTN_ID_0+i, BTN_STYLE_2D);
			UG_ButtonSetFont(&window1, BTN_ID_0+i, &D_FONT);
			UG_ButtonSetText(&window1, BTN_ID_0+i, glyphs[i]);
			UG_ButtonSetBackColor(&window1, BTN_ID_0+i, C_BLACK);
			UG_ButtonSetForeColor(&window1, BTN_ID_0+i, C_WHITE);
		}
	}

	UG_WindowShow(&window1);
}

void ui_loop(){

}
