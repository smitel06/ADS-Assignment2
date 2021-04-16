#include <iostream>
#include <string>
#include "BST.h"
#include "AVL.h"
#include <fstream>
#include <vector>


//ADS ASSIGNMENT 2 BY ELIAH SMITH
//GIT REPOSITORY https://github.com/smitel06/ADS-Assessment-2


using namespace std;

void main()
{
	//declarations of variables
	int numsToInsert; //number of values we are going to insert into tree
	AVL avlTree; //AVL tree of numbers from input file 

	//start of program open input file for instructions
	ifstream inputFile("input-q1a2.txt");
	//read first line and put into numbers to insert
	inputFile >> numsToInsert; //this will be used to create for loop with vector to hold our values

	for (int i = 1; i <= numsToInsert; i++)
	{
		int temp;
		inputFile >> temp; //places value in temporary int variable
		avlTree.insert(new InputNode(temp)); //inserts value pulled from input file
	}
	inputFile.close();//close the file we are done reading the input file


	//output to file
	string filename = "output-q1-a2.txt";//file name to insert into functions
	ofstream outputFile;
	outputFile.open(filename, std::ofstream::out | std::ofstream::trunc); //cleans file out before writing to it 
	outputFile.close();//closes file
	avlTree.show(avlTree.root, filename);

	system("pause");
}