#include <iostream>

void dfs(std::vector <std::vector <int>> &mat1, int);
int main()
{
    int V = 4;
    std::vector <std::vector <int>> mat1(4, std::vector <int>(4, 0));
    mat1[0][1] = 1;
    mat1[1][0] = 1;
    mat1[0][2] = 1;
    mat1[2][0] = 1;
    mat1[1][2] = 1;
    mat1[2][1] = 1;
    mat1[2][3] = 1;
    mat1[3][2] = 1;
    dfs(mat1, 0);
}

void dfs(std::vector <std::vector <int>> &mat1, int start)
{
    std::vector<bool> vec(mat1.size(), false);
    std::stack<int> stack1;
    stack1.push(start);
    vec[start] = true;
    while (!stack1.empty())
    {
        int node = stack1.top();
        std::cout << "Visited Node: " << node << std::endl;
        stack1.pop();
        for (int i = mat1[node].size() - 1; i >= 0; i--)
        {
            if (!vec[i] && mat1[node][i] == 1)
            {
                stack1.push(i);
                vec[i] = true;
            }
        }
    }
}