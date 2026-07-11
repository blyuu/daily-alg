// Coin Change 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> dp;
    dp.resize(N+1);

    if(N >=1) dp[1] = 1;
    if(N >=2) dp[2] = 2;
    if(N >=3) dp[3] =1;
    if(N >=4) dp[4] = 1;

    for(int i = 5; i< N+1; i++)
    {
        int val1 = dp[4] + dp[i-4];
        int val2 = dp[3] + dp[i-3];
        int val3 = dp[1] + dp[i-1];

        dp[i] = min({val1,val2,val3});
    }

    cout << dp[N]; 

    return 0;
}