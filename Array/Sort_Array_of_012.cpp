#include <iostream>

void swap(int* a, int* b);


void sort012(int arr[], int n)
{
    //arr = [0,1,0,2,1,1,0,2,2]
    //count0 to tract 0
    int count0 = {};

    //Move all zeros at starting of array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            swap(&arr[i], &arr[count0]);
            count0++;
        }
    }

    //arr = [0,0,0,2,1,1,1,2,2]

    //count1 to tract 1
    int count1 = count0 ;

    //Then place all 1 after 0
    for (int i = count0 ; i < n; i++)
    {
        if (arr[i] == 1)
        {
            swap(&arr[i], &arr[count1]);
            count1++;
        }
    }
    //arr = [0,0,0,1,1,1,2,2,2]

    //All zeros are moved to their position
    //No need to perform operation for 2s.

}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Driver code
int main()
{
    int arr[] = { 0,1,0,2,1,1,0,2,2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Before: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    sort012(arr, n);

    std::cout << "After: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
}

//Output
//Before: 0 1 0 2 1 1 0 2 2
//After: 0 0 0 1 1 1 2 2 2

