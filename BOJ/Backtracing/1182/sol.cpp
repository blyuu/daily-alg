#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> arr;
int count = 0;

void dfs(int index, int sum)
{
    if(index == N)
    {
        if(sum == M)
        {
            count++;
        }
        return;
    }

    dfs(index+1 , sum+arr[index]);
    dfs(index+1, sum);

}

int main()
{
    cin >> N >> M;
    arr.resize(N);

    for(int i = 0; i< N; i++)
    {
        cin >> arr[i];
    }

    dfs(0,0);

    if(M == 0)
    {
        count--;
    }

    cout << count;

    return 0;


}