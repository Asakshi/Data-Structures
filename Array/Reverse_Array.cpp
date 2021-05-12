//

#include <bits/stdc++.h>

int main()
{
    int a[] = { 1,2,3,4,5,6 };

    std::cout << "Before: ";
    for (int ele : a)
    {
        std::cout << ele << " ";
    }

    int first_index = 0;
    int last_index = (sizeof(a) / sizeof(a[0])) - 1;

    while (first_index < last_index)
    {
        int temp;
        temp = a[first_index];
        a[first_index] = a[last_index];
        a[last_index] = temp;
        first_index++;
        last_index--;
    }

    std::cout << "\nAfter: ";
    for (int ele : a)
    {
        std::cout << ele << " ";
    }
}

