#include <iostream>
#include <vector>

using namespace std;

int N, K, S;
bool IsTrue = false;
vector<int> arr;

void dfs(int index, int sum, int cnt)
{
    if (index == N)
    {
        if (sum == S && cnt == K)
        {
            IsTrue = true;
        }
        return;
    }

    // 현재 원소 선택
    dfs(index + 1, sum + arr[index], cnt + 1);

    // 현재 원소 선택 안 함
    dfs(index + 1, sum, cnt);
}

int main()
{
    cin >> N >> K >> S;

    arr.resize(N);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    dfs(0, 0, 0);

    if (IsTrue)
        cout << "YES";
    else
        cout << "NO";
}