
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define FALSE 0
#define LEFT  0
#define RIGHT 1
#define SIZE 100



typedef struct listNode {
    int data;
    struct listNode* next;
} ListNode;

typedef struct list {
    ListNode* head;
    ListNode* tail;
} List;

typedef struct  treeNode {
    int data;
    struct treeNode* parent;
    struct treeNode* left;
    struct treeNode* right;
} TreeNode;

typedef struct tree {
    TreeNode* root;
    List leafList;   /*רשימה מקושרת של כל העלים בעץ*/
} Tree;
void insertDataToStartList(List* lst, int data);
void insertNodeToStartList(List* lst, ListNode* newHead);
void makeEmptyList(List* res);
Tree AddLeaf(Tree tr, TreeNode* p, int branchSelect, int data);
void CheckMem(void* ptr);
Tree BuildTreeFromArrayWithLeafList(int* arr, int  size);
TreeNode* BuildTreeFromArrayWithLeafListRec(int* arr, int start, int  end, int size);
TreeNode* createNewTreeNode(int data, TreeNode* left, TreeNode* right, TreeNode* parent);
TreeNode* findParent(Tree tr, int parentData, int branchSelect);
TreeNode* findParentRec(TreeNode* root, int parentData, int branchSelect);
void BuildLeafList(TreeNode* root, List* head);
void AddLeafRec(TreeNode* root, TreeNode* LeafToAddTo, int branchSelect, int data);
Tree AddLeaf(Tree tr, TreeNode* p, int branchSelect, int data);
void addToList(List* list, int data);
void printTreeInorder(Tree tr);
void printTreeInorderRec(TreeNode* root);
void freeTreeRec(TreeNode* root);
void freeTree(Tree tr);
void printLeafList(Tree tr);
void printLeafListRec(List* leafList);
void freeListRec(ListNode* head);
void freeList(List* list);
ListNode* ReturnNode_to_Update(int data, ListNode* head);