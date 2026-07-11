#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> dp;

    dp.resize(N+1);

    if(N >= 1 ) dp[1] = 1;
    if(N >= 2) dp[2] = 2;

    for(int i = 3; i < N+1; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[N];

    return 0;


}