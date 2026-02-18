#include <stdio.h>
#include <stdlib.h>

/*
 * Stack implementation using dynamic array (list-based).
 * Time Complexity: Push O(1) amortized, Pop O(1), Peek O(1)
 */

#define INITIAL_CAPACITY 10

typedef struct {
    int *items;
    int top;      // Index of the top element (-1 if empty)
    int capacity; // Current capacity of the array
} Stack;

Stack* create_stack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->items = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    s->top = -1;
    s->capacity = INITIAL_CAPACITY;
    return s;
}

void resize_stack(Stack *s, int new_capacity) {
    int *new_items = (int *)malloc(new_capacity * sizeof(int));
    for (int i = 0; i <= s->top; i++) {
        new_items[i] = s->items[i];
    }
    free(s->items);
    s->items = new_items;
    s->capacity = new_capacity;
    printf("  [Resized to capacity %d]\n", new_capacity);
}

void push(Stack *s, int value) {
    if (s->top == s->capacity - 1) {
        resize_stack(s, s->capacity * 2);
    }
    s->items[++s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->items[s->top--];
}

int peek(Stack *s) {
    if (s->top == -1) {
        return -1;
    }
    return s->items[s->top];
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int size(Stack *s) {
    return s->top + 1;
}

void print_stack(Stack *s) {
    printf("[");
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->items[i]);
        if (i < s->top) printf(", ");
    }
    printf("]\n");
}

void free_stack(Stack *s) {
    free(s->items);
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
