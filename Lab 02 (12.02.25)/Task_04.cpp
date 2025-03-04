#include <iostream>
#include <cstring> // For memset
#include<ctime>
#include<cmath>
using namespace std;

#define MAX 200 // Maximum digits to handle large numbers

//Grade school
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

//Karatsuba
int karatsuba(int x , int y)
{
    if(x < 10 || y < 10)
    {
        return x * y;
    }

    int n = max((int)log10(x) + 1 , (int)log10(y) + 1);
    int m = n / 2;

    //Dividing the numbers equally
    int a = x / pow(10 , m);
    int b = x % (int)pow(10 , m);
    int c = y / pow(10 , m);
    int d = y % (int)pow(10 , m);

    //Formula
    int z0 = karatsuba(b , d);
    int z1 = karatsuba((a + b) , (c + d));
    int z2 = karatsuba(a , c);

    return (z2 * pow(10 , (2 * m))) + ((z1 - z2 - z0) * pow(10 , m)) + z0;
}

int main()
{
    int A, B;
    cout << "Enter two integers: ";
    cin >> A >> B;

    BigIntMultiplication multiplier;

    clock_t startT = clock();

    cout << "Product Using Grade School Multiplication: ";
    multiplier.multiply(A, B);

    clock_t endT = clock();

    double duration_grade_scool = (double)(endT - startT) / CLOCKS_PER_SEC;
    cout << "Run Time For Grade School Multiplication: " << duration_grade_scool << " seconds\n";

    clock_t startK = clock();

    int result = karatsuba(A , B);
    cout << "Product Using Karatsuba Multiplication: " << result << "\n";

    clock_t endK = clock();

    double duration_karatsuba = (double)(endK- startK) / CLOCKS_PER_SEC;
    cout << "Run Time For Karatsuba Multiplication: " << duration_karatsuba << " seconds\n";

    double r = (abs(duration_grade_scool - duration_karatsuba));
    cout << "Compared Time: " << r << "seconds\n";

    return 0;
}
