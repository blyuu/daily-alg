#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> dp(N+1);

    if(N >= 1) dp[1] = 1;
    if (N >=2) dp[2] = 2;
    if (N >=3 ) dp[3] = 4;

    for(int i = 4; i < N+1; i++)
    {
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }

    cout << dp[N];

    return 0;

}