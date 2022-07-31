#include <iostream>

using namespace std;

int main()
{
    int a[10][10];
    cout << a[0][0];
    cout << "a00: " << a[0][0] << endl;
    a[0][0] = 2;
    cout << "a00: " << a[0][0] << endl;
}