#include <iostream>
void peek(const std::vector <int> &);
size_t size(const std::vector <int> &);
void push(std::vector <int> &, int );
void pop(std::vector <int> &);
void display(const std::vector <int> &);

int main()
{
    std::vector <int> vec;
    push(vec, 20);
    push(vec, 5);
    push(vec, 10);
    display(vec);
    pop(vec);
    pop(vec);
    display(vec);
    push(vec, 15);
    peek(vec);
    display(vec);
    size_t size1 = size(vec);
    std::cout << size1 << std::endl;
    return 0;
}

void peek(const std::vector <int> &vec)
{
    if (!vec.empty())
    {
        std::cout << vec.back() << std::endl;
    }
    else
    {
        std::cout << "Stack is empty" << std::endl;    
    }
}

void push(std::vector <int> &vec, int val)
{
    vec.push_back(val);
}

void pop(std::vector <int> &vec)
{
    if (!vec.empty())
    {
        std::cout << "Popped " << vec.back() << " from the stack" << std::endl;
        vec.pop_back();
    }
    else
    {
        std::cout << "Stack is Empty, cannot pop " << std::endl; 
    }
    
}

void display(const std::vector <int> &vec)
{
    if (!vec.empty())
    {
       for (int i: vec)
       {
        std::cout << i << "\t";
       }
       std::cout << "\n";
    }
    else
    {
        std::cout << "Stack is empty" << std::endl; 
    }
}

size_t size(const std::vector <int> &vec)
{
    return vec.size();
}