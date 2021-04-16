#pragma once
#include "InputNode.h"
#include <fstream> //include to allow filestreaming on bst.cpp
#include <queue>


//Helper class for breadth first output
class InputLevelNode
{
public:
	InputNode *input;
	int level;

	//constructor
	InputLevelNode(InputNode* input, int level)
	{
		this->input = input;
		this->level = level;
	}
};

//Binary search Tree
//root node sort of acting as center
//everything smaller then root stored on left
//everything else to the right

class BST
{
public:
	InputNode* root = NULL;
	virtual void insert(InputNode* newStudent);
	InputNode* search(int inValue, bool showSearchPath = false);


	//recursive traversal functions
	void inOrderTraversal(InputNode* current);
	void preOrderTraversal(InputNode* current);
	void postOrderTraversal(InputNode* current);
	void inOrderOutputFile(InputNode* current, string outputFileName);

	//show function
	void show(InputNode* p, string outputFileName); 

};

