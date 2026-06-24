#include <iostream>
#include <vector>

using namespace std;


void dfs(int start, vector<vector<int>>& Neighbors, vector<bool>& visited)
{
    visited[start] =  true;

    for(int val : Neighbors[start])
    {
        if(!visited[val])
        {
            dfs(val, Neighbors, visited);
        }
    }

}

int Counter(int start, int end, vector<vector<int>>& Neighbors, vector<bool>& visited)
{
    int count  = 0; 
    for(int i = start ; i<= end; i++)
    {
        if(!visited[i])
        {
            dfs(i,Neighbors,visited);
            count++;
            
        }
    }

    return count;
}

int main()
{
   vector<vector<int>> Neighbors(7);

   vector<bool> visited(7,0);

   int count = 0;

   Neighbors[1].push_back(2);
   Neighbors[2].push_back(1);

   Neighbors[3].push_back(4);

   Neighbors[4].push_back(3);
   Neighbors[4].push_back(5);

   int result = Counter(1,6,Neighbors,visited);

   cout << result; 

   return 0;
}