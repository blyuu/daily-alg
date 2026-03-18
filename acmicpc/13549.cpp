#include <iostream>
#include <deque>

using namespace std;

int bfs(int start, int end)
{
    int list[100000];
    for(int i = 0; i < 100000; i++)
    {
        list[i] = 1e9;   // 충분히 큰 값
    }
    list[start] = 0;
    deque<int> dq;
    dq.push_front(start);

    while(!dq.empty())
    {
       int now = dq.front();
       dq.pop_front();

        if(now*2 < 100000 && list[now*2] > list[now])
        {
            list[now*2] = list[now];
            dq.push_front(now*2);
        }

        if(now+1 < 100000 && list[now+1] > list[now] + 1)
        {
            list[now+1] = list[now]+1;
            dq.push_back(now+1);
        }

        if(now-1 >= 0 && list[now-1] > list[now] + 1)
        {
            list[now-1] = list[now]+1;
            dq.push_back(now-1);
        }

    }

    return list[end];
}

int main()
{
    int a,b;

    cin >> a >> b;

    cout << bfs(a,b);

    return 0;


}
