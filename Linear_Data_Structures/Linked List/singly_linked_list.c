#include <stdio.h>
#include <stdlib.h>

/*
 * Singly linked list implementation in C
 * Simple demo: insert head/tail, search, delete, traverse
 */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void insert_at_head(Node **head, Node **tail, int data) {
    Node *n = create_node(data);
    n->next = *head;
    *head = n;
    if (*tail == NULL) *tail = n;
}

void insert_at_tail(Node **head, Node **tail, int data) {
    Node *n = create_node(data);
    if (*tail) {
        (*tail)->next = n;
        *tail = n;
    } else {
        *head = *tail = n;
    }
}

int search(Node *head, int key) {
    Node *cur = head;
    while (cur) {
        if (cur->data == key) return 1;
        cur = cur->next;
    }
    return 0;
}

int delete_value(Node **head, Node **tail, int key) {
    Node *cur = *head;
    Node *prev = NULL;
    while (cur) {
        if (cur->data == key) {
            if (prev) prev->next = cur->next;
            else *head = cur->next;
            if (cur == *tail) *tail = prev;
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}

void traverse(Node *head) {
    Node *cur = head;
    printf("[");
    while (cur) {
        printf("%d", cur->data);
        if (cur->next) printf(", ");
        cur = cur->next;
    }
    printf("]\n");
}

void free_list(Node *head) {
    Node *cur = head;
    while (cur) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

int main() {
    Node *head = NULL, *tail = NULL;
    insert_at_tail(&head, &tail, 10);
    insert_at_tail(&head, &tail, 20);
    insert_at_head(&head, &tail, 5);
    printf("List after inserts: ");
    traverse(head);

    printf("Search 20: %s\n", search(head, 20) ? "found" : "not found");
    delete_value(&head, &tail, 20);
    printf("After delete 20: ");
    traverse(head);

    free_list(head);
    return 0;
}
