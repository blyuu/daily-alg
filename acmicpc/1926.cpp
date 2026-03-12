#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,-1,0};

int dfs(vector<vector<int>>& neighbors, vector<vector<bool>>& visited, int x, int y, int& count)
{
    visited[y][x] = true;

    count++;

    for(int i = 0; i< 4 ;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < neighbors[0].size() && ny>=0 && ny< neighbors.size())
        {
            if(!visited[ny][nx] && neighbors[ny][nx]== 1)
            {
                dfs(neighbors,visited,nx,ny,count);
            }
        }
    }

    return count;

}

int main()
{
    int n,m;
    cin >> n >> m;

    int value = 0; 
    vector<int> resultstore;

    vector<vector<int>> neighbors(n,vector<int>(m,0));
    vector<vector<bool>> visited(n,vector<bool>(m,false));

    for(int i =0; i< n; i++)
    {
        for(int j = 0 ; j<m; j++)
        {
            cin >> neighbors[i][j];
        }
    }

     for(int i =0; i< n; i++)
    {
        for(int j = 0 ; j<m; j++)
        {
            if(!visited[i][j] && neighbors[i][j]==1)
            {
                int result = dfs(neighbors,visited,j,i,value);
                resultstore.push_back(result);
            }
            value = 0;
        }
    }

    

    sort(resultstore.begin(),resultstore.end(), greater<int>());
    cout << resultstore.size() << endl;
    cout << resultstore[0];

    return 0;

}