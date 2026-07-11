#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> numlist;
vector<int> operators;
vector<int> sumresult;

void dfs(int index, int sum, int pls, int min, int mul, int div)
{
    if(index == N)
    {
        sumresult.push_back(sum);
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        
    }
}

int main()
{
    cin >> N;

    numlist.resize(N);
    operators.resize(4);

    for(int i = 0; i = N; i++)
    {
        cin >> numlist[i];
    }

    for(int i = 0; i <  4 ;i++)
    {
        cin >> operators[i];    
    }
}