#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<int> housenum;

void dfs(vector<vector<int>>& neighbors, vector<vector<bool>>& visited, int x, int y, int& count)
{
    visited[y][x] = true;

    for(int i = 0; i< 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(ny >=0 && ny < neighbors[x].size() && nx >= 0 && nx < neighbors.size())
        {
            if(!visited[ny][nx] && neighbors[ny][nx] == 1)
            {
                count++;
                dfs(neighbors, visited, nx,ny, count);
            }
        }
    }

}


int main()
{
    int n;
    cin >> n;

    int num = 0;

    int counter = 0; 

    vector<vector<int>> neighbors (n, vector<int>(n,0));

    vector<vector<bool>>visited (n,vector<bool> (n,false));

    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< n; j++)
        {
            scanf("%1d",&neighbors[i][j]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n ; j++)
        {
           if(!visited[j][i] && neighbors[j][i] == 1)
           {
                counter = 1;
                dfs(neighbors,visited, i,j, counter);
                housenum.push_back(counter);
                counter = 0;
                num++;
           }
        }
    }

    sort(housenum.begin(),housenum.end());

    cout << num << endl;

    for( auto v: housenum)
    {
        cout << v  << endl;
    }


    return 0;


    
    
}