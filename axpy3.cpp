#include <iostream>
#include <fstream>

void read_matrix(std::ifstream &f, double **, int, int );
void display_matrix(double **, int, int );
void matmul(double **, double **, int **, double **);

int main()
{
    std::ifstream file("mats.txt");
    int rows, cols;
    double **matrices[2];
    int **dims = new int*[2];
    for (int k =0; k < 2; k++)
    {
        dims[k] = new int[2];
    }
     for (int i = 0; i < 2; i++)
    {
        file >> rows >> cols;
        dims[i][0] = rows;
        dims[i][1] = cols;

        matrices[i] = new double*[rows];
        for (int r = 0; r < rows; r++)
        {
            matrices[i][r] = new double[cols];
        }

        read_matrix(file, matrices[i], rows, cols);
        std::cout << "Matrix " << i+1 << ": " << std::endl;
        display_matrix(matrices[i], rows, cols);
    }
    if (dims[0][1] != dims[1][0])
    {
        std::cerr << "Error, the dimensions do not match" << std::endl;
        return -1;
    }
    double **mat_res = new double*[dims[0][0]];
    for (int m = 0; m < dims[0][0]; m++)
        {
            mat_res[m] = new double[dims[1][1]];
        }
    matmul(matrices[0], matrices[1], dims, mat_res);
    std::cout << "The result of the matrix multiplication is : "<< std::endl;
    display_matrix(mat_res, dims[0][0], dims[1][1]);
    for (int i = 0; i < 2; i++)
    {
        for (int r = 0; r < dims[i][0]; r++)
        {
            delete[] matrices[i][r];
        }
        delete[] matrices[i];
    }

    for (int r = 0; r < dims[0][0]; r++)
    {
        delete[] mat_res[r];
    }
    delete[] mat_res;
    return 0;
}

void display_matrix(double **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void read_matrix(std::ifstream &file, double **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            file >> matrix[i][j];
        }
    }
}

void matmul(double **matrix1, double **matrix2, int **dims, double **mat_res)
{ 
        for (int i = 0;i < dims[0][0]; i++)
        {
            for (int j = 0; j < dims[1][0]; j++)
            {
                for (int k = 0; k < dims[1][1]; k++)
                {
                    mat_res[i][k] += matrix1[i][j] * matrix2[j][k];
                }
            }
        }
}

