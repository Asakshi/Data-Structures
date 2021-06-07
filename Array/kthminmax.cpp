#include <iostream>
#include <utility>

class MaxHeap
{
private:
    int capacity;
    int heap_size;
    int* harray;
public:
    MaxHeap(int[], int);
    int getMax();
    void maxHeapify(int i);
    void extractMax();
};

MaxHeap::MaxHeap(int a[], int size)
{
    heap_size = size;
    harray = a;

    /*Hepifying the Tree from (level-1)th level
    *
    * 13, 10,5,3,4,6,1
    *              13
    *             /  \
    *           10    5 ---> Second last level
    *          / \   / \
    *         3   4  6  1
    */
    int i = heap_size / 2 - 1; //index of node from hepify function should start
    
    while (i >= 0)
    {
        maxHeapify(i);
        i--;
    }
}
int MaxHeap::getMax()
{
    if (heap_size < 1)
    {
        return INT_MAX;
    }
    if (heap_size >= 1)
    {
        return harray[0];
    }
}

int parent(int i)
{
    return (i - 1) / 2;
}
int leftchild(int i)
{
    return (2 * i + 1);
}
int rightchild(int i)
{
    return (2 * i + 2);
}
void swap(int* p, int* q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void MaxHeap::maxHeapify(int i)
{
    int l = leftchild(i);
    int r = rightchild(i);
    int largest = i;

    if ((l < heap_size) && (harray[l] > harray[i]))
    {
        largest = l;
    }
    if ((r < heap_size) && (harray[r] > harray[largest]))
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(&harray[largest], &harray[i]);
        maxHeapify(largest);
    }
}


void MaxHeap::extractMax()
{
    if (heap_size < 1)
    {
        std::cout << "Heap is Empty";
        return;
    }
    if (heap_size == 1)
    {
        heap_size--;
    }

    int root = harray[0];
    harray[0] = harray[heap_size - 1];
    heap_size--;

    maxHeapify(0);
}

class MinHeap
{
private:
    int capacity;
    int heap_size;
    int* harray;
public:
    MinHeap(int[], int);
    int getMin();
    void minHeapify(int i);
    int extractMin();
};

MinHeap::MinHeap(int a[], int size)
{
    heap_size = size;
    harray = a;
    int i = heap_size / 2 - 1;
    while (i >= 0)
    {
        minHeapify(i);
        i--;
    }
}
int MinHeap::getMin()
{
    if (heap_size < 1)
    {
        return INT_MAX;
    }
    if (heap_size >= 1)
    {
        return harray[0];
    }
}


void MinHeap::minHeapify(int i)
{
    int l = leftchild(i);
    int r = rightchild(i);
    int smallest = i;

    if ((l < heap_size) && (harray[l] < harray[i]))
    {
        smallest = l;
    }
    if ((r < heap_size) && (harray[r] < harray[smallest]))
    {
        smallest = r;
    }

    if (smallest != i)
    {
        swap(&harray[smallest], &harray[i]);
        minHeapify(smallest);
    }
}


int MinHeap::extractMin()
{
    if (heap_size < 1)
    {
        return INT_MAX;
    }
    if (heap_size == 1)
    {
        heap_size--;
    }

    int root = harray[0];
    harray[0] = harray[heap_size - 1];
    heap_size--;

    minHeapify(0);
}

std::pair<int, int> KthMinMax(int arr[], int size, int k)
{
    int max;
    int min;

    //Kth maximum element
    MaxHeap kthmax(arr, size);
    
    for (int i = 0; i < k - 1; i++)
    {
        kthmax.extractMax();
    }

    max = kthmax.getMax();

    //Kth minimum element
    MinHeap kthmin(arr, size);
    for (int i = 0; i < k - 1; i++)
    {
        kthmin.extractMin();
    }

    min = kthmin.getMin();

    //pair of kth max and kth min element
    std::pair<int, int> kthMinMaxPair;
    kthMinMaxPair.first = min;
    kthMinMaxPair.second = max;

    return kthMinMaxPair;

}

int main()
{
    int arr[] = { 13, 10,5,3,4,6,1 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int k = 3;//To find 3rd max and min element

    std::pair<int, int> kthMinMaxPair;

    kthMinMaxPair = KthMinMax(arr, size, k);

    std::cout << k << "rd min element is " << kthMinMaxPair.first;
    std::cout << '\n';
    std::cout << k << "rd max element is " << kthMinMaxPair.second;

}

/*
3rd min element is 3
3rd max element is 6
*/
