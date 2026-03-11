#include <iostream>
#include <vector>

using namespace std;


void dfs(vector<vector<int>>& neighbors, vector<bool>& visited, int start)
{
    visited[start] = true;

    for(int val : neighbors[start])
    {
        if(!visited[val])
        {
            dfs(neighbors, visited, val);
        }
    }

}

int counter(vector<vector<int>>& neighbor, vector<bool>& visited, int node)
{
    int count = 0;
    for(int i = 1; i<=node; i++)
    {
        if(!visited[i])
        {
            dfs(neighbor,visited, i);
            count++;
        }
        
        
    }
    return count;
}

int main()
{
    int N, M;

    cin >> N >> M;

    vector<vector<int>> neighbors(N+1);

    vector<bool> visited (N+1, false);

    for(int i = 0; i < M ; i++)
    {
        int a,b;
        cin >> a>> b;

        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }

    int result = counter(neighbors,visited,N);

    cout << result;

    return 0;

}