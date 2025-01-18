#include <iostream>

void disp_mat_graph(const std::vector <std::vector <int>> &);
void bfs(const std::vector <std::vector <int>> &, int);

int main()
{
    int V = 4;
    std::vector <std::vector <int>> mat1(V, std::vector <int> (V, 0));
   
    mat1[0][1] = 1;
    mat1[1][0] = 1;
    mat1[1][2] = 1;
    mat1[2][1] = 1;
    mat1[2][3] = 1;
    mat1[3][2] = 1;
    disp_mat_graph(mat1);
    bfs(mat1, 0);
    return 0;
}

void disp_mat_graph(const std::vector <std::vector <int>> &mat1)
{
    for (std::vector <int> c : mat1)
    {
        for (int j: c)
        {
            std::cout << j << "\t";
        }
        std::cout << "\n";
    }
}

void bfs(const std::vector <std::vector <int>> &mat1, int start)
{
    std::queue <int> queue1;
    std::vector <bool> vec(mat1.size(), false);
    vec[start] = true;
    queue1.push(start);
    while (!queue1.empty())
    {
        int node = queue1.front();
        queue1.pop();
        std::cout << "Node: "<< node << std::endl;
        for (int i = 0; i < mat1[node].size(); i++)
        {
            if (mat1[node][i] == 1 && vec[i] != true)
            {
                vec[i] = true;
                queue1.push(i);
            }
        }
    }
}