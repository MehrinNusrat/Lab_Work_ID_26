#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> Matrix;

Matrix add(const Matrix &A , const Matrix &B)
{
    int n = A.size();
    Matrix C(n , vector<int>(n));
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

Matrix subtract(const Matrix &A , const Matrix &B)
{
    int n = A.size();
    Matrix C(n , vector<int>(n));
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

Matrix strassen(const Matrix &A , const Matrix &B)
{
    int n = A.size();
    Matrix C(n , vector<int>(n , 0));

    if(n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
    }
    else
    {
        int k = n / 2;
        Matrix A11(k , vector<int>(k)) , A12(k , vector<int>(k)) , A21(k , vector<int>(k)) , A22(k , vector<int>(k));
        Matrix B11(k , vector<int>(k)) , B12(k , vector<int>(k)) , B21(k , vector<int>(k)) , B22(k , vector<int>(k));

        for(int i = 0 ; i < k ; i++)
        {
            for(int j = 0 ; j < k ; j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + k];
                A21[i][j] = A[i + k][j];
                A22[i][j] = A[i + k][j + k];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + k];
                B21[i][j] = B[i + k][j];
                B22[i][j] = B[i + k][j + k];
            }
        }

        Matrix M1 = strassen(A11 , subtract(B12 , B22));
        Matrix M2 = strassen(add(A11 , A12) , B22);
        Matrix M3 = strassen(add(A21 , A22) , B11);
        Matrix M4 = strassen(A22 , subtract(B21 , B11));
        Matrix M5 = strassen(add(A11 , A22) , add(B11 , B22));
        Matrix M6 = strassen(subtract(A12 , A22) , add(B21 , B22));
        Matrix M7 = strassen(subtract(A11 , A21) , add(B11 , B12));

        Matrix C11 = subtract(add(add(M4 , M5) , M6) , M2);
        Matrix C12 = add(M1 , M2);
        Matrix C21 = add(M3 , M4);
        Matrix C22 = subtract(add(subtract(M1 , M3) , M5) , M7);

        for(int i = 0 ; i < k ; i++)
        {
            for(int j = 0 ; j < k ; j++)
            {
                C[i][j] = C11[i][j];
                C[i][j + k] = C12[i][j];
                C[i + k][j] = C21[i][j];
                C[i + k][j + k] = C22[i][j];
            }
        }
    }

    return C;
}

void printMatrix(const Matrix &M)
{
    for(const auto &row : M)
    {
        for(int num : row)
        {
            cout << num << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    cout << "\n";

    Matrix A(n , vector<int>(n)) , B(n , vector<int>(n));

    cout << "Mat A: ";
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "\n";

    cout << "Mat B: ";
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> B[i][j];
        }
    }

    Matrix C_add = add(A , B);
    Matrix C_subtract = subtract(A , B);
    Matrix C_strassen_multiplication = strassen(A , B);

    cout << "\nMultiplication Result Using Strassen's Idea:\n\n";
    printMatrix(C_strassen_multiplication);

    return 0;
}

