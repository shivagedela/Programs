#include<bits/stdc++.h>
using namespace std;

/*** Problem - Given array of numbers and a sum, find largest subarray with given sum possible. ***/

//Bruteforce - Go through all subarrays possbile and compare length of subarray for given sum
int bruteforce(int* arr, int n, int k, int* start, int* end)
{
    int max_length = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                // length of current subarray is diff of i and j
                if (max_length < (j-i+1)) 
                {
                    max_length = j-i+1;
                    *start = i;
                    *end = j;
                }
            }
            //cout << sum << " " << *start << " " << *end << endl;
        }       
    }
    return max_length;
//Time Complexity: O(N^2) - first loop (N) * inner loop(N)
//Space Complexity: O(1) - No extra space used
}

/* Efficient Approach - we use hashing with key as sum and value as current_index
So when current_sum is not equal to give sum, 
we try to look for entry in hash table which can make current_sum = given_sum
if found match compare length with max_length */
int bestWay(int* arr, int n, int k, int* start, int* end)
{
    unordered_map<int, int> hash_table;
    int sum = 0, max_length = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == k)
        {
            max_length = i+1;
            *start = 0;
            *end = i;
        }

        if (hash_table.find(sum) == hash_table.end())
            hash_table[sum] = i;   //store current sum in hash_table if not found

        if (hash_table.find(sum-k) != hash_table.end())
        {
            /* if hash_table has a entry which makes current sum == given_sum,
            then calculate new subarray length and compare max_length
            example - current subarray {2, 3, -1, 5, 4, -2} and given_sum = 9
            curr_sum = 11 but if u remove first element we get 9,
            So we check in hash_table for sum(11-9) i.e, hash_table(sum = 2)
            and first element is returned, So now we assume a subarray after this index to current index
            which gives us {3, -1, 5, 4, -2}  whose sum is 9 */
            if (max_length < (i-hash_table[sum-k]+1))
            {
                max_length = i-hash_table[sum-k];
                *start = hash_table[sum-k]+1;
                *end = i;
            }
        }
        //cout << sum << " " << *start << " " << *end << endl;
    }
    return max_length;
//Time Complexity: O(N) - one loop (N)
//Space Complexity: O(N) - hash_table for N elements
}

//Efficient Space Approach - Use 2 pointers to adjust subarray whose sum = given_sum
//NOTE - doesn't work with negative numbers
int minimal_space(int* arr, int n, int k, int* start, int* end)
{
    int max_length = INT_MIN, i = 0, j = 0, sum = 0;

    while (j < n)
    {
        sum += arr[j];
        if (sum == k)
        {
            // length of current subarray is diff of i and j
            if (max_length < (j-i+1)) 
            {
                max_length = j-i+1;
                *start = i;
                *end = j;
            }
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }

            if (sum == k)
            {
                // length of current subarray is diff of i and j
                if (max_length < (j-i+1)) 
                {
                    max_length = j-i+1;
                    *start = i;
                    *end = j;
                }
            }
        }
        
        j++; //next iteration
        //cout << sum << " " << i << " " << j << endl;      
    }
    return max_length;
//Time Complexity: O(N) - one loop(N)
//Space Complexity: O(1) - No extra space used
}

int main()
{
    int arr[] = {2, 3, -1, 5, 4, -2, 6, -3, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int find_sum = 9, start = 0, end = arr_size;

    int max_len_BF = bruteforce(arr, arr_size, find_sum, &start, &end);
    cout << "Largest_Subarray_Bruteforce - " << max_len_BF << endl;
    for (int i = start; i <= end; i++)
        cout << arr[i] << " ";
    cout << endl << "=================================\n";

    start = 0; end = arr_size;
    int best_len = bestWay(arr, arr_size, find_sum, &start, &end);
    cout << "Largest_Subarray - " << best_len << endl;
    for (int i = start; i <= end; i++)
        cout << arr[i] << " ";
    cout << endl << "=================================\n";

    int pos_arr[] = {6, 2, 3, 1, 5, 4, 2, 6, 3, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    find_sum = 17, start = 0, end = size;
    int max_len = minimal_space(pos_arr, size, find_sum, &start, &end);
    cout << "Largest_Subarray_min_space - " << max_len << endl;
    for (int i = start; i <= end; i++)
        cout << pos_arr[i] << " ";
    cout << endl << "=================================\n";

    return 0;
}