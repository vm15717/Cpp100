#include <iostream>
int fib(int );

int main ()
{
    int n = 20;
    int w = fib(n);
    std::cout << w << std::endl;
}

int fib(int n)
{
    if (n==0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fib(n-1)+fib(n-2);
    }
}