#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;

void bfs(vector<int>& neighbors, vector<bool>& visited, int start)
{
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int a = q.front();
        q.pop();

        int forward = a + neighbors[a];
        int backward = a - neighbors[a];

        if(forward < neighbors.size() && !visited[forward])
        {
            q.push(forward);
            visited[forward] = true;
        }
        if(backward >= 0 && !visited[backward])
        {
            q.push(backward);
            visited[backward] = true;
        }

        
    }

}

int main()
{
    int node;
    cin >> node;

    vector<int> neighbors;
    vector<bool> visited(node,false);

    for(int i = 0; i<node; i++)
    {
        int a;
        cin >> a;
        neighbors.push_back(a);
    }


    int start;
    cin >> start;

    bfs(neighbors,visited, start-1);

    int count = 0; 
    for (auto a : visited)
    {
        if (a)
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;

}