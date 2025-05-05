#include<iostream>
using namespace std;

int main()
{
    int m , n , p;
    cout << "Enter rows and columns of matrix A: ";
    cin >> m >> n;
    cout << "Enter columns of matrix B: ";
    cin >> p;

    int A[m][n] , B[n][p] , C[m][p] = {0};

    int multiplicationCount = 0;
    int additionCount = 0;

    cout << "Mat A: ";
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Mat B: ";
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < p ; j++)
        {
            cin >> B[i][j];
        }
    }

    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < p ; j++)
        {
            C[i][j] = 0;
            for(int k = 0 ; k < n ; k++)
            {
                C[i][j] = C[i][j] + (A[i][k] * B[k][j]);

                multiplicationCount++;

                if(k > 0)
                {
                    additionCount++;
                }
            }
        }
    }

    cout << "\nMatrix multiplication of A and B: ";
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < p ; j++)
        {
            cout << C[i][j] << " ";
        }
    }

    cout << "\n";

    cout << "Total multiplication operations: " << multiplicationCount << "\n";
    cout << "Total addition operations: " << additionCount << "\n";

    return 0;
}

