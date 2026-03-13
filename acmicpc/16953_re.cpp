#include <iostream>
#include <queue>

using namespace std;

/*
2 162가 입력되면 
2 4 21 8 81 42 211 가 순서대로 queue에 들어감 
여기서 이제 162보다 크면 다 queue에 추가 안하게 
*/

int bfs(int a, int b)
{
    queue<int> q;
    int count = 0;
    q.push(a);

    while(!q.empty())
    {

        int front = q.front();
        q.pop();

        int twice = front*2;
        int add1 = front*10 +1;

        if(front == b)
        {
            return count;
        }
        if(twice <= b)
        {
            count++;
            q.push(twice);
        }
        if(add1 <= b)
        {
            count++;
            q.push(add1);
        }
        
    }

    return -1;
}


int main()
{
    int a,b;
    cin >> a >> b;

    cout << bfs(a,b);

    return 0;


}