#include "Header.h"

//printing tree by level in O(n) complexity
void printByLevels(Tree tr)
{
    printByLevelsRec(tr.root,tr.CountNodes);
}
void printByLevelsRec(TreeNode* root,int NodesCount)
{
    int rear, front;
    TreeNode** queue = createQueue(&front, &rear); // building a queue
    TreeNode* temp_node = root;

    while (temp_node !=NULL) {
        printf("%d ", temp_node->data);

        /*push left child */
        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);

        /*push right child */
        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);

        /*pull node and make it temp_node for next iteration*/
        temp_node = deQueue(queue, &front, NodesCount);
    }
}

// Function to release the tree
void freeTree(Tree tr)
{
    freeTreeRec(tr.root);
}
//Recursively free the tree nodes
void freeTreeRec(TreeNode* root)
{
    if (root == NULL)
        return;
    else
    {
        freeTreeRec(root->left);
        freeTreeRec(root->right);
        free(root);
    }
}
//Printing the tree in inorder
void printTreeInorder(Tree tr)
{
    printTreeInorderRec(tr.root);
    printf("\n");
}
//Recursively printing the tree in inorder manner
void printTreeInorderRec(TreeNode* root)
{
    if (root == NULL)
        return;
    else
    {
        printTreeInorderRec(root->left);
        printf("%d ", root->data);
        printTreeInorderRec(root->right);
    }
}
//Create new node in the tree
TreeNode* createNewTreeNode(int data, TreeNode* left, TreeNode* right)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}
//Build the tree from the given array like in question 1
Tree BuildTreeFromArray(int* arr, int  size)
{
    Tree tr;
    int start = 0;
    int end = size;
    int countNodes = 0;
    tr.root = BuildTreeFromArrayRec(arr, start, end,&countNodes);
    tr.CountNodes = countNodes;
    return tr;

}

//recursively build the tree from an array and update the number of nodes in the tree parameter
TreeNode* BuildTreeFromArrayRec(int* arr, int start, int  end,int* countNodes)
{
    if (start > end)
    {
        return NULL;
    }
    else
    {

        int mid = (start + end) / 2;
        TreeNode* right, * left, * root;
        left = BuildTreeFromArrayRec(arr, start, mid - 1, countNodes);
        right = BuildTreeFromArrayRec(arr, mid + 1, end, countNodes);
        root = (arr[mid] != -1) ? createNewTreeNode(arr[mid], left, right)  : NULL;
        if (root != NULL)
        {
            *countNodes = *countNodes + 1;
        }
        return root;
    }
}

void CheckMem(void* ptr)
{
    if (ptr == NULL)
    {
        exit(EXIT_FAILURE);
    }
}
//Queue functions:

//creating an array of treeNodes 
TreeNode** createQueue(int* front, int* rear)
{
    TreeNode** queue = (TreeNode**)malloc(
        sizeof(TreeNode*) * SIZE);

    *front = *rear = 0;
    return queue;
}

//Function to push node to the TreeNode queue(array)
void enQueue(TreeNode** queue, int* rear,
    TreeNode* new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}
//Pull the last element from the array of treenodes
TreeNode* deQueue(TreeNode** queue, int* front,int nodesCount)
{
    (*front)++;
    if (nodesCount-1 > *front)
    {
        return queue[*front - 1];

    }
    return NULL;
}