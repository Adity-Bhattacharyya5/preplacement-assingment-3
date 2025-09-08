#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printNthFromEnd(struct Node* head, int n) {
    struct Node* mainPtr = head;
    struct Node* refPtr = head;

    int count = 0;

    while (count < n) {
        if (refPtr == NULL) {
            printf("List has fewer than %d nodes.\n", n);
            return;
        }
        refPtr = refPtr->next;
        count++;
    }

    while (refPtr != NULL) {
        mainPtr = mainPtr->next;
        refPtr = refPtr->next;
    }

    printf("The %dth node from the end is %d\n", n, mainPtr->data);
}


void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 50);

    printList(head); 

    printNthFromEnd(head, 2);  

    return 0;
}

