#include<iostream>
using namespace std;

int main()
{
    int arr1[100] = {2, 4, 6}; // First array
    int size1 = 3;

    int arr2[100] = {8, 10, 12, 14}; // Second array
    int size2 = 4;

    int mergedSize = size1 + size2;
    int merged[mergedSize];

    //Copying first array
    for(int i = 0 ; i < size1 ; i++)
    {
        merged[i] = arr1[i];
    }

    //Copying second array
    for(int i = 0 ; i < size2 ; i++)
    {
        merged[size1 + i] = arr2[i];
    }

    //Print
    cout << "The merged array: ";
    for(int i = 0 ; i < mergedSize ; i++)
    {
        cout << merged[i] << " ";
    }

    cout << "\n";

    return 0;

}
