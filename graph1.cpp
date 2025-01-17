#include <iostream>

void disp_graph(const std::vector <std::vector <int>> &);

int main()
{
    int V = 5;
    std::vector <std::vector <int>> adjlist(V); 
    adjlist[0].push_back(1);
    adjlist[1].push_back(0);
    adjlist[1].push_back(2);
    adjlist[2].push_back(1);
    adjlist[2].push_back(3);
    adjlist[3].push_back(2);
    disp_graph(adjlist);
}

void disp_graph(const std::vector <std::vector <int>> &adjlist)
{
    for (int i = 0; i < adjlist.size(); i++)
    {
        std::cout << "Vertex " << i << std::endl;
        for (int neighbour : adjlist[i])
        {
            std::cout << "Neigbour " << neighbour << std::endl;
        }
    }
}