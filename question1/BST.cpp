#include "BST.h"

void BST::insert(InputNode* newValue)
{
	//IF the root is null(tree is empty), then make this student the root
	if (root == NULL)
	{
		root = newValue;
		return; //exit early we are done
	}

	//some pointers to help us place new studenht
	InputNode* current = root;//current node we are pointing at
	InputNode* parent = NULL; //parent of current(one above)

	while (true)//infinite loop
	{
		//lets keep track of where we were before moving
		parent = current;
		//LEFT OR RIGHT
		//if new students student ID is les then student at current then go down left
		if (newValue->inValue < current->inValue)
		{
			//go left because its less then
			current = current->leftChild;
			//if current is null we found empty slot for insertion
			{
				if (current == NULL)
				{
					//stick student here
					parent->leftChild = newValue;
					return;//done, leave loop
				}
			}
		}
		else
		{
			//go down right path
			current = current->rightChild;
			//if current is null insert
			if (current == NULL)
			{
				parent->rightChild = newValue;
				return; // we are done here
			}
		}
	}
}

void BST::show(InputNode* p, string outputFileName)
{
	//output file declaration
	ofstream outputFile;

	//Base Case
	if (root == NULL) return;

	//create an empty queue for level order traversal
	queue<InputLevelNode> q;

	//Enqueue and initialize height
	q.push(InputLevelNode(root, 0));

	int previousOutputLevel = - 1;
		//open the file in append mode
		outputFile.open(outputFileName, fstream::app);

	while (q.empty() == false)
	{
		//print front of the queue and remove it
		InputLevelNode node = q.front();
		if (node.level != previousOutputLevel)
		{
			outputFile << endl;
			outputFile << node.level << "- ";
			previousOutputLevel = node.level;
		}
		outputFile << node.input->inValue << " ";
		q.pop();

		/* Enqueue left child*/
		if (node.input->leftChild != NULL)
			q.push(InputLevelNode(node.input->leftChild, node.level + 1));

		/* Enqueue right child*/
		if (node.input->rightChild != NULL)
			q.push(InputLevelNode(node.input->rightChild, node.level + 1));
	}
	outputFile.close(); //close the file after using it
}
