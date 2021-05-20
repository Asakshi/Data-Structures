#include<iostream>
#include<algorithm>

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
    std::reverse(arr, arr+size);
    
    std::cout << "\nAfter Reversing Array:";
    printArray(arr);
    
   return 0;
}
