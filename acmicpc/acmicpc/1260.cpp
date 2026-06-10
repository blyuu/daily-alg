#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

vector<int> dfslist;
vector<int> bfslist;

void dfs(vector<vector<int>>& neighbors, vector<bool>& visited, int start)
{
    visited[start] = true;

    dfslist.push_back(start);

    for(int neighbor : neighbors[start])
    {
        if(!visited[neighbor])
        {
            dfs(neighbors, visited, neighbor);
        }
    }
}

void bfs(vector<vector<int>>& neighbors, vector<bool>& visited, int start)
{
    queue<int> q; 
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        for(int val : neighbors[q.front()])
        {
            if(!visited[val])
            {
                visited[val] = true;
                q.push(val);
            }
        }
        bfslist.push_back(q.front());
        q.pop();
    }
}

void reset(vector<bool>& visited)
{
    for (int i = 0; i <visited.size();i++)
    {
        visited[i] = false;
    }
}
int main()
{
    int node, line, start;
    cin >> node >> line >> start;

    vector<vector<int>> neighbors(node+1);
    vector<bool> visited(node+1,false);

    int n = 0;
    while(n < line)
    {
        int a,b;
        cin >> a >> b;

        neighbors[a].push_back(b);
        neighbors[b].push_back(a);

        n++;
    }

    for(int i = 1; i <= node; i++)
    {
        sort(neighbors[i].begin(), neighbors[i].end());
    }

    dfs(neighbors,visited, start);
    reset(visited);
    bfs(neighbors,visited, start);


    for(int i = 0; i < dfslist.size(); i++)
    {
        cout << dfslist[i];
        if(i != dfslist.size()-1) cout << " ";
    }

    cout << endl;

    for(int i = 0; i < bfslist.size(); i++)
        {
            cout << bfslist[i];
            if(i != bfslist.size()-1) cout << " ";
        }

    return 0;

}