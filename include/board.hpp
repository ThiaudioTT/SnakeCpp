// TODO?
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

#define HEIGHT 50
#define WIDTH 66
#define CELLWIDTH 12

sf::Vector2f board[HEIGHT][WIDTH];

void fillBoard() // int w, int h
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            board[i][j] = sf::Vector2f(x, y);
            x += 12;
        }
        x = 0;
        y += 12;
    }
}
