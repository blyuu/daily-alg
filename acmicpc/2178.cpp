#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int nx[4] = {1,0,-1,0};
int ny[4] = {0, 1, 0 ,-1};

void bfs(vector<vector<int>>&grid, int startrow, int startcolumn)
{
    queue<pair<int,int>> q;
    q.push({startrow,startcolumn});

    while(!q.empty())
    {
        int ty = q.front().first;
        int tx = q.front().second;

        q.pop();
        for(int i = 0; i< 4; i++)
        {
            int newy = ty+ny[i];
            int newx= tx + nx[i];

            {
                if (newy >= 0 && newy < grid.size() && newx >=0 && newx < grid[newy].size())
                {
                    if(grid[newy][newx] == 1)
                    {
                        grid[newy][newx] = grid[ty][tx] + 1;
                        q.push({newy,newx});
                    }
                }
            }
        }
    }
    
}

int main()
{
    //scanf(%1d)로 입력받기

    int row, column;

    cin >> row >> column;

    vector<vector<int>>grid(row, vector<int>(column));

    for(int i = 0; i< row; i++)
    {
        for(int j = 0; j<column; j++)
        {
            scanf("%1d", &grid[i][j]);
        }
    } 
    bfs(grid,0,0);

    cout << grid[row-1][column-1];

    return 0;


}