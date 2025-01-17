#include <iostream>
std::string remove_punct(const std::string &);
std::string string_reverse(const std::string &s);

int main()
{
    std::string s = "alpha, ahpla";
    std::string sr = remove_punct(s);
    std::string sres = string_reverse(sr);
    std::cout << sres << std::endl;
    if (sres == sr)
    {
        std::cout << "It's a palindrome!" << std::endl;
    }
    else
    {
        std::cout << "It's not a palindrome!" << std::endl;
    }
    return 0;
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

std::string string_reverse(const std::string &str)
{
    std::string res;
    for (size_t i = str.size(); i > 0; i--)
    {
            res += str[i-1];
    }
    return res;
}