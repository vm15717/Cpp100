#include <iostream>
#include <map>

void rev_map(std::map <int, std::string> &, std::map <std::string, int> &);
void disp_map(const std::map <int, std::string> &);
void disp_rev_map(const std::map <std::string, int> &);

int main()
{
    std::map <int, std::string> map1;
    map1[0] = "Hello";
    map1[1] = "Worlds";
    map1[2] = "!!!!";
    map1[3] = "Worlds";
    map1[4] = "!!!!";
    disp_map(map1);
    std::map <std::string, int> map2;
    rev_map(map1, map2);
    disp_rev_map(map2);
}

void rev_map(std::map <int, std::string> &map1, std::map <std::string, int> &map2)
{
    for (const auto &[key, value] : map1)
    {
        if (map2[value])
        {
            std::cout << "Key already exists!" << std::endl;
        }
        else
        {
            map2[value] = key;
        }
    }   
}

void disp_map(const std::map <int, std::string> &map1)
{
    for (const auto &[key, value]: map1)
    {
        std::cout << key << "->" << value << std::endl;
    }
}
void disp_rev_map(const std::map <std::string, int> &map1)
{
    for (const auto &[key, value]: map1)
    {
        std::cout << key << "->" << value << std::endl;
    }
}