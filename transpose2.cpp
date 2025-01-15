#include <iostream>
#include <fstream>

void read_matrix(std::ifstream &, std::vector<std::vector <int>> &);
void disp_matrix(std::vector<std::vector <int>> &);
void transpose(std::vector<std::vector <int>> &, std::vector<std::vector <int>> &);

int main()
{
    std::ifstream file("vec3.txt");
    int rows;
    int cols;
    file >> rows >> cols;
    std::vector<std::vector <int>> matrix(rows, std::vector <int> (cols));
    read_matrix(file, matrix);
    file.close();
    std::cout << "The original matrix is :" << std::endl;
    disp_matrix(matrix);
    std::vector<std::vector <int>> mat2(cols, std::vector <int> (rows)); 
    transpose(matrix, mat2);
    std::cout << "The transposed matrix is :" << std::endl;
    disp_matrix(mat2);
}


void disp_matrix(std::vector <std::vector <int>> &mat)
{
    for (std::vector <int> i : mat)
    {
        for (int j : i)
        {
            std::cout << j << "\t";
        }
        std::cout << "\n";
    }
}

void read_matrix(std::ifstream &file, std::vector<std::vector <int>> &mat1)
{
   for (int i = 0; i < mat1.size(); i++)
    {
        for (int j = 0; j < mat1[i].size(); j++)
        {
            file >> mat1[i][j];
        }
    }
}

void transpose(std::vector<std::vector <int>> &mat1, std::vector<std::vector <int>> &mat2)
{
    for (int i = 0; i < mat2.size(); i++)
    {
        for (int j = 0; j < mat2[i].size(); j++)
        {
            mat2[i][j] = mat1[j][i];
        }
    }
}