#include <iostream>
#include <vector>

using namespace std;

void dfs(int N, int M,vector<int>& path, vector<vector<int>>&list,int start)
{
    if(path.size() == M)
    {
        list.push_back(path);
        return;
    }

    for(int i = start; i <= N; i++)
    {
        path.push_back(i);
        dfs(N,M,path,list, i+1);
        path.pop_back();
    }
 

}


int main()
{
    int N,M;
    cin >> N >> M;

    vector<int> path;
    vector<vector<int>>list;

    dfs(N,M,path,list,1);

   for (auto c : list)
   {
        for (auto d: c)
        {
            cout << d; 
        }
        cout << endl;
   }

   return 0;

    

}