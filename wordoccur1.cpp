#include <iostream>
#include <fstream>
#include <map>

void disp_map(const std::map <std::string, int> &);
std::string to_lowercase(const std::string &);
std::string remove_punct(const std::string &);

int main()
{
    std::ifstream file("words.txt");
    std::map <std::string, int> words_map;
    std::string word;
    int i = 0;
    if (!file)
    {
        std::cerr << "The file cannot be opened" << std::endl;
        return -1;
    }
    while (file >> word)
    {
        word =to_lowercase(word);
        word =remove_punct(word);
        if (word.empty())
        {
            std::cerr << "The word is empty" << std::endl;
        }
        else
        {
            words_map[word]++;
        }
    }
    file.close();
    disp_map(words_map);
    return 0;
}

void disp_map(const std::map <std::string, int> &words_map)
{
    for (const auto &[key, value] : words_map)
    {
        std::cout << key << "->" << value << std::endl;   
    }
}

std::string to_lowercase(const std::string &str1)
{
    std::string res;
    for (char c:str1)
    {
        res += std::tolower(c);
    }
    return res;
}

std::string remove_punct(const std::string &str1)
{
    std::string res;
    for (char c: str1)
    {
        if(std::isalpha(c))
        {
            res += c;
        }
    }
    return res;
}