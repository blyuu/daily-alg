#include <iostream>
#include <queue>

using namespace std;

long long bfs(long long start, long long end)
{
    queue<pair<long long,long long>> q;

    q.push({start, 0});
    long long result = 0;

    while(!q.empty())
    {
        long long a = q.front().first;
        long long  b = q.front().second;
        q.pop();

        if (a == end)
        {
            return b;
        }

        if ( a*2 <= end)
        {
           
            q.push({a*2,b+1});
        }

        if( a*10 +1 <= end)
        {
            
            q.push({a*10+1, b+1});
        }

    }

    return -1;
}

int main()
{
    long long a,b;
    cin >> a>> b;

    long long result = bfs(a,b);

    long long val = (result == -1 )? -1 : result+1;

    cout << val;

    return 0;
}