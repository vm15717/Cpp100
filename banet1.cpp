#include <iostream>
#include <map>
#include <random>

void disp_graph(std::vector <std::vector <int>> &);
void banet1(std::vector <std::vector <int>> &, int, int);
int sum1(std::vector <int> &);
void degree1(std::vector <std::vector <int>> &, std::map <int, int> &);
void rand_ind(std::map <int, int> &, int, std::vector <int> &);

int main()
{
    int V = 4;
    std::vector <std::vector <int>> mat1(V, std::vector <int>(V, 0));
    mat1[0][1] = 1;
    mat1[1][0] = 1;
    mat1[0][2] = 1;
    mat1[2][0] = 1;
    mat1[1][3] = 1;
    mat1[3][1] = 1;
    mat1[2][3] = 1;
    mat1[3][2] = 1;
    std::cout << "Old graph is :" << std::endl;
    disp_graph(mat1);
    int n = 2;
    int time = 3;
    banet1(mat1, n, time);
    std::cout << "New graph is :" << std::endl;
    disp_graph(mat1);
    return 0;
}

void disp_graph(std::vector <std::vector <int>> &mat1)
{
    for (std::vector <int> j: mat1)
    {
        for (int i : j)
        {
            std::cout << i << "\t";
        }
        std::cout << "\n";
    }
}

void banet1(std::vector <std::vector <int>> &mat1, int num, int time)
{
    for (int i = 0; i < time; i++)
    {
        std::map <int, int> deg_vec;
        degree1(mat1, deg_vec);
        std::vector <int> indices (num);
        rand_ind(deg_vec, num, indices);
        std::vector <int> zeros(mat1[0].size(), 0);
        for (int j = 0; j < num; j++)
        {
            mat1.push_back(zeros);
        }
        for (int m = 0; m < mat1.size(); m++)
        {
            mat1[m].push_back(0);
        }
        for (int k = 0; k < num; k++)
        {
            mat1[mat1.size()-num+k][indices[k]] = 1;
            mat1[indices[k]][mat1.size()-num+k] = 1;
        }
    }
}

void degree1(std::vector <std::vector <int>> &mat1, std::map <int, int> &deg_vec)
{
    for (int i = 0; i < mat1.size(); i++)
    {
        deg_vec.insert({i, sum1(mat1[i])});
    }
}

int sum1(std::vector <int> &vec1)
{
    int sum = 0;
    for (int j:vec1)
    {
        sum+=j;
    }
    return sum;
}

void rand_ind(std::map <int, int> &deg_vec, int num, std::vector <int> &vec1)
{
    std::vector<int> weighted_nodes;
    for (const auto& entry : deg_vec)
    {
        int degree = entry.second;
        for (int i = 0; i < degree; ++i)
        {
            weighted_nodes.push_back(entry.first);  
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, weighted_nodes.size() - 1);

    for (int i = 0; i < num; i++)
    {
        int rand_index = dis(gen);
        vec1[i] = weighted_nodes[rand_index];  
    }
}