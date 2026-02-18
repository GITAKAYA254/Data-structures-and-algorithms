#include <stdio.h>
#include <stdlib.h>

/*
 * Stack implementation using linked list (node-based).
 * Offers fine-grained memory control and no resizing overhead.
 * Time Complexity: Push O(1), Pop O(1), Peek O(1)
 */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
    int size_count;
} Stack;

Stack* create_stack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    s->size_count = 0;
    return s;
}

Node* create_node(int data) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void push(Stack *s, int data) {
    Node *new_node = create_node(data);
    new_node->next = s->top;
    s->top = new_node;
    s->size_count++;
}

int pop(Stack *s) {
    if (s->top == NULL) {
        printf("Stack underflow!\n");
        return -1;
    }
    int popped = s->top->data;
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size_count--;
    return popped;
}

int peek(Stack *s) {
    if (s->top == NULL) {
        return -1;
    }
    return s->top->data;
}

int is_empty(Stack *s) {
    return s->top == NULL;
}

int size(Stack *s) {
    return s->size_count;
}

void print_stack(Stack *s) {
    printf("[");
    Node *current = s->top;
    int first = 1;
    while (current != NULL) {
        if (!first) printf(" -> ");
        printf("%d", current->data);
        current = current->next;
        first = 0;
    }
    printf("]\n");
}

void free_stack(Stack *s) {
    while (!is_empty(s)) {
        pop(s);
    }
    free(s);
}

int main() {
    Stack *stack = create_stack();
    printf("Empty stack: ");
    print_stack(stack);
    
    printf("\nPushing 10, 20, 30:\n");
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("Stack: ");
    print_stack(stack);
    
    printf("Peek: %d\n", peek(stack));
    printf("Size: %d\n", size(stack));
    
    printf("\nPopping:\n");
    while (!is_empty(stack)) {
        printf("  Popped: %d\n", pop(stack));
    }
    
    printf("Empty again: %s\n", is_empty(stack) ? "true" : "false");
    
    free_stack(stack);
    return 0;
}
