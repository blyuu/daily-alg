#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> list; 


void listadder(vector<vector<bool>>& visited, int start, int end, int M)
{
    if(start >= 1 && start <= end)
    {
        for(int i = -M; i<= M; i++)
        {
            if( i== 0)
            {
                continue;
            }

            int next = start + i;

            if(next >= 1 && next <= end)
            {
                if(!visited[start][next])
                {
                    list.push_back({start,next});
                    visited[start][next] = true;
                    listadder(visited,next,end,M);
                }
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, 0));

    listadder(visited, 1, N, M);

    for(auto val : list)
    {
        cout << val.first << " " << val.second << endl;
    }

    return 0;



}