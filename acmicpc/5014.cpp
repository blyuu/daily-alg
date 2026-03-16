#include <iostream>
#include <queue>
#include <vector>


using namespace std;

long long bfs(long long start, long long end, long long up, long long down, long long max)
{
    queue<pair<long long,long long>> q;

    vector<bool> visited(max+1,false);
    q.push({start,0});

    while(!q.empty())
    {
        long long front = q.front().first;
        long long count = q.front().second;
        q.pop();

        long long frontadd = front + up;
        long long downminus = front - down;

        if(front == end)
        {
            return count;
        }

        if(frontadd <= max && !visited[frontadd])
        {
            q.push({frontadd,count+1});
            visited[frontadd] = true;
        }

        if(downminus > 0 && !visited[downminus])
        {
            q.push({downminus,count+1});
            visited[downminus] = true;
        }


    }

    return -1;
}

int main()
{
    long long F,S,G,U,D;
    cin >> F >> S >> G >> U >> D;

    long long result =  bfs(S,G,U,D,F);

    if(result == -1)
    {
        cout << "use the stairs" << endl;
    }
    else
    {
        cout << result;
    }

    return 0;
}

