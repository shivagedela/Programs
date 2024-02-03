#include<iostream>
using namespace std;

/*** Problem - Given array of numbers, find largest subarray sum possible. ***/

//Bruteforce - Go through all subarrays possbile and compare sum
int bruteforce(int* arr, int n, int* start, int* end)
{
    int max_sum = INT8_MIN;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum > max_sum)
            {
                max_sum = sum;
                *start = i;
                *end = j;
            }
            //cout << sum << " " << *start << " " << *end << endl;
        }
        
    }
    return max_sum;
//Time Complexity: O(N^2) - first loop (N) * inner loop(N)
//Space Complexity: O(1) - No extra space used
}

/* Kadane Algorithm - calculate sum till current index and compare max_sum 
So basically subarray with negative is left(i.e, we set sum=0) in this algorithm */
int kadaneAlgorithm(int* arr, int n, int* start, int* end)
{
    int max_sum = INT8_MIN, sum_ending_here = 0; 
    int s = 0;  //start of subarray
    for (int i = 0; i < n; i++)
    {
        sum_ending_here += arr[i];
        if (sum_ending_here > max_sum)
        {
            max_sum = sum_ending_here;
            *start = s;
            *end = i;
        }
        
        if (sum_ending_here < 0) 
        {
            /*This implies that this subarray sum is negative, So we ignore it
            Hence we set sum = 0 and start of next subarray s = current_index + 1*/
            sum_ending_here = 0;  
            s = i + 1;
        }
        //cout << sum_ending_here << " " << *start << " " << *end << endl;    
    }
    return max_sum;
//Time Complexity: O(N) - one loop (N)
//Space Complexity: O(1) - No extra space used
}

int main()
{
    int arr[] = {2, 3, -1, 5, 4, -2, 6, -3, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int start = 0, end = arr_size;

    int max_sum_BF = bruteforce(arr, arr_size, &start, &end);
    cout << "Largest_Sum_Bruteforce - " << max_sum_BF << endl;
    for (int i = start; i <= end; i++)
        cout << arr[i] << " ";
    cout << endl << "=================================\n";

    start = 0; end = arr_size;
    int max_sum_algo = kadaneAlgorithm(arr, arr_size, &start, &end);
    cout << "Largest_Sum_KadaneAlgorithm - " << max_sum_algo << endl;
    for (int i = start; i <= end; i++)
        cout << arr[i] << " ";
    cout << endl << "=================================\n";

    return 0;
}