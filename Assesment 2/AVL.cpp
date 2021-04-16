#include "AVL.h"


//using recursion we keep looking down and pass final height values up
int AVL::height(InputNode* node)
{
    int h = 0;

    //helps break recursion cycle by testing for null
    if (node != NULL)
    {
        int leftH = height(node->leftChild);
        int rightH = height(node->rightChild);
        //max gets bigger of the two
        int maxH = max(leftH, rightH);

        h = maxH + 1;
    }
    return h;
}

int AVL::difference(InputNode* node)
{
    //if empty tree its balanced
    if (node == NULL)
        return 0;

    int leftH = height(node->leftChild);
    int rightH = height(node->rightChild);
    int balanceFactor = leftH - rightH;

    return balanceFactor;
}

InputNode* AVL::RRrotation(InputNode* parent)
{
    InputNode* temp = parent->rightChild;
    parent->rightChild = temp->leftChild;
    temp->leftChild = parent;
    if (displayRotations)
    {
        cout << "RR rotation on " << endl;
    }
    return temp;
}

InputNode* AVL::LLrotation(InputNode* parent)
{
    InputNode* temp = parent->leftChild;
    parent->leftChild = temp->rightChild;
    temp->rightChild = parent;
    if (displayRotations)
    {
        cout << "LL rotation on " << parent->inValue << endl;
    }
    return temp;
}

//needs two rotations 
//first rotation rotates bottom two nodes which turns it into a right right
//use RRrotation for second rotation
InputNode* AVL::LRrotation(InputNode* parent)
{
    InputNode* temp = parent->leftChild;
    parent->leftChild = RRrotation(temp);
    if (displayRotations)
    {
        cout << "LR rotation on " << parent->inValue << endl;
    }
    return LLrotation(parent);
}

//mirrored version of LRrotation
InputNode* AVL::RLrotation(InputNode* parent)
{
    InputNode* temp = parent->rightChild;
    parent->rightChild = LLrotation(temp);
    if (displayRotations)
    {
        cout << "RL rotation on " << endl;
    }
    return RRrotation(parent);
}

InputNode* AVL::balance(InputNode* parent)
{
    //get balance factor
    int balanceFactor = difference(parent);

    //If balance factor no -1, 0 or 1 workout how to balance
    if (balanceFactor > 1)
    {
        //left side is heavy
        if (difference(parent->leftChild) > 0)
        {
            //left child unbalanced
            parent = LLrotation(parent);
        }
        else
        {
            //otherwise right child is unbalanced
            parent = LRrotation(parent);
        }

    }
    else if (balanceFactor < -1)
    {
        //right branch is heavier
        if (difference(parent->rightChild) > 0)
        {
            //Left child heavy
            parent = RLrotation(parent);
        }
        else
        {
            //right child heavy
            parent = RRrotation(parent);
        }
    }


    //always return parent
    return parent;
}

InputNode* AVL::insertAVL(InputNode* parent, InputNode* newValue)
{
    //if sub tree empty this becomes the parent
    if (parent == NULL)
    {
        parent = newValue;
        return parent;
    }

    //parent not null so we havent found an empty slot for new student
    //go left or right branch path
    if (newValue->inValue < parent->inValue)
    {
        parent->leftChild = insertAVL(parent->leftChild, newValue);
        parent = balance(parent);
    }
    else//assume ID is greater or equal to parents ID
    {
        parent->rightChild = insertAVL(parent->rightChild, newValue);
        parent = balance(parent);
    }


}

void AVL::insert(InputNode* newValue)
{
    cout << "Inserting " << newValue->inValue << endl;
    root = insertAVL(root, newValue);
    cout << endl;
}
