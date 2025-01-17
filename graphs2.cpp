#include <iostream>

void disp_mat_graph(std::vector <std::vector <int>> &);

int main()
{
    int V = 5;
    std::vector <std::vector <int>> mat1(V, std::vector <int> (5, 0));
    mat1[0][1] = 1;
    mat1[1][0] = 1;
    mat1[1][2] = 1;
    mat1[2][1] = 1;
    mat1[2][3] = 1;
    mat1[3][2] = 1;
    disp_mat_graph(mat1);
    return 0;
}

void disp_mat_graph(std::vector <std::vector <int>> &mat1)
{
    for (std::vector <int> c : mat1)
    {
        for (int j: c)
        {
            std::cout << j << "\t";
        }
        std::cout << "\n";
    }
}