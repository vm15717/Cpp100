#include <iostream>
#include <fstream>

void disp_mat(std::vector<std::vector <int>> &);
void transpose(std::vector<std::vector <int>> &, std::vector<std::vector <int>> & );

int main()
{
    std::vector<std::vector <int>> matrix(2, std::vector<int>(2));
    std::ifstream file("vec2.txt");
    int v;
    int i = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            file >> v;
            matrix[i][j] = v;
        }
    }
    file.close();
    std::cout << "The original matrix is: "<< std::endl;
    disp_mat(matrix);
    std::vector<std::vector <int>> matrix2(2, std::vector<int>(2));
    transpose(matrix, matrix2);
    std::cout << "The transformed matrix is: "<<std::endl;
    disp_mat(matrix2);
}

void disp_mat(std::vector<std::vector <int>> &mat)
{
    for (std::vector <int> i: mat)
    {
        for (int j: i)
        {
            std::cout << j << "\t";
        }
        std::cout << "\n";
    }
}

void transpose(std::vector<std::vector <int>> &mat1, std::vector<std::vector <int>> &mat2)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            mat2[i][j] = mat1[j][i];
        }
    }
}