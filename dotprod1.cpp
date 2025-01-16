#include <iostream>
#include <fstream>

void disp_vec(const std::vector <int> &);
int dotp(const std::vector <int> &, const std::vector <int> &);

int main()
{
    size_t length;
    std::vector <std::vector <int>> vecs;
    std::ifstream file("vecs.txt");
    if (!file) {
        std::cerr << "Error: Could not open file!" << std::endl;
        return -1;
    }
    for (int i = 0; i < 2; i++)
    {
        file >> length;
        std::vector <int> vec1(length);
        for (int i = 0; i < length; i++)
        {
            file >> vec1[i];
        }
        vecs.push_back(vec1);
    }
    std::cout << "The first vector is" << std::endl;
    disp_vec(vecs[0]);
    std::cout << "The second vector is " << std::endl;
    disp_vec(vecs[1]);
    if (vecs[0].size() != vecs[1].size())
    {
        std::cout << "The lengths of the vectors dont match!!" << std::endl;
        return -1;
    }
    int res;
    res = dotp(vecs[0], vecs[1]);
    std::cout << "Their dot product is "<< res << std::endl;
    return 0;
}


void disp_vec(const std::vector <int> &vec)
{
    for (int i:vec)
    {
        std::cout << i << "\t";
    }
    std::cout << "\n";
}

int dotp(const std::vector <int> &vec1, const std::vector <int> &vec2)
{
    int res = 0;
    for (size_t i = 0; i < vec1.size(); i++)
    {
        res += vec1[i]*vec2[i];
    }
    return res;
}