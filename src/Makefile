CC=gcc -pedantic -Wall -Wextra --std=c99 -O2
OBJECTS=../obj/resource.o ../obj/huey32.o ../obj/color_conversions.o
FLAGS=

all:$(OBJECTS)
	$(CC) -o ../huey32.exe $(OBJECTS) -s -lcomctl32 -mwindows -lwinmm

../obj/resource.o:../res/resource.rc ../res/resource.h ../res/huey32.ico
	windres ../res/resource.rc -o ../obj/resource.o

../obj/huey32.o:huey32.c color_names.h font_names.h color_conversions.c 
	$(CC) -o ../obj/huey32.o -c huey32.c

../obj/color_conversions.o:color_conversions.h color_conversions.c
	$(CC) -o ../obj/color_conversions.o -c color_conversions.c

clean:
	rm ../obj/*.o
	rm ../*.exe

