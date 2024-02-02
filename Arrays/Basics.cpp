#include<iostream>
using namespace std;

//Pass array as paramter
void printArray(int* arr, int n)
{
    int i;
 
    printf("Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    cout << endl;
}

//Return array using dynamically allocated array
int* fun_using_new()
{
    int* arr = new int[100]; // allocate array
 
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
 
    return arr;
}

//Return array using static array
int* fun_using_static()
{
    //Static Array - Available until end of program
    static int arr[100];

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    return arr;
}

int main()
{
    int num5[] = {1, 2, 3, 4, 5};  // initialize array
    int num5_size = sizeof(num5) / sizeof(num5[0]);  // calculate array size
    printArray(num5, num5_size);   // print array

    int* ptr = fun_using_new();
    cout << "Using NEW: " << ptr[0] << " " << ptr[1] << " " << ptr[2] << endl;
    delete[] ptr;  // allocated memory must be deleted

    int* ptr_2_static = fun_using_static();
    cout << "Using STATIC: " << ptr_2_static[0] << " " << ptr_2_static[1] << endl;

    return 0;
}