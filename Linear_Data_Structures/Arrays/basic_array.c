#include <stdio.h>
#include <string.h>

/*
 * Basic Array Operations
 * Demonstrates simple array usage: access, insert, delete, traverse
 */

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} Array;

void insert_at(Array *arr, int index, int value) {
    if (arr->size >= MAX_SIZE || index > arr->size) return;
    
    for (int i = arr->size; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[index] = value;
    arr->size++;
}

void delete_at(Array *arr, int index) {
    if (index >= arr->size) return;
    
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

void append(Array *arr, int value) {
    if (arr->size < MAX_SIZE) {
        arr->data[arr->size] = value;
        arr->size++;
    }
}

int access_element(Array *arr, int index) {
    if (index < arr->size) {
        return arr->data[index];
    }
    return -1;
}

void print_array(Array *arr) {
    printf("[");
    for (int i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i < arr->size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    Array arr = {0};
    
    // Create basic array
    int values[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        append(&arr, values[i]);
    }
    
    printf("Original array: ");
    print_array(&arr);
    
    // Access element
    printf("\nAccess Operations:\n");
    printf("Element at index 0: %d\n", access_element(&arr, 0));
    printf("Element at index 4: %d\n", access_element(&arr, 4));
    
    // Insert element
    printf("\nInsert Operations:\n");
    insert_at(&arr, 2, 10);
    printf("After inserting 10 at index 2: ");
    print_array(&arr);
    
    // Delete element
    printf("\nDelete Operations:\n");
    delete_at(&arr, 2);
    printf("After deleting element at index 2: ");
    print_array(&arr);
    
    // Traverse array
    printf("\nTraverse Operations:\n");
    printf("Iterating through array:\n");
    for (int i = 0; i < arr.size; i++) {
        printf("  Index %d: %d\n", i, arr.data[i]);
    }
    
    // Append element
    printf("\nAppend Operations:\n");
    append(&arr, 6);
    printf("After appending 6: ");
    print_array(&arr);
    
    // Modify element
    printf("\nModify Operations:\n");
    arr.data[0] = 100;
    printf("After changing first element to 100: ");
    print_array(&arr);
    
    // Get length
    printf("\nLength of array: %d\n", arr.size);
    
    return 0;
}
