#include <iostream>

class student{
    public:
        int id;
        std::string name;
        void insert(int i, std::string n)
        {
            id = i;
            name = n;
        }
        void display()
        {
            std::cout << id << std::endl;
            std::cout << name << std::endl;
        }
};

int main()
{
    student s1, s2;
    s1.insert(18, "Virat Kohli");
    s2.insert(10, "Sachin Tendulkar");
    s1.display();
    s2.display();
    return 0;
}