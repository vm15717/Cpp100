#include <iostream>

class box
{
    public:
        double length;
        double breadth;
        double height;
        double volume()
        {
            return length * breadth * height;
        }
};


int main()
{
    box b1, b2;
    b1.length = 3;
    b1.breadth = 2;
    b1.height = 5;
    std::cout << b1.volume() << std::endl;
    return 0;
}