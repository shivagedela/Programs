#include<iostream>
using namespace std;

void print_subarray(char* arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        for (int j = i; j < arr_size; j++)
        {
            /* print continuous elements from i to j
               i.e, here {s}, {s h}, {s h i}... */
            cout << "{ ";
            for (int k = i; k <= j; k++)
                cout << arr[k] << " ";
            cout << "}\n";         
        }       
    }
//Time Complexity - O(N^3) - first loop (N) * inner loop(N) * inner loop(N)
//Space Complexity: O(1) - No extra space used
}

int main()
{
    char arr[] = {'s', 'h', 'i', 'v', 'a'};
    int n = sizeof(arr)/sizeof(arr[0]);
    print_subarray(arr, n);  //print subarrays of given array
    
    return 0;
}