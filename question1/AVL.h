#pragma once
#include "BST.h"

//AVL is self balancing binary search tree
class AVL : public BST
{
public:
	bool displayRotations = true;

	//works out height of sub tree(branch)
	int height(InputNode* node);

	//difference between left and right subtrees
	int difference(InputNode* node);

	//ROTATIONS
	//returns new parent of subtree
	//parameter: current parent of subtree
	//right branch, right child
	InputNode* RRrotation(InputNode* parent);
	//left branch, left child
	InputNode* LLrotation(InputNode* parent);
	//left branch, right child
	InputNode* LRrotation(InputNode* parent);
	//right branch, left child
	InputNode* RLrotation(InputNode* parent);

	//BALANCE
	//balances a tree structure where parent is the top node
	//returns new parent after balancing
	InputNode* balance(InputNode* parent);

	//INSERT
	//recursive insert that considers parent a sub tree
	//also balances itself and returns new root node
	InputNode* insertAVL(InputNode* parent, InputNode* newValue);

	//overriding insert from parent
	void insert(InputNode* newValue);
};

