#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int MAX = 100000;
long long bfs(long long start, long long end)
{

    vector<long long> distrecord(MAX, 1e9);

    distrecord[start] = 0;

    deque<long long> dq;

    dq.push_front(start);

    while(!dq.empty())
    {
        long long val = dq.front();
        dq.pop_front();

        if(val == end)
        {
            break;
        }

        if(val*2 < MAX && distrecord[val] < distrecord[val*2])
        {
            distrecord[val*2] = distrecord[val];
            dq.push_front(val*2);
        }

        if(distrecord[val] < distrecord[val+1] && val+1 <MAX)
        {
            distrecord[val+1]= distrecord[val]+1;
            dq.push_back(val+1);
        }
        if(distrecord[val] < distrecord[val-1] && val-1 >=0)
        {
            distrecord[val-1] = distrecord[val]+1;
            dq.push_back(val-1);
        }
    }

    return distrecord[end];
}

int main()
{
    long long start, end;

    cin >> start >> end;

    long long result = bfs(start,end);

    cout << result << endl;

    return 0;


}