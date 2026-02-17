#include <stdio.h>
#include <stdlib.h>

/*
 * Doubly linked list implementation in C
 * Demo: insert head/tail, search, delete, traverse forward/backward
 */

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

DNode* create_node(int data) {
    DNode *n = (DNode*)malloc(sizeof(DNode));
    n->data = data;
    n->prev = n->next = NULL;
    return n;
}

void insert_at_head(DNode **head, DNode **tail, int data) {
    DNode *n = create_node(data);
    n->next = *head;
    if (*head) (*head)->prev = n;
    *head = n;
    if (*tail == NULL) *tail = n;
}

void insert_at_tail(DNode **head, DNode **tail, int data) {
    DNode *n = create_node(data);
    if (*tail) {
        (*tail)->next = n;
        n->prev = *tail;
        *tail = n;
    } else {
        *head = *tail = n;
    }
}

int search(DNode *head, int key) {
    DNode *cur = head;
    while (cur) {
        if (cur->data == key) return 1;
        cur = cur->next;
    }
    return 0;
}

int delete_value(DNode **head, DNode **tail, int key) {
    DNode *cur = *head;
    while (cur) {
        if (cur->data == key) {
            if (cur->prev) cur->prev->next = cur->next;
            else *head = cur->next;
            if (cur->next) cur->next->prev = cur->prev;
            else *tail = cur->prev;
            free(cur);
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

void traverse_forward(DNode *head) {
    DNode *cur = head;
    printf("[");
    while (cur) {
        printf("%d", cur->data);
        if (cur->next) printf(", ");
        cur = cur->next;
    }
    printf("]\n");
}

void traverse_backward(DNode *tail) {
    DNode *cur = tail;
    printf("[");
    while (cur) {
        printf("%d", cur->data);
        if (cur->prev) printf(", ");
        cur = cur->prev;
    }
    printf("]\n");
}

void free_list(DNode *head) {
    DNode *cur = head;
    while (cur) {
        DNode *next = cur->next;
        free(cur);
        cur = next;
    }
}

int main() {
    DNode *head = NULL, *tail = NULL;
    insert_at_tail(&head, &tail, 1);
    insert_at_tail(&head, &tail, 2);
    insert_at_tail(&head, &tail, 3);
    printf("Forward: ");
    traverse_forward(head);
    printf("Backward: ");
    traverse_backward(tail);

    insert_at_head(&head, &tail, 0);
    printf("After insert_at_head(0) Forward: ");
    traverse_forward(head);

    delete_value(&head, &tail, 2);
    printf("After delete 2 Forward: ");
    traverse_forward(head);

    free_list(head);
    return 0;
}
