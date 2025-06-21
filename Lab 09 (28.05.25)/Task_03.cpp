#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void countingSort(vector<int>& arr)
{
    if(arr.empty())
    {
        return;
    }

    int maxVal = *max_element(arr.begin(), arr.end());

    vector<int> count(maxVal + 1 , 0); // C
    vector<int> output(arr.size());  // B

    for(int i : arr)
    {
        count[i] ++;
    }

    for(int i = 1 ; i <= maxVal ; i++)
    {
        count[i] += count[i - 1];
    }

    for(int i = arr.size() - 1 ; i >= 0 ; i--)
    {
        output[count[arr[i]] - 1] = arr[i]; // B[C[A[i]] = A[i]
        count[arr[i]]--; //C[A[i]] = C[A[i]] - 1
    }

    arr = output;
}

int main()
{
    vector<int> data = {4, 2, 2, 8, 3, 3, 1}; //A

    countingSort(data);

    for(int num : data)
    {
        cout << num << " ";
    }

    return 0;
}
