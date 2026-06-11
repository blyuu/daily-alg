#include <iostream>
#include <vector>
#include <deque>


using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int bfs(vector<vector<int>>& v1,vector<vector<int>>& dist,int x, int y)
{
    deque<pair<int,int>> dq;


    int row = v1.size();
    int col = v1[0].size();

    dq.push_front({y,x});

    dist[y][x] = 0;

    while(!dq.empty())
    {
        int valY = dq.front().first;
        int valX = dq.front().second;

        dq.pop_front();

        for(int i = 0; i <4 ; i++)
        {
            int ny = valY +dy[i];
            int nx = valX +dx[i]; 

            if(ny >= 0 && ny< row && nx >=0 && nx < col)
            {
                int count = v1[ny][nx];

                if(dist[ny][nx] > dist[valY][valX] + count)
                {
                    dist[ny][nx] = dist[valY][valX] + count;

                    if(count == 0)
                    {
                        dq.push_front({ny,nx});
                    }
                    else
                    {
                        dq.push_back({ny,nx});
                    }
                    
                }
            }
        }

    }

    return dist[row-1][col-1];
}

int main()
{
    int row, column;

    cin >> column >> row;

    vector<vector<int>> v1(row, vector<int>(column, 1));

    vector<vector<int>> distance(row, vector<int>(column, 1e9));


    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<column; j++)
        {
            scanf("%1d", &v1[i][j]);
        }
    }   


    int result = bfs(v1,distance, 0,0);

    cout << result << endl;

    return 0;

}