#include<iostream>
using namespace std;

int getMax(int arr[] , int n)
{
    int max = arr[0];
    for(int i = 1 ; i < n ; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[] , int n , int exp)
{
    int output[n];
    int Count[10] = {0};

    for(int i = 0 ; i < n ; i++)
    {
        Count[(arr[i] / exp) % 10]++;
    }

    for(int i = 1 ; i < 10 ; i++)
    {
        Count[i] += Count[i - 1];
    }

    for(int i = n - 1 ; i >= 0 ; i--)
    {
        output[Count[(arr[i] / exp) % 10] -1] = arr[i];
        Count[(arr[i] / exp) % 10]--;
    }

    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[] , int n)
{
    int max = getMax(arr, n);

    for(int exp = 1 ; max / exp > 0 ; exp *= 10)
    {
        countSort(arr , n , exp);
    }
}

void printArray(int arr[] , int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {329 , 457 , 657 , 839 , 436 , 720 , 355};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr , n);
    cout << "Sorted array: ";
    printArray(arr , n);

    return 0;
}
