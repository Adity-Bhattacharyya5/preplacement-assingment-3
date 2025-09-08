#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
struct Node* addTwoLists(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node** lastPtrRef = &result;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        *lastPtrRef = newNode(digit);
        lastPtrRef = &((*lastPtrRef)->next);
    }

    return result;
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
void insertAtBeginning(struct Node** head, int data) {
    struct Node* node = newNode(data);
    node->next = *head;
    *head = node;
}

int main() {
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;
    insertAtBeginning(&num1, 3);
    insertAtBeginning(&num1, 4);
    insertAtBeginning(&num1, 2);
    insertAtBeginning(&num2, 4);
    insertAtBeginning(&num2, 6);
    insertAtBeginning(&num2, 5);

    printf("Number 1: ");
    printList(num1);
    printf("Number 2: ");
    printList(num2);

    struct Node* sum = addTwoLists(num1, num2);

    printf("Sum: ");
    printList(sum);
    return 0;
}

