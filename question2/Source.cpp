#include <iostream>
#include <string>
#include "BinaryMaxHeap.h"
#include <fstream>
using namespace std;

void main()
{
	int numsToInsert; //first line in file will be stored heree it is the number of values
	BinaryMaxHeap numberHeap;

	//start program here
	//open input value for variables to insert
	ifstream inputFile("input-q2a2.txt");
	//store the first value in variable
	inputFile >> numsToInsert;
	//create variable for output file name
	string filename = "output-q2-a2.txt";
	//wipe file so we can overwrite
	ofstream outputFile;
	outputFile.open(filename, std::ofstream::out | std::ofstream::trunc); //cleans file out before writing to it 
	outputFile.close();//closes file
	for (int i = 1; i <= numsToInsert; i++)
	{
		//store the numbers in the file in a temp before putting into heap
		int temp;
		numberHeap.writeHeap(filename);
		inputFile >> temp;
		numberHeap.Insert(input(temp));
		numberHeap.writeHeap(filename);
	}
	//close input file
	inputFile.close();
	
	system("pause");
}