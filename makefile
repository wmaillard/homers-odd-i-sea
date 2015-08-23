CC=g++
CFLAGS=-c
LDFLAGS=
SOURCES=main.cpp Creature.cpp Cyclops.cpp Island.cpp Item.cpp Ithaca.cpp Landscape.cpp Phaecians.cpp Player.cpp Room.cpp Laest.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=game

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) *.o *~
