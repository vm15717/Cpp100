# include <iostream>

int main()
{
    int w = 2;
    float z = 1.1;
    double z1 = 10.33242352;
    std::string s1 = "Hello mate!";
    std::cout << w << std::endl;
    std::cout << z << std::endl;
    printf("%lf\n", z1);
    // std::cout << z1 << std::endl;
    std::cout << s1 << std::endl;
    for (int i = 0; i < 64; i++)
    {
        std::cout << i << " ";
        printf("%d ", (int) pow(w, i));
        printf("%lf ", pow(z, i));
        std::cout << "\n";
    };
    return 0;
}