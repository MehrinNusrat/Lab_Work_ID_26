#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;

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
    clock_t start;
    double duration;

    start = clock();

    int num1;
    cout << "Enter first number: ";
    cin >> num1;

    int num2;
    cout << "Enter second number: ";
    cin >> num2;

    int result = karatsuba(num1 , num2);
    cout << "The product: " << result;

    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    cout << "\nDuration: " << duration << " seconds";

    return 0;
}
