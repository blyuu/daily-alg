#include <iostream>
#include <vector>
#include <deque>


using namespace std;


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

        if(valX+1 < dist[0].size() && v1[valY][valX+1] == 1 &&  dist[valY][valX+1] > dist[valY][valX])
        {
            dist[valY][valX+1] = dist[valY][valX] + 1;
            dq.push_back({valY, valX+1});
        }

        if(valY+1 < dist.size() && v1[valY+1][valX] == 1 &&  dist[valY+1][valX] > dist[valY][valX])
        {
            dist[valY+1][valX] = dist[valY][valX] + 1;
            dq.push_back({valY+1, valX});
        }

        if(valY-1 >=0 && v1[valY-1][valX] == 1 &&  dist[valY-1][valX] > dist[valY][valX])
        {
            dist[valY-1][valX] = dist[valY][valX] + 1;
            dq.push_back({valY-1, valX});
        }

        if(valX-1 >=0 && v1[valY][valX-1] == 1 &&  dist[valY][valX-1] > dist[valY][valX])
        {
            dist[valY][valX-1] = dist[valY][valX] + 1;
            dq.push_back({valY, valX-1});
        }


        if(valX+1 < dist[0].size() && v1[valY][valX+1] == 0 &&  dist[valY][valX+1] > dist[valY][valX])
        {
            dist[valY][valX+1] = dist[valY][valX];
            dq.push_front({valY, valX+1});
        }

        if(valY+1 < dist.size() && v1[valY+1][valX] == 0 &&  dist[valY+1][valX] > dist[valY][valX])
        {
            dist[valY+1][valX] = dist[valY][valX];
            dq.push_front({valY+1, valX});
        }

        if(valY-1 >=0 && v1[valY-1][valX] == 0 &&  dist[valY-1][valX] > dist[valY][valX])
        {
            dist[valY-1][valX] = dist[valY][valX];
            dq.push_front({valY-1, valX});
        }

        if(valX-1 >=0 && v1[valY][valX-1] == 0 &&  dist[valY][valX-1] > dist[valY][valX])
        {
            dist[valY][valX-1] = dist[valY][valX];
            dq.push_front({valY, valX-1});
        }
        
    }

    int answer = dist[row-1][col-1];

    return answer;
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