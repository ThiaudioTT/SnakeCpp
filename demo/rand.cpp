#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

int main()
{
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int random = 0 + (rand() % (788 - 0 + 1)); // geez, stack overflow, help me
        cout << random << endl;
    }

    return 0;
}