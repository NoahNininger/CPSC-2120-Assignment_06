# include <iostream>
# include "minHeap.h"

using namespace std;

void minHeap::siftUp(int pos)
{
    int parent = (pos-1) / 2;
    int child = pos;

 // compares children and parents and swaps them
    while (child != 0 && heap[parent] > heap[child])
    {
        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        child = parent;
        parent = (parent - 1) / 2;  // new parent
    }
}

void minHeap::siftDown(int pos)
{
    int parent = pos;
    int leftChild = 2 * parent + 1;
    int rightChild = 2 * parent + 2;
    int childToSwap = -1;

 // left child
    if (leftChild < (int)heap.size() && heap[leftChild] < heap[parent])
        { childToSwap = leftChild; }
 // right child
    if (rightChild < (int)heap.size() && heap[rightChild] < heap[parent])
    {
        if (childToSwap == -1) 
            { childToSwap = rightChild; }
        else        // takes the smallest child
        {
            if (heap[rightChild] < heap[leftChild])
                { childToSwap = rightChild; }
        }
    }

    if (childToSwap == -1)      // if there is no need to swap
        { return; }

 // swap parent with selected child
    int temp = heap[parent];
    heap[parent] = heap[childToSwap];
    heap[childToSwap] = temp;

    siftDown(childToSwap);      // recursion
}

minHeap::minHeap(vector<int> data)
{
    heap.resize(0); // clear heap
    for(int i = 0; i < (int)data.size(); i++)     // fill the vector
        { heap.push_back(data[i]); }
    for(int i = heap.size() - 1; i >= 0; i--)
        { siftDown(i); }
}

void minHeap::insert(int value)
{
    heap.push_back(value);
    int pos = heap.size() - 1;
    siftUp(pos);
}

int minHeap::removeMin()
{
    if(heap.size()== 0)     // if heap is empty
        { return -1; }

 // swap first and last element, and then remove the element
    int temp = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap[heap.size() - 1] = temp;
    heap.pop_back();

    siftDown(0);

    return temp;
}
