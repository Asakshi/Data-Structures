//

#include <iostream>

void reverseArrar(int arr[], int size)
{
    int first_indxe = 0;
    int last_index = size-1;
     while (first_index < last_index)
    {
        int temp;
        temp = a[first_index];
        a[first_index] = a[last_index];
        a[last_index] = temp;
        first_index++;
        last_index--;
    }
}

void printArray(int arr[])
{
    for (int ele : arr)
    {
        std::cout << ele << " ";
    }
    
    std::cout<<'\n';
}

//Driver function
int main()
{
    int arr[] = { 1,2,3,4,5,6 };

    std::cout << "Before Reversing Array: ";
    printArray(arr);
    
    int size = (sizeof(arr) / sizeof(arr[0]));
    reverseArray(arr, size);
    
    std::cout << "\nAfter Reversing Array:";
    printArray(arr);
    
   return 0;
}

