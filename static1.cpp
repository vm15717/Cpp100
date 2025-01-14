#include <iostream>
int add(int );
int z = 2;

int main()
{
    int a = 0;
    int b;
    for (int i = 0; i < 3; i++)
    {
        b = add(a);
        std::cout << b << "\t"<< a << std::endl;
    }
}


int add(int a)
{
    extern int z;
    int c = 0;
    c = c + 1 + z;
    a = a + c;
    return a;
}