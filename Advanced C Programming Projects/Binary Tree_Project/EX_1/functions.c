#include "Header.h"
//free the tree memory
void freeTree(Tree tr)
{
    freeTreeRec(tr.root);
}

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
//Printing the tree in inorder manner
void printTreeInorder(Tree tr)
{
    printTreeInorderRec(tr.root);
    printf("\n");
}

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

//Create New node in the tree
TreeNode* createNewTreeNode(int data, TreeNode* left, TreeNode* right)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}
//Question 1 BuildTreeFromArray function call to a recursive function
Tree BuildTreeFromArray(int* arr, int  size)
{
    Tree tr;
    int start = 0;
    int end = size;
    tr.root = BuildTreeFromArrayRec(arr, start, end,size);
    return tr;

}

//Recursive function that build the tree from a given array
TreeNode* BuildTreeFromArrayRec(int* arr, int start, int  end,int size)
{
    if (start > end)
    {
        return NULL;
    }
    else
    {

        int mid = (start + end) / 2;
        TreeNode* right, * left, * root;
        left = BuildTreeFromArrayRec(arr, start, mid - 1,size);
        right = BuildTreeFromArrayRec(arr, mid + 1, end,size);
        root = (arr[mid] != -1 && mid != size) ? createNewTreeNode(arr[mid], left, right) : NULL;

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