#include<deque>
#include <iostream>

int main()
{
    std::deque<int> n = {1,2,3};

    n.push_back(4);

    std::cout << "NUMBER "<< n[3];

}