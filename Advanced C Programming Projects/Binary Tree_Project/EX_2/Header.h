#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define FALSE 0

#define TRUE 1

#define SIZE 100

typedef int BOOL;
typedef struct treeNode
{
    char data;
    struct treeNode* left;
    struct treeNode* right;
    struct treeNode* next;
}  TreeNode;

typedef struct tree
{
    TreeNode* root;
}Tree;


void CheckMem(void* ptr);
TreeNode* createNewTreeNode(int data, TreeNode* left, TreeNode* right, TreeNode* next);
void freeTree(Tree tr);
void freeTreeRec(TreeNode* root);
char* postfixCreator(char* str);
TreeNode* buildExpressionTreeIter(char* postfix, int size);
BOOL buildExpressionTree(char str[], Tree* tr);
void push2(TreeNode* x);
TreeNode* pop2();
double calcExpression(Tree tr);
bool ifOk(char* postfix, int size);
double calcExpressionCall(TreeNode* root);
double calcExpression(Tree tr);
void push(char ch);
char pop();
int priority(char ch);
bool isOperator(char c);
void freeTree(Tree tr);
void freeTreeRec(TreeNode* root);