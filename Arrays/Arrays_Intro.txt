Arrays are 
 - Collecation of items of same data type at contiguous locations.
 - Stored in heap in JVM.

Array traversal - array[index]  //index starts with 0
Time complexity - O(n)     //go through all elements
Auxilary space - O(1)      //no extra space needed

Syntax to pass array to functions:
int func(int array[], int size)
int func(int* array[], int size)

Syntax to return array from functions:
int* func() { int arr = new arr[10] }
int* func() { static int arr[10] }
struct func() { struct x }    //create a struct with array 

For a array of size n, 
there are n*(n+1)/2 non-empty subarrays.
there are (2**n – 1) non-empty sub-sequences.