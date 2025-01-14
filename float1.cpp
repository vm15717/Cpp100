#include <iostream>
#include "/Users/vrm18/Documents/Programming/CP/Cpp100/add1.cpp"

float z;

int main()
{
    float x;
    extern float z;
    int i;
    x = 0.0;
    for (int i = 0; i < 3; i++)
    {
        add(x);
        std::cout << x << " " << z << std::endl;
    };
    return 0;
}
