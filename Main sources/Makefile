CC = gcc
CFLAGS = -Wall
EXEC = test
HEADERS = $(wildcard *.h)
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) -o $@ $^ `sdl2-config --cflags --libs` `pkg-config --cflags --libs glib-2.0` `xml2-config --cflags` `xml2-config --libs` -lSDL2_gfx  -lSDL2_ttf -g -lm

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< `sdl2-config --cflags --libs` `pkg-config --cflags --libs glib-2.0` `xml2-config --cflags` `xml2-config --libs` -lSDL2_gfx -lSDL2_ttf -g -lm

clean:
	rm -f $(OBJECTS)

mrproper: clean
	rm -f $(EXEC)
