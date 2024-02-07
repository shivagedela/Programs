#include<bits/stdc++.h>
using namespace std;

/*** Problem - Given array of size n and a number k, find all elements that appear > n/k times ***/

// Bruteforce - Sort all the elements and count each element appearance, if it is > n/k, then print
int bruteforce(int arr[], int n, int k, int* sol)
{
    sort(arr, arr+n);   //sort the array in ascending order

    int count = 1, prev = arr[0], j = 0;
    for (int i = 1; i < n; i++)
    {
        if(prev == arr[i]) count++;
        else if(count > (n/k))
        {
            sol[j++] = prev;
            prev = arr[i];
            count = 1;
        }
        else
        {
            prev = arr[i];
            count = 1;
        }
        //cout << prev << " " << count << endl;
    }

    if (count > (n/k))
        sol[j++] = prev;

    return j;
//Time Complexity: O(NlogN) - sorting of N elements
//Space Complexity: O(1) - No extra space used  
}

/* Efficient Approach - we use hashing with key as element and value as its count 
and if count of an element > n/k, print that element*/
vector<int> bestWay(int* arr, int n, int k)
{
    unordered_map<int, int> counter;
    vector<int> sol;

    /* For every element, if it is present in hash_map then increase its count */
    for (int i = 0; i < n; i++)
	{
		if (counter.find(arr[i]) != counter.end())   //element is available
			counter[arr[i]] += 1;
		else
			counter[arr[i]] = 1;
	}

    unordered_map<int, int>::iterator it;
    for ( it = counter.begin(); it != counter.end(); it++)
    {
        //cout << "Key - " << it->first << " Value - " << it->second << endl;
        if (it->second > (n/k))
            sol.push_back(it->first);
    }
    return sol;
//Time Complexity: O(N) - one loop(N)
//Space Complexity: O(N) - hash_table for N elements
}

int main()
{
    int arr[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int k = 4;

    int sol_BF[100];
    int j = bruteforce(arr, arr_size, k, sol_BF);
    for (int i = 0; i < j; i++)
        cout << sol_BF[i] << " ";
    
    cout << "\n===================================\n";
    vector<int> best_sol = bestWay(arr, arr_size, k);
    for (auto ele : best_sol)
        cout << ele << " ";

    return 0;
}