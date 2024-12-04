#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d", root->data);
        inOrder(root->right);
    }
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d", root->data);
    }
}

void display(Node *root, int space)
{
    int count = 5;
    if (root == NULL)
    {
        return;
    }
    space = space + count;
    display(root->right, space);
    printf("\n");
    for (int i = count; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);
    display(root->left, space);
}

int main()
{
    Node *root = NULL;
    int choice, value;
    printf("Binary Search Tree Program\n");
    do
    {
        printf("\n1.Insert Element\n");
        printf("2.In-order Traversal\n");
        printf("3.Pre-order Traversal\n");
        printf("4.Post-order Traversal\n");
        printf("5.Display Tree\n");
        printf("6.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("In-order Traversal: ");
            inOrder(root);
            printf("\n");
            break;
        case 3:
            printf("Pre-order Traversal: ");
            preOrder(root);
            printf("\n");
            break;
        case 4:
            printf("Post-order Traversal: ");
            postOrder(root);
            printf("\n");
            break;
        case 5:
            printf("Tree Structure:\n");
            display(root, 0);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);
    return 0;
}
