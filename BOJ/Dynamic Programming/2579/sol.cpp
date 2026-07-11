#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> points (N+1);

    vector<int> dp(N+1);

    for(int i = 1; i< N+1; i++)
    {
        cin >> points[i];
    }

    if(N >= 1) dp[1] = points[1];
    if(N >= 2) dp[2] = dp[1] + points[2];
    if(N >=3) dp[3] = dp[1]+points[3];

    for(int i = 4; i< N+1; i++)
    {

        int val1 = dp[i-3] + points[i-3] + points[i];
        int val2 = dp[i-2] + points[i];

        dp[i] = max({val1,val2});
    }

    cout << dp[N];

    return 0;

}

