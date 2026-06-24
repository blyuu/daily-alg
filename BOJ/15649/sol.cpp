#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<bool>& visited, vector<int>& path, int N, int M, vector<vector<int>>& result)
{
    if(path.size() == M)
    {
        result.push_back(path);
        return;
    }

    for(int i = 1; i <= N; i++)
    {
        if(!visited[i])
        {
            path.push_back(i);
            visited[i] = true;
            dfs(visited,path,N,M,result);
            path.pop_back();    
            visited[i] = false;
        }
        
    }

}


int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> path;
    vector<bool> visited(N+1, false);
    vector<vector<int>> result;

    dfs(visited,path, N, M, result);

    for(auto c: result)
    {
        for (auto d : c)
        {
            cout << d;
        }

        cout << endl;
    }

    return 0;

}