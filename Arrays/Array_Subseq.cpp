#include<bits/stdc++.h>
using namespace std;

void print_Subsequences(char* arr, int arr_size)
{
    //Total number of subsequences is 2**n - 1
    int max_seq = pow(2, arr_size);

    for (int bit_num = 1; bit_num < max_seq; bit_num++)
    {
        /* Here bit_num is respesenting 0001 to 1111,
           Now we need to match '1' of bit_num to arr index 
           i.e, if bit_num is 0001, we print here {a}
                if bit_num is 0100, we print here {c}
                if bit_num is 0101, we print here {a c}... */
        cout << "{ ";
        for (int idx = 0; idx < arr_size; idx++)
        {
            /* we shift 1(0001) to left with reference to index
            i.e, for idx 2, we refer it as 0100 */
            if (bit_num & (1<<idx)) cout << arr[idx] << " ";         
        }
        cout << "}\n";
    }
//Time Complexity: O((2^N) * N) - first loop (2^N) * inner loop(N)
//Space Complexity: O(1) - No extra space used
}

int main()
{
    int n = 4;
    char arr[n] = {'a', 'b', 'c', 'd'}; 
    print_Subsequences(arr, n);

    return 0;
}