#include <iostream>
#include <vector>


using namespace std;

void dfs(vector<vector<int>>& neighbors, vector<bool>& visited, int start, int& count)
{
    visited[start] = true;


    for(int a : neighbors[start])
    {
        if(!visited[a])
        {
            dfs(neighbors, visited, a,count);
            count++;
        }
    }

}

int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;

    vector<vector<int>> neighbors (n+1);
    vector<bool> visited(n+1,false);

    for(int i = 0; i< m; i++)
    {
        int a,b;

        cin >> a >> b;

        neighbors[a].push_back(b);
        neighbors[b].push_back(a);

    }

    int count = 0;

    dfs(neighbors,visited, 1, count);


    cout << count << endl;

    return 0;

}