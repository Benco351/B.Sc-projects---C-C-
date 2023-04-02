#include "Header.h"

char stringValidator[SIZE]; // Temp array
int top = -1; // Terminator
TreeNode* head = NULL; // The head  (node) of the STACK data structure .

//Convert char to int 
int toInt(char str)
{

    return str - '0';
}


// This function receives a node of the syntax tree
// and recursively evaluates it
double calcExpressionCall(TreeNode* root)
{
    // empty tree
    if (!root)
        return 0;

    // leaf node i.e, an integer
    if (!root->left && !root->right)
        return (double)toInt(root->data);

    // Evaluate left subtree
    double l_val = calcExpressionCall(root->left);

    // Evaluate right subtree
    double r_val = calcExpressionCall(root->right);

    // Check which operator to apply
    if (root->data == '+')
        return l_val + r_val;

    if (root->data == '-')
        return l_val - r_val;

    if (root->data == '*')
        return l_val * r_val;

    if (root->data == '%')
        return ((int)l_val % (int)r_val);

    return l_val / r_val;
}
//Function that returns the calculation of the expression tree
double calcExpression(Tree tr)
{
    return calcExpressionCall(tr.root);
}
//Function to push element to the temp array 
void push(char ch)
{
    stringValidator[++top] = ch;
}
//Function that returns the last element inserted to the temp array else -1
char pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return stringValidator[top--];
    }
}
//Function that returns the math character priority 
int priority(char ch)
{
    if (ch == '(' || ch == ')')
    {
        return 0;
    }
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    if (ch == '*' || ch == '/' || ch == '%')
    {
        return 2;
    }
}
//Returns true/false if the given char type is valid or not
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// push a node to the Stack data structure
void push2(TreeNode* x)
{
    if (head == NULL)
        head = x;
    else
    {
        (x)->next = head;
        head = x;
    }

}
TreeNode* pop2()
{
    // Poping out the top most[ pointed with head] element
    TreeNode* p = head;
    head = head->next;
    return p;
}
// build the expression tree by postfix array.
BOOL buildExpressionTree(char str[], Tree* tr)
{
    if (!ifOk(str, strlen(str)))
    {
        tr->root = NULL;
        return FALSE;
    }
    else
    {
        char* postfix = postfixCreator(str);
        int size = strlen(postfix);
        tr->root = buildExpressionTreeIter(postfix, size);
        free(postfix);
        return TRUE;
    }

}
// checks if the input is valid for the next steps
bool ifOk(char* str, int size)
{
    int countLeft = 0, countRight = 0;
    for (int i = 0; i < size; i++)
    {
        if (str[i] != ')' && str[i] != '(')
        {
            if (!isOperator(str[i]) && ((str[i] - '0' < 0) || (str[i] - '0' > 9)))
            {
                return false;
            }
        }
        else
        {
            if (str[i] == ')')
            {
                countLeft++;
            }
            else
            {
                countRight++;
            }
        }
    }
    if (countLeft == countRight)
        return true;
    return false;
}
// create a stack with every step of the tree
TreeNode* buildExpressionTreeIter(char* postfix, int size)
{
    TreeNode* left, * right, * root = NULL;
    int index = 0;
    for (int i = 0; i < size && postfix[i] != '\0'; i++)
    {
        if (isOperator(postfix[i]))
        {
            root = createNewTreeNode(postfix[i], NULL, NULL, NULL);
            right = pop2();
            left = pop2();
            root->left = left;
            root->right = right;
            push2(root);
        }
        else
        {
            root = createNewTreeNode(postfix[i], NULL, NULL, NULL);
            push2(root);
        }
    }
    return root;
}
// checking asociativity and make a new array to build the tree from
char* postfixCreator(char* str)
{
    char temp;
    int maxSize = 1;
    char* postfix = (char*)malloc(sizeof(char));
    CheckMem(postfix);
    int i = 0; 
    int j = 0;
    while ((*str) != '\0')
    
    {
        if (j == maxSize)
        {
            maxSize *= 2;
            postfix = (char*)realloc(postfix, sizeof(char) * maxSize);
        }
        if (*str >= '0' && *str <= '9')
        {
            postfix[i++] = *str;
            j++;
        }

        else if (*str == '(')
        {
            push(*str);
        }
        else if (*str == ')')
        {
            while ((temp = pop()) != '(')
            {
                postfix[i++] = temp;
            }
        }
        else
        {
            if (isOperator(*str))
            {
                while (priority(stringValidator[top]) >= priority(*str))
                {
                    postfix[i++] = pop();
                    j++;
                }
                push(*str);
            }
        }

        str++;
    }
    while (top != -1)
    {
        postfix[++i] = pop();
        j++;
    }
    postfix[i] = '\0';

    return postfix;
}
// free the memory in the tree nodes
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
        /*  free(root->next);*/
        free(root);

    }
}
//Create New node in the tree function
TreeNode* createNewTreeNode(int data, TreeNode* left, TreeNode* right, TreeNode* next)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    CheckMem(node);
    node->data = data;
    node->left = left;
    node->right = right;
    node->next = next;
    return node;
}


void CheckMem(void* ptr)
{
    if (ptr == NULL)
    {
        exit(EXIT_FAILURE);
    }
}