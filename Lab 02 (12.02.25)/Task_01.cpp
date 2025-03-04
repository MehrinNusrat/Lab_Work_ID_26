#include <iostream>
#include <cstring> // For memset
#include<ctime>
using namespace std;

#define MAX 200 // Maximum digits to handle large numbers

class BigIntMultiplication
{
private:
    int numA[MAX], numB[MAX], result[MAX];
    int lenA, lenB;

public:
    // Constructor to initialize arrays
    BigIntMultiplication()
    {
        memset(numA, 0, sizeof(numA));
        memset(numB, 0, sizeof(numB));
        memset(result, 0, sizeof(result));
        lenA = lenB = 0;
    }

    // Function to convert an integer into a digit array (least significant digit first)
    void storeNumber(int num, int arr[], int &length)
    {
        while (num > 0) {
            arr[length++] = num % 10; // storing digit
            num /= 10;
        }
    }

    // Function to multiply two integers using grade school multiplication
    void multiply(int A, int B)
    {
        if (A == 0 || B == 0)
        {
            cout << "0" << endl; // If either number is 0, the product is 0
            return;
        }

        // Store numbers in digit arrays
        storeNumber(A, numA, lenA);
        storeNumber(B, numB, lenB);

        // Perform grade school multiplication
        for (int i = 0; i < lenB; i++)
        {
            for (int j = 0; j < lenA; j++)
            {
                result[i + j] += numB[i] * numA[j];
                result[i + j + 1] += result[i + j] / 10; // carry
                result[i + j] %= 10; // remainder
            }
        }

        printResult();
    }

    // Function to print the final result
    void printResult()
    {
        int lenResult = lenA + lenB;
        while (lenResult > 1 && result[lenResult - 1] == 0)
        {
            lenResult--; // Remove leading zeros
        }

        // Print the result in correct order (reverse of storage)
        for (int i = lenResult - 1; i >= 0; i--)
        {
            cout << result[i];
        }
        cout << endl;
    }
};

// Driver Code
int main() {
    int A, B;
    cout << "Enter two integers: ";
    cin >> A >> B;

    BigIntMultiplication multiplier;

    clock_t startT = clock();

    cout << "Product: ";
    multiplier.multiply(A, B);

    clock_t endT = clock();

    double duration;
    duration = (double)(endT - startT) / CLOCKS_PER_SEC;
    cout << "\nDuration: " << duration << " seconds";

    return 0;
}

