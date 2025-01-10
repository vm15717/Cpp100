#include <iostream>

class Student{
    public:
        int id;
        std::string name;
};

int main()
{
    Student s1;
    s1.id = 18;
    s1.name = "Virat Kohli";
    std::cout << s1.name << std::endl;
    std::cout << s1.id << std::endl;
    return 0;
}