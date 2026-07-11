#include <iostream>
#include <vector>

using namespace std;

void dfs(int N, int M, vector<vector<int>>&list, vector<int>&path, int start)
{
    if(path.size() == M)
    {
        list.push_back(path);
        return;
    }

    for(int i = start;i <= N ; i++)
    {
        
        path.push_back(i);
        dfs(N,M,list,path, i);
        path.pop_back();
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> list;
    vector<int> path;
    vector<bool> visited(N+1, false);

    dfs(N,M,list,path,1);

    for(auto c: list)
    {
        for(auto d: c)
        {
            cout << d;
        }
        cout << endl;
    }

    return 0;

}