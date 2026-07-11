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

    if(N >= 1 ) dp[1] = 0;
    if(N>=2) dp[2] = 1;
    if(N>=3) dp[3] = 1;

    for(int i = 4; i <N+1; i++)
    {
        int val1 = 10000;
        int val2 = 10000;
        if(i%2 == 0)
        {
            val1 = dp[i/2] + 1;
        }

        
        if(i%3 == 0)
        {
            val2 = dp[i/3] +1;
        }

        int val3 = dp[i-1] + 1;

        dp[i] = min({val1,val2,val3});
    }

    cout << dp[N];

    return 0;
}