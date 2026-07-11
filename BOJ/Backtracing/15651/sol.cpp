#include <iostream>
#include <vector>

using namespace std;

void dfs(int N, int M, vector<vector<int>>&list, vector<int>&path)
{
    if(path.size() == M)
    {
        list.push_back(path);
        return;
    }

    for(int i = 1; i<=N; i++)
    {
        path.push_back(i);
        dfs(N,M,list,path);
        path.pop_back();
    }
}

int main()
{
    int N,M;
    cin >> N >> M;

    vector<vector<int>> list;
    vector<int> path;

    dfs(N,M,list,path);

    for(auto c: list)
    {
        for (auto d: c)
        {
            cout << d;
        }
        cout << endl;
    }

    return 0;

}