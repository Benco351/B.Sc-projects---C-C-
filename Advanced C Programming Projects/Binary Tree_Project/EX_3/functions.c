#include "Header.h"


//Create an empty list
void makeEmptyList(List* res)
{
    res->head = res->tail = NULL;
}
ListNode* createNewListNode(int data, ListNode* next)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    CheckMem(node);
    node->data = data;
    node->next = next;
    return node;
}
// Check if the current list is empty
bool isEmptyList(List lst)
{
    return (lst.head == NULL);
}
//utility function of insertDataToEndList
void insertNodeToEndList(List* lst, ListNode* newTail)
{
    if (isEmptyList(*lst))
        lst->head = lst->tail = newTail;
    else
    {
        lst->tail->next = newTail;
        lst->tail = newTail;
    }
}
//Insert data to end list function using 2 others utility function below
void insertDataToEndList(List* lst, int data)
{
    ListNode* newTail;
    newTail = createNewListNode(data, NULL);
    insertNodeToEndList(lst, newTail);

}
//Function that returns the deserved parent pointer.
TreeNode* findParent(Tree tr, int parentData, int branchSelect)
{
   
   
    return findParentRec(tr.root, parentData, branchSelect);
}

// Returns the exact parent pointer
TreeNode* findParentRec(TreeNode* root, int parentData, int branchSelect)
{
    TreeNode* temp = NULL;
    if (root != NULL)
    {
        if (root->data == parentData)
        {
            switch (branchSelect)
            {
            case LEFT:
                if ( root->left == NULL)
                {
                    return root;

                }


                break;
            case RIGHT:
                if ( root->right == NULL)
                {
                    return root;
                }
                break;
            }
        }
        else
        {
            temp = findParentRec(root->left, parentData, branchSelect);
            if (temp == NULL)
            {
                temp = findParentRec(root->right, parentData, branchSelect);
            }
            return temp;
        }
        return NULL;
    }
    return NULL;
   
}
// Returns a pointer if the data exists in the list else NULL
ListNode* ReturnNode_to_Update(int data, ListNode* head)
{

    if (head == NULL)
        return NULL;

    if (head->data == data)
        return head;



    return ReturnNode_to_Update(data, head->next);

}
//Main function that resposibly to add a leaf to the tree
Tree AddLeaf(Tree tr, TreeNode* p, int branchSelect, int data)
{
    AddLeafRec(tr.root, p, branchSelect, data); // first add the leaf
    ListNode* some = ReturnNode_to_Update(p->data, tr.leafList.head); // find if exists already in the leaflist
    if (!some)
    {
        if (branchSelect != LEFT)// If no left subtree
        {

            addToList(&tr.leafList, data);
        }
        else 
        {
            insertDataToStartList(&tr.leafList, data);
        }
    }
    else // if found the data in the leaflist
    {
       
        some->data = data;
    
    }
  
    return tr;
}

// Function that insert new node to the start of a given list
void insertDataToStartList(List* lst, int data)
{
    ListNode* newHead;
    newHead = createNewListNode(data, NULL);
    insertNodeToStartList(lst, newHead);
}
//Utillity function of insertDataToStartList.
void insertNodeToStartList(List* lst, ListNode* newHead)
{
    if (isEmptyList(*lst))
        lst->head = lst->tail = newHead;
    else
    {
        newHead->next = lst->head;
        lst->head = newHead;
    }
}
// Recursive function that add the leaf to the specific child of a leaf
void AddLeafRec(TreeNode* root, TreeNode* LeafToAddTo, int branchSelect, int data)
{
    if (root == NULL) {
        return;
    }
    TreeNode* NewNode;
    switch (branchSelect)
    {
    case LEFT:
        if (root == LeafToAddTo && root->left == NULL)
        {
            NewNode = createNewTreeNode(data, NULL, NULL, LeafToAddTo);
            root->left = NewNode;
            break;
        }


        break;
    case RIGHT:
        if (root == LeafToAddTo && root->right == NULL)
        {
            NewNode = createNewTreeNode(data, NULL, NULL, LeafToAddTo);
            root->right = NewNode;
            break;
        }
        break;
    default:
        return;
        break;
    }
    AddLeafRec(root->left, LeafToAddTo, branchSelect,  data);
    AddLeafRec(root->right, LeafToAddTo, branchSelect,  data);
}
//Shortcut function that call to insertDataToEndList function
void addToList(List* list, int data)
{
    insertDataToEndList(list, data);
}

// Main function Question 3 
Tree BuildTreeFromArrayWithLeafList(int* arr, int  size)
{
    Tree tr;
    int start = 0;
    int end = size;
    makeEmptyList(&tr.leafList);
    tr.root = BuildTreeFromArrayWithLeafListRec(arr, start, end,size);
    BuildLeafList(tr.root, &tr.leafList);
    return tr;

}
//Build a leaflist from a give tree
void BuildLeafList(TreeNode* root , List* head)
{
    if (root == NULL)
    {
        return ;
    }
    else
    {
        BuildLeafList(root->left, head);
        BuildLeafList(root->right, head);
        if (root->left == NULL && root->right == NULL)
        {
            insertDataToEndList(head, root->data);
        }
    
    }

}

//Function that build a tree from an array like question 1 but also after the recursive call , pointing every child to his parent
TreeNode* BuildTreeFromArrayWithLeafListRec(int* arr, int start, int  end,int size)
{
    if (start > end)
    {
        return NULL;
    }
    else
    {

        int mid = (start + end) / 2;
        TreeNode* right, * left, * root;

        left = BuildTreeFromArrayWithLeafListRec(arr, start, mid - 1, size);

        right = BuildTreeFromArrayWithLeafListRec(arr, mid + 1, end, size);

        root = (arr[mid] != -1 && mid != size) ? createNewTreeNode(arr[mid], left, right, NULL) : NULL;

        if (left != NULL)
        {
            left->parent = root;
        }
        if (right != NULL)
        {
            right->parent = root;
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
//Function that creates new node in the tree
TreeNode* createNewTreeNode(int data, TreeNode* left, TreeNode* right, TreeNode* parent)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = left;
    node->right = right;
    node->parent = parent;
    return node;
}
//Function to release the tree memory 
void freeTree(Tree tr)
{
    freeTreeRec(tr.root);
    freeList(&tr.leafList);
}
//Recursivley free the tree
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
//Printing the tree inOrder
void printTreeInorder(Tree tr)
{
    printTreeInorderRec(tr.root);
    printf("\n");
}
//Recursivley printing the nodes of a tree in inOrder form
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
//Function to release the list memory
void freeList(List* list)
{
    freeListRec(list->head);
}
//free list using recursion
void freeListRec(ListNode* head)
{
    if (head == NULL)
        return;
    else
    {
        freeListRec(head->next);
        free(head);
    }
}
//printing the LeafList nodes.
void printLeafList(Tree tr)
{
    printLeafListRec(&tr.leafList);
}
//Recursively printing the leaflist nodes.
void printLeafListRec(List* leafList)
{
    ListNode* curr = leafList->head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}