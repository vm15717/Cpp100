#include <iostream>

class vector{
    private:
        int *A;
        size_t n;
    public:
        vector (size_t n) : n(n)
        {
            A = new int[n];
        }

        ~vector() {
            delete[] A;
        }
        void setelement(size_t index, int element)
        {
            A[index] = element;
        }
        void display()
        {
            for (int i = 0; i < n; i++)
            {
                std::cout << A[i] << "\t";   
            }
            std::cout << "\n";
        }
};

int main()
{
    vector v(2);
    v.setelement(0, 2);
    v.setelement(1, 2);
    v.display();
    return 0;
};