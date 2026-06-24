#include <iostream>
#include <vector>

using namespace std;

void dfs(int start, vector<bool>&visited, vector<vector<int>>& neighbors,vector<int> &list)
{
    visited[start] = true;
    list.push_back(start);

    for(int val : neighbors[start])
    {
        if(!visited[val])
        {
            dfs(val, visited, neighbors, list);
        }
    }
}

int main()
{
    vector<vector<int>> neighbors(6);
    vector<bool> visited(6,0);
    vector<int> list;

    neighbors[1].push_back(2);
    neighbors[1].push_back(3);

    neighbors[2].push_back(4);
    neighbors[2].push_back(1);

    neighbors[3].push_back(1);
    neighbors[3].push_back(5);

    neighbors[4].push_back(2);
    neighbors[4].push_back(3);

    dfs(1,visited, neighbors,list);

    for(auto c: list)
    {
        cout << c << endl;
    }

    return 0;
}