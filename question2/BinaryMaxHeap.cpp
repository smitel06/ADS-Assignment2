#include "BinaryMaxHeap.h"

int BinaryMaxHeap::leftChildIndex(int parent)
{
    int leftIndex = 2 * parent + 1;
    if (leftIndex < heap.size())
        return leftIndex;
    else
        return -1;
}

int BinaryMaxHeap::rightChildIndex(int parent)
{
    int rightIndex = 2 * parent + 2;
    if (rightIndex < heap.size())
        return rightIndex;
    else
        return -1;
}

int BinaryMaxHeap::parentIndex(int child)
{
    int parent = (child - 1) / 2;
    if (child == 0)
        return -1;
    else
        return parent;
}

//after inserting, we heapify up from where that new inserted value ended up;
//compares current node to parent and swaps larger to top
//recursive means each swap calls heapify up on the next level
void BinaryMaxHeap::heapifyup(int index)
{
    //if index is not the root
    //AND parent index within heap bounds
    //AND current nodes inValue < parent nodes inValue
    if (index >= 0 && parentIndex(index) >= 0 && heap[index].inValue > heap[parentIndex(index)].inValue)
    {
        //if so swap values between current and parent
        input temp = heap[index];
        heap[index] = heap[parentIndex(index)];
        heap[parentIndex(index)] = temp;
        //since we swapped run heapifyup again
        heapifyup(parentIndex(index));
    }
}

//down is left efficient to up because we have to compare both children first
//usually called when root is destroyed
//recursive keeps swapping until complete
void BinaryMaxHeap::heapifydown(int index)
{
    //get left and right children indexes
    int childL = leftChildIndex(index);
    int childR = rightChildIndex(index);
    //child variable respresenting path we will compare down
    int childIndex = childL;
    //if childL and childR is not equal to -1
    //and right child inValue is less then lefts
    if (childL >= 0 && childR >= 0 && heap[childR].inValue > heap[childL].inValue)
    {
        //make right child focus instead of left
        childIndex = childR;
    }

    //If childIndex is not root and is not negative 1
    //and currents nodes biggerr then childs node
    if (childIndex > 0 && heap[index].inValue < heap[childIndex].inValue)
    {
        //swap current with child
        input temp = heap[index];
        heap[index] = heap[childIndex];
        heap[childIndex] = temp;
        //recurse further down
        heapifydown(childIndex);
    }

}

//inserts at the lowest next free spot keeping the tree balanced
void BinaryMaxHeap::Insert(input element)
{
    heap.push_back(element);
    heapifyup(heap.size() - 1);
}

void BinaryMaxHeap::DeleteMax()
{
    //cant delete if heap is empty
    if (heap.size() == 0)
    {
        cout << "Heap empty!" << endl;
        return;
    }
    //copy the value in last element into root
    heap[0] = heap[heap.size() - 1];
    //delete last element
    heap.pop_back();
    //then heapify down from root
    heapifydown(0);
    cout << "Root input deleted" << endl;
}

//get root input node from heap tree structure
input* BinaryMaxHeap::ExtractMax()
{
    if (heap.size() == 0)
        return NULL;
    else
        return &(heap.front());
}

void BinaryMaxHeap::writeHeap(string filename)
{
    ofstream outputFile;
    //open the file in append mode
    outputFile.open(filename, fstream::app);
    for (input p : heap)
    {
        outputFile << " " << p.inValue << " ";
    }
    outputFile << endl;
}

int BinaryMaxHeap::Size()
{
    return heap.size();
}
