OBJ = main.o Graphics.o Game.o BasicHandler.o StateManager.o AssetManager.o ConfigManager.o
CFLAGS = -Wall -I"/usr/local/include" 
SFML_LINK_FLAGS = -I"/usr/local/lib" -lsfml-graphics -lsfml-window -lsfml-system

all: bin

bin: $(OBJ)
	g++ $(CFLAGS) $(OBJ) -o bin $(SFML_LINK_FLAGS)

%.o : %.c
	g++ $(CFLAGS) -c $<

clean:
	rm bin $(OBJ)
