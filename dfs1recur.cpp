#include <iostream>

void dfsrecur(const std::vector <std::vector <int>> &, std::vector <bool> &, int);

int main()
{
    int V = 4;
    std::vector <std::vector <int>> mat1(V, std::vector <int>(V));
    mat1[0][1] = 1;
    mat1[1][0] = 1;
    mat1[0][2] = 1;
    mat1[2][0] = 1;
    mat1[1][3] = 1;
    mat1[3][1] = 1;
    mat1[2][3] = 1;
    mat1[3][2] = 1;
    std::vector <bool> vec(mat1.size(), false);
    int start = 0;
    dfsrecur(mat1, vec, start);
}

void dfsrecur(const std::vector <std::vector <int>> &mat1, std::vector <bool> &vec, int start)
{
    std::cout << "Visited node : "<< start << std::endl;
    vec[start] = true;
    for (int i = 0; i < mat1[start].size();i++)
    {
        if (!vec[i] && mat1[start][i] == 1)
        {
            dfsrecur(mat1, vec, i);
        }
    }
}