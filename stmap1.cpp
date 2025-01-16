#include <iostream>
#include <map>

void disp_map(std::map <int, std::string> &);

int main()
{
    std::map<int, std::string> map1;
    map1.insert({0, "Apple"});
    map1.insert({1, "Orange"});
    map1.insert({2, "Berry"});
    disp_map(map1);
    map1[2] = "strawberry";
    disp_map(map1);
    if (map1.count(4))
    {
        std::cout << "Key 4 exists" << std::endl;
    }
    else
    {
        std::cout << "Key 4 doesnt exist" << std::endl;
    }
}

void disp_map(std::map <int, std::string> &map1)
{
    for (const auto &[key, value]: map1)
    {
        std::cout << key << "->" << value << std::endl;
    }
}