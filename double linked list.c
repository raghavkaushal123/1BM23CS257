#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertLeft(struct Node** head, int target, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Target node with value %d not found.\n", target);
        free(newNode);
        return;
    }

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        *head = newNode;
    }
    temp->prev = newNode;
}

void deleteNode(struct Node** head, int value) {
    struct Node* current = *head;

    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Node with value %d deleted.\n", value);
}

void display(struct Node* head) {
    struct Node* temp = head;

    printf("List contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, target;

    printf("Doubly Linked List Operations:\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a node to the list\n");
        printf("2. Insert a node to the left of a target\n");
        printf("3. Delete a node by value\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value for the new node: ");
                scanf("%d", &data);
                if (head == NULL) {
                    head = createNode(data);
                } else {
                    struct Node* temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = createNode(data);
                    temp->next->prev = temp;
                }
                printf("Node with value %d added.\n", data);
                break;

            case 2:
                printf("Enter the target value: ");
                scanf("%d", &target);
                printf("Enter value for the new node: ");
                scanf("%d", &data);
                insertLeft(&head, target, data);
                break;

            case 3:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

