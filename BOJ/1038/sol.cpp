#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> nums;

void AddList(long long current)
{
    nums.push_back(current);

    int LastDigit = current % 10;

    for (int next = 0; next < LastDigit; next++)
    {
        
        AddList(current * 10 + next);
    }
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i <= 9; i++)
    {
        AddList(i);
    }

    sort(nums.begin(), nums.end());

    if (N >= nums.size())
    {
        cout << -1;
    }
    else
    {
        cout << nums[N];
    }

    return 0;
}