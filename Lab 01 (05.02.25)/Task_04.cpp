#include<iostream>
using namespace std;

int main()
{
    int t;
    cout << "Enter test cases: ";
    cin >> t;

    while(t--)
    {
        int n;
        cout << "\nEnter the number of elements: ";
        cin>>n;

        int a[n];
        cout << "Elements: ";
        for(int i = 0 ; i < n ; i++)
        {
            cin >> a[i];
        }

        int min_val = a[0];
        for(int i = 1 ; i < n ; i++)
        {
            if(a[i] < min_val)
            {
                min_val = a[i];
            }
        }

        int Count = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(a[i] > min_val)
            {
                Count++;
            }
        }

        cout << "\nOutput: " << Count << "\n";

    }


    return 0;
}
