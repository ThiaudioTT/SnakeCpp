LIBS=-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

all: snakeGame

snake.o: ./src/snake.cpp
	g++ -c ./src/snake.cpp -o ./bin/snake.o

fruit.o: ./src/fruit.cpp
	g++ -c ./src/fruit.cpp -o ./bin/fruit.o

sound.o:
	g++ -c ./src/sound.cpp -o ./bin/sound.o

main.o: ./src/main.cpp
	g++ -c ./src/main.cpp -o ./bin/main.o

snakeGame: main.o snake.o fruit.o sound.o
	@echo "Building..."
	g++ -o SnakeGame ./bin/snake.o ./bin/fruit.o ./bin/sound.o ./bin/main.o $(LIBS)


# FOR WINDOWS
# do not forget to put the dlls in your folder.
# NOT TESTED YET
windows: mainW.o snakeW.o fruitW.o
	@echo "Building for your Windows..."
	g++ -o SnakeGame.exe ./bin/snakeW.o ./bin/fruitW.o ./bin/soundW.o ./bin/mainW.o -L ./include/lib $(LIBS)

mainW.o: ./src/main.cpp
	g++ -c ./src/main.cpp -o ./bin/mainW.o -I ./include/

snakeW.o: ./src/snake.cpp
	g++ -c ./src/snake.cpp -o ./bin/snakeW.o -I ./include/

fruitW.o: ./src/fruit.cpp
	g++ -c ./src/fruit.cpp -o ./bin/fruitW.o -I ./include/	

soundW.o: ./src/sound.cpp
	g++ -c ./src/fruit.cpp -o ./bin/soundW.o -I ./include/