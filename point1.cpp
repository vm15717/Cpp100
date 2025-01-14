#include <iostream>

int main()
{
    int n = 6;
    int *n1;
    n1 = &n;
    int **n2;
    n2 = &n1;
    **n2 = 10;
    std::cout << n << std::endl;
    std::cout << *n1 << std::endl;
    std::cout << **n2 << std::endl;
    return 0;
}