#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements of array A: ";
    cin >> n;

    int A[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> A[i];
    }

    int sum = 0;

    for(int i = 0 ; i < n ; i++)
    {
        sum = sum + A[i];
    }

    cout << "Sum = " << sum;

    return 0;
}
