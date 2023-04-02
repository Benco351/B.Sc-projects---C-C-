#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define SIZE 100
typedef struct treeNode
{
    
    unsigned int data;
    struct treeNode* left;
    struct treeNode* right;
}  TreeNode;

typedef struct tree
{
    TreeNode* root;
    int CountNodes;
  
}Tree;

TreeNode* BuildTreeFromArrayRec(int* arr, int start, int  end, int* countNodes);
void CheckMem(void* ptr);
TreeNode* createNewTreeNode(int data, TreeNode* left, TreeNode* right);
Tree BuildTreeFromArray(int* arr, int  size);
void printTreeInorderRec(TreeNode* root);
void printTreeInorder(Tree tr);
void freeTree(Tree tr);
void freeTreeRec(TreeNode* root);
void printByLevels(Tree tr);
void printByLevelsRec(TreeNode* root, int NodesCount);
TreeNode* deQueue(TreeNode** queue, int* front, int nodesCount);
void enQueue(TreeNode** queue, int* rear,
    TreeNode* new_node);
TreeNode** createQueue(int* front, int* rear);