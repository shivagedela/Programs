#include<bits/stdc++.h>
using namespace std;

/*** Problem - Given a square matrix, rotate matrix by 90 in anti-clockwise ***/

void printMatrix(int arr[][4], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    } 
}

// Reverse every row and then transpose
void rotateMatrix(int arr[][4], int n)
{
    /* Reverse each row 
    eg: 1 2 3  after reverse 3 2 1
        4 5 6                6 5 4 
        7 8 9                9 8 7 */
    for (int i = 0; i < n; i++)
        reverse(arr[i], arr[i] + n);

    /* Transpose - change rows to columns and columns to rows
    eg: 3 2 1  after reverse 3 6 9
        6 5 4                2 5 8 
        9 8 7                1 4 7 */
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            swap(arr[i][j], arr[j][i]);

//Time Complexity: O(N^2) + O(N^2) - first loop(N * reverse of N) + second loop(N*N)
//Space Complexity: O(1) - No extra space used 
}

// Mathematical approach
void bestWay(int arr[][4], int n)
{
    int temp;
    for (int j = 0; j < n/2; j++)
    {
        for (int i = j; i < n-j-1; i++)
        {
            temp = arr[i][j];
            arr[i][j] = arr[j][n-1-i];
            arr[j][n-1-i] = arr[n-1-i][n-1-j];
            arr[n-1-i][n-1-j] = arr[n-1-j][i];
            arr[n-1-j][i] = temp;
        }
        // printMatrix(arr, 4);
        // cout << "==============================\n";
    }
//Time Complexity: O(N^2) - first loop(N) * inner loop(N)
//Space Complexity: O(1) - No extra space used     
}

int main()
{
    int arr[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {8, 10, 11, 12},
                     {13, 14, 15, 16}};

    printMatrix(arr, 4);
    cout << "==============================\n";
    
    rotateMatrix(arr, 4);
    printMatrix(arr, 4);
    cout << "==============================\n";
    
    bestWay(arr, 4);
    printMatrix(arr, 4);
    cout << "==============================\n";
    return 0;
}