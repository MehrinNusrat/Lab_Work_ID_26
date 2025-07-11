#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void constructPermutation(vector<int>& arr , int left , int right , int& k)
{
    if(right - left <= 1 || k <= 1)
    {
        return;
    }

    int mid = (left + right) / 2;

    k -= 2;

    constructPermutation(arr , left , mid , k);
    constructPermutation(arr , mid , right , k);

    if(right - left == 3)
    {
        swap(arr[left], arr[left + 1]);
    }
    else
    {
        reverse(arr.begin() + left, arr.begin() + right);
    }
}

bool isValidPermutation(int n , int k)
{
    return (k % 2 == 1) && (k <= (2 * n - 1));
}

vector<int> findPermutation(int n , int k)
{
    if(!isValidPermutation(n , k))
    {
        return {-1};
    }

    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = i + 1;
    }

    if(k == 1)
    {
        return arr;
    }

    constructPermutation(arr , 0 , n , k);

    return arr;
}

int main()
{
    int n , k;
    cin >> n >> k;

    vector<int> result = findPermutation(n , k);

    if(result[0] == -1)
    {
        cout << "-1" << "\n";
    }
    else
    {
        for(int num : result)
        {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}
