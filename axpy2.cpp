#include <iostream>
#include <fstream>

void read_matrix(int **, std::ifstream &);
void print_matrix(int **);
void mat_mul(int **, int **, int **);

int main()
{
    int **mat1 = new int*[2];
    for (int i = 0; i < 2; i++)
    {
        mat1[i] = new int[2];
    }
    int **mat2 = new int*[2];
    for (int i = 0; i < 2; i++)
    {
        mat2[i] = new int[2];
    }
    int **mat3 = new int*[2];
    for (int i = 0; i < 2; i++)
    {
        mat3[i] = new int[2];
    }
    std::ifstream file1("mat1.txt");
    std::ifstream file2("mat2.txt");
    if (!file1)
    {
        std::cerr << "Error in the file with matrix 1" << std::endl;
        return 1;
    }
    if (!file2)
    {
        std::cerr << "Error in the file with matrix 2" << std::endl;
        return 1;
    }
    read_matrix(mat1, file1);
    read_matrix(mat2, file2);
    file1.close();
    file2.close();
    std::cout << "Matrix 1:" << std::endl;
    print_matrix(mat1);
    std::cout << "Matrix 2:" << std::endl;
    print_matrix(mat2);
    mat_mul(mat1, mat2, mat3);
    std::cout << "Matrix 1 x Matrix 2 =" << std::endl;
    print_matrix(mat3);
    mat_mul(mat2, mat1, mat3);
    std::cout << "Matrix 2 x Matrix 1=" << std::endl;
    print_matrix(mat3);
    for (int i = 0; i < 2; ++i) {
        delete[] mat1[i];  // Free each row
    }
    delete[] mat1;
    for (int i = 0; i < 2; ++i) {
        delete[] mat2[i];  // Free each row
    }
    delete[] mat2;
    for (int i = 0; i < 2; ++i) {
        delete[] mat3[i];  // Free each row
    }
    delete[] mat3;
    return 0;
}

void read_matrix(int **matrix, std::ifstream &file1)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            file1 >> matrix[i][j];
        }
    }
}

void print_matrix(int **matrix)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void mat_mul(int **matrix1, int **matrix2, int **matrix3)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}