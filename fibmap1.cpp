#include <iostream>
#include <map>

std::map <int, int> map1;
int fib(int, std::map <int, int> &);

int main()
{
    //extern std::map <int, int> map1;
    map1[0] = 0;
    map1[1] = 1;
    int i = 20;
    int w = fib(i, map1);
    std::cout << w << std::endl;
}

int fib(int i, std::map <int, int> &map1)
{
    if (map1.find(i) != map1.end())
    {
        return map1[i];
    }
    map1[i] = fib(i-1, map1)+fib(i-2, map1);
    return map1[i];
}