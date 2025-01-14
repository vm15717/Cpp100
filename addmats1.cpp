#include <iostream>
#include <fstream>

void read_matrix(std::ifstream &, double **, int, int);
void display_matrix(double **, int, int);
void addmats(double **, double **, double **, int **);
int main()
{
    std::ifstream file("mats2.txt");
    int rows, cols;
    double **matrices[2];
    int **dims = new int*[2];
    for (int i = 0; i < 2; i++)
    {
        dims[i] = new int[2];
    }
    for (int i = 0; i < 2; i++)
    {
        file >> rows >> cols;
        matrices[i] = new double*[rows];
        for (int r = 0; r < rows; r++)
        {
            matrices[i][r] = new double [cols];
        }
        read_matrix(file, matrices[i], rows, cols);
        dims[i][0] = rows;
        dims[i][1] = cols;
        display_matrix(matrices[i], rows, cols);
    }
    if ((dims[0][0] != dims[1][0]) || dims[0][1] != dims[1][1])
    {
        std::cerr << "The dimensions dont match" << std::endl;
        return -1;
    }
    double **mat_res = new double*[dims[0][0]];
    for (int i = 0; i < dims[0][0]; i++)
    {
        mat_res[i] = new double[dims[1][1]];
    }
    addmats(mat_res, matrices[0], matrices[1], dims);
    std::cout << "The two matrices add to give: " << std::endl;
    display_matrix(mat_res, dims[0][0], dims[1][1]);
    for (int i = 0; i < 2; i++)
    {
        for (int r = 0; r < dims[0][0]; r++)
        {
            delete []matrices[i][r];
        }
        delete matrices[i];
    }
    for (int r = 0; r < dims[0][0]; r++)
    {
        delete[] mat_res[r];
    }
    delete[] mat_res;
    file.close();
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

void addmats(double **mat_res, double **mat1, double **mat2, int **dims)
{
    for (int i = 0; i < dims[0][0]; i++)
    {
        for (int j = 0; j < dims[1][1]; j++)
        {
            mat_res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}