#include <iostream>

int main()
{
    char **marker;
    char *course[] = {"numerical", "methods"};
    marker = &course[0];
    for (int i = 0; i < 5; i++)
    {
        std::cout << *(*(marker))++  << std::endl;
    }
    return 0;
}