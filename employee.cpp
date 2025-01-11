#include <iostream>

class employee{
    public:
        int id;
        std::string name;
        float salary;
        void insert(int id1, std::string name1, float salary1)
        {
            id = id1;
            name = name1;
            salary = salary1;
        }
        void display()
        {
            std::cout << id << std::endl;
            std::cout << name << std::endl;
            std::cout << salary << std::endl;
        }
};


int main()
{
    employee e1, e2;
    e1.insert(1, "Javed", 1350.5);
    e2.insert(2, "Akhthar", 234.45);
    e1.display();
    e2.display();
    return 0;
}