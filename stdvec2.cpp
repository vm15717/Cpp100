#include <iostream>
#include <fstream>

bool comp(int, int);
void disp_vec(std::vector <int> &);

int main()
{
    std::vector <int> vec;
    std::fstream file("vec1.txt");
    int v;
    while (file >> v)
    {
        vec.push_back(v);
    }
    file.close();
    std::cout << "The 10 elements are" << std::endl;
    disp_vec(vec);
    std::sort(vec.begin(), vec.end(), comp);
    std::cout << "The sorted elements are" << std::endl;
    disp_vec(vec);
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    std::cout << "After removing duplicates we have" << std::endl;
    disp_vec(vec);
}

bool comp(int a, int b)
{
    return a > b;
}

void disp_vec(std::vector <int> &vec)
{
    for(int v: vec)
    {
        std::cout << v << "\t";
    }
    std::cout << "\n";
}