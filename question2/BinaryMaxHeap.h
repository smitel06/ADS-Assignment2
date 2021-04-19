#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include "input.h"
#include <fstream>

class BinaryMaxHeap
{
public:
	vector<input> heap;
	int leftChildIndex(int parent);
	int rightChildIndex(int parent);
	int parentIndex(int child);

	void heapifyup(int index);
	void heapifydown(int index);

	void Insert(input element);
	void DeleteMax();
	input* ExtractMax();
	void writeHeap(string filename);
	int Size();


};

