#include<iostream>
using namespace std;

int Fibonacci(int n , int memo[])
{
    if(n < 0)
    {
        cout << "Invalid input.";
        return -1;
    }

    if(n == 0)
    {
        return 0;
    }

    if(n == 1)
    {
        return 1;
    }

    if(memo[n] != -1)
    {
        return memo[n];
    }
    memo[n] = Fibonacci(n - 1 , memo) + Fibonacci(n - 2 , memo); // check for n-1 and n-2 as well
    return memo[n];
}

void FibonacciSequence(int n , int memo[])
{
    if (n < 0)
    {
        cout << "Invalid input.";
        return;
    }

    for (int i = 0 ; i <= n ; i++)
    {
        cout << Fibonacci(i, memo) << " ";
    }
    cout << "\n";
}

int main()
{
    int n;
    cout << "Enter a number n: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Invalid input.\n";
        return 0;
    }

    int memo[n + 1];
    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }

    cout << "Fibonacci(" << n << ") = " << Fibonacci(n, memo) << "\n";

    FibonacciSequence(n , memo);

    return 0;

}
