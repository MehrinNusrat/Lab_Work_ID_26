#include<iostream>
using namespace std;

int main()
{
    int testCase;
    cout << "Enter test cases: ";
    cin >> testCase;
    for(int i = 1 ; i < testCase ; i++)
    {
        int n;
        cout << "\nEnter the number of elements: ";
        cin >> n;

        int arr[n];
        cout << "Enter the elements: ";
        cout << "\n";
        for(int i = 0 ; i < n ; i++)
        {
            cin >> arr[i];
        }

        int max_height = arr[0];
        for(int i = 1 ; i < n ; i++)
        {
            if(arr[i] > max_height)
            {
                max_height = arr[i];
            }
        }
        cout << "\nHighest Height: " << max_height;

    }

    return 0;

}
