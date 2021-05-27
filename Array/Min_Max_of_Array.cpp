#include <iostream>
#include<utility>

//Pair of minimum number and maximum number is
//is returned by followinf function by using pair container
std::pair<int,int> min_max_number(int arr[], int size)
{
    std::pair<int, int> min_max;

    int min_num;
    int max_num;

    //If array contains only one element ,then first element is both
    //maximum and minimum
    if (size == 1)
    {
        min_max.first = arr[0];
        min_max.second = arr[0];
    }

    //Default values of min and max is defined by
    //first two elements of array
    if (arr[0] < arr[1])
    {
        min_num = arr[0];
        max_num = arr[1];
    }
    else
    {
        min_num = arr[1];
        max_num = arr[0];
    }

    for (int i = 2; i < size; i++)
    {
        if (arr[i] < min_num)
            min_num = arr[i];
        else if (arr[i] > max_num)
            max_num = arr[i];
    }

    min_max.first = min_num;
    min_max.second = max_num;

    return min_max;
}

//Driver function
int main()
{
    int arr[] = { 1000,11,445,1,330,3000 };

    int size = sizeof(arr) / sizeof(arr[0]);

    std::pair<int, int> min_max;
    min_max = min_max_number(arr, size);

    std::cout << "Minimun number = " << min_max.first <<
        " \nMaximum number = " << min_max.second << '\n';
    return 0;
}


