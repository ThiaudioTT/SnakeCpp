LIBS=-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

all: snakeGame

snake.o: ./src/snake.cpp
	g++ -c ./src/snake.cpp -o ./bin/snake.o

fruit.o: ./src/fruit.cpp
	g++ -c ./src/fruit.cpp -o ./bin/fruit.o

main.o: ./src/main.cpp
	g++ -c ./src/main.cpp -o ./bin/main.o

snakeGame: main.o snake.o fruit.o
	@echo "Building..."
	g++ -o SnakeGame.o ./bin/snake.o ./bin/fruit.o ./bin/main.o $(LIBS)
