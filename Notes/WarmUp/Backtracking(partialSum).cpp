#include <iostream>
#include <vector>

using namespace std;

int Number, Sum;
vector<int> arr;

bool IsTrue = false;

void dfs(int index, int sum)
{
    if(index == Number)
    {
        if(sum == Sum)
        {
            IsTrue = true;
        }
        
        return;
    }

    dfs(index +1, sum + arr[index]);
    dfs(index +1 , sum);
}

int main()
{
    cin>> Number >> Sum;

    arr.resize(Number);
    
    for(int i = 0; i < Number; i++)
    {
        cin >> arr[i];
    }

    dfs(0,0);


    if(IsTrue)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }


}