CC=gcc
CFLAGS=-g -std=c99 `sdl2-config --libs --cflags`

all:
	${CC} ${CFLAGS} -o ugui_sim sdl.c ../ugui.c -I../ phone.c
