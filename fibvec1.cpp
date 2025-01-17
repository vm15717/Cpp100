#include <iostream>

int fib(int, std::vector <int> &);

int main()
{
    int i = 10;
    std::vector <int> vec1(11, -1);
    vec1[0] = 0;
    vec1[1] = 1;
    int w = fib(i, vec1);
    std::cout << w << std::endl;
    return 0;
}

int fib(int i, std::vector <int> &vec1)
{
    if (vec1[i] != -1)
    {
        return vec1[i];
    }
    vec1[i] = fib(i-1, vec1) + fib(i-2, vec1);
    return vec1[i];
}