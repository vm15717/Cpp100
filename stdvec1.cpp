#include <iostream>

int main()
{
    std::vector <int> vec(5, 42);
    int j = 0;
    // printing elements
    for (int v: vec)
    {
        std::cout << v << std::endl;
    }
    // adding an element
    vec.push_back(43);
    vec.emplace_back(44);
    vec.pop_back();
    vec.insert(vec.begin() + 2, 1);
    vec.erase(vec.begin()+2);
    for (int v: vec)
    {
        std::cout << v << std::endl;
    }
    return 0;
}