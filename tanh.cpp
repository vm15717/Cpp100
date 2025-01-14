#include <iostream>
#include <cmath>

int main()
{
    float x, y;
    FILE *FP;
    FP = fopen("vals.txt", "w");
    while (x++ < 3.0)
    {
        fprintf(FP, "%f\n", tanh(x));
    }
    fclose(FP);
    return 0;
}