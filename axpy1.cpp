#include <iostream>

int main()
{
    int A[2][2] = {{1, 2}, {3, 4}};
    int y[2] = {1, -2};
    int *B = new int[2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            B[i] = B[i] + A[i][j]*y[j];
        }
    }
    for (int i = 0; i < 2; i ++ )
    {
        std::cout << B[i] << std::endl;
    }
    return 0;
}