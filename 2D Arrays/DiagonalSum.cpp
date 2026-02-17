#include <iostream>

using namespace std;

void diagonalSum(int arr[][3], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++) // rows
    {
        for (int j = 0; j < n; j++) // cols
        {
            if (i == j)
            {
                sum += arr[i][j];
            }
            else if (j == n - i - 1)
            {

                sum += arr[i][j];
            }
        }
    }

    cout << "Sum is = " << sum << endl;
}

void diagonalSum2(int arr[][3], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++) // rows
    {
        sum += arr[i][i];

        if (i != n-i-1)
        {
            sum += arr[i][n-i-1];
        }
        
    }

    cout << "Sum is = " << sum << endl;
}

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    diagonalSum2(arr, 3);

    return 0;
}