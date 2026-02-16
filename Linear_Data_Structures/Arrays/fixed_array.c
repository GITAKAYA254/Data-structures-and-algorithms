#include <stdio.h>
#include <stdlib.h>

/*
 * Fixed Array Implementation
 * Manual size-limited array class to demonstrate memory constraints
 */

typedef struct {
    int *data;
    int size;      // Capacity
    int count;     // Current number of elements
} FixedArray;

FixedArray* create_fixed_array(int size) {
    FixedArray *arr = (FixedArray *)malloc(sizeof(FixedArray));
    arr->data = (int *)malloc(size * sizeof(int));
    arr->size = size;
    arr->count = 0;
    return arr;
}

int insert(FixedArray *arr, int value) {
    if (arr->count >= arr->size) {
        printf("Error: Array is full!\n");
        return 0;
    }
    arr->data[arr->count] = value;
    arr->count++;
    return 1;
}

int insert_at(FixedArray *arr, int index, int value) {
    if (index > arr->count || index < 0) {
        printf("Error: Invalid index!\n");
        return 0;
    }
    if (arr->count >= arr->size) {
        printf("Error: Array is full!\n");
        return 0;
    }
    
    // Shift elements to the right
    for (int i = arr->count; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    
    arr->data[index] = value;
    arr->count++;
    return 1;
}

int delete(FixedArray *arr, int index) {
    if (index >= arr->count || index < 0) {
        printf("Error: Invalid index!\n");
        return 0;
    }
    
    // Shift elements to the left
    for (int i = index; i < arr->count - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    
    arr->count--;
    return 1;
}

int access(FixedArray *arr, int index) {
    if (index >= arr->count || index < 0) {
        printf("Error: Invalid index!\n");
        return -1;
    }
    return arr->data[index];
}

int is_full(FixedArray *arr) {
    return arr->count >= arr->size;
}

int is_empty(FixedArray *arr) {
    return arr->count == 0;
}

void print_array(FixedArray *arr) {
    printf("[");
    for (int i = 0; i < arr->count; i++) {
        printf("%d", arr->data[i]);
        if (i < arr->count - 1) printf(", ");
    }
    printf("]\n");
}

void free_array(FixedArray *arr) {
    free(arr->data);
    free(arr);
}

int main() {
    // Create fixed array of size 5
    FixedArray *arr = create_fixed_array(5);
    printf("Created fixed array with capacity: %d\n", arr->size);
    
    // Insert elements
    printf("\nInserting elements:\n");
    for (int i = 1; i <= 5; i++) {
        insert(arr, i * 10);
        printf("  Inserted %d: ", i * 10);
        print_array(arr);
    }
    
    printf("\nArray is full: %s\n", is_full(arr) ? "true" : "false");
    
    // Try to insert when full
    printf("\nTrying to insert 100 (should fail):\n");
    insert(arr, 100);
    
    // Access elements
    printf("\nAccessing elements:\n");
    printf("  Element at index 0: %d\n", access(arr, 0));
    printf("  Element at index 4: %d\n", access(arr, 4));
    
    // Insert at specific position
    printf("\nInserting 25 at index 1:\n");
    delete(arr, 4);  // Make space first
    insert_at(arr, 1, 25);
    printf("  ");
    print_array(arr);
    
    // Delete element
    printf("\nDeleting element at index 2:\n");
    delete(arr, 2);
    printf("  ");
    print_array(arr);
    
    printf("\nCurrent count: %d/%d\n", arr->count, arr->size);
    
    free_array(arr);
    return 0;
}
