#include <iostream>

int main()
{
    int *i = new int;

    std::cout << *i << std::endl;

    delete i;
    return 0;
}