#include <stdio.h>
#include <stdlib.h>

/*
 * Dynamic Array Implementation
 * Simulate dynamic array resizing manually (like vector in C++)
 */

typedef struct {
    int *data;
    int size;      // Current number of elements
    int capacity;  // Maximum capacity
} DynamicArray;

DynamicArray* create_dynamic_array(int initial_capacity) {
    DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
    arr->data = (int *)malloc(initial_capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = initial_capacity;
    return arr;
}

void resize(DynamicArray *arr, int new_capacity) {
    int old_capacity = arr->capacity;
    int *new_data = (int *)malloc(new_capacity * sizeof(int));
    
    // Copy existing elements
    for (int i = 0; i < arr->size; i++) {
        new_data[i] = arr->data[i];
    }
    
    free(arr->data);
    arr->data = new_data;
    arr->capacity = new_capacity;
    printf("  [Resized array from capacity %d to %d]\n", old_capacity, new_capacity);
}

void append(DynamicArray *arr, int value) {
    // If full, double the capacity
    if (arr->size >= arr->capacity) {
        resize(arr, arr->capacity * 2);
    }
    
    arr->data[arr->size] = value;
    arr->size++;
}

int insert_at(DynamicArray *arr, int index, int value) {
    if (index > arr->size || index < 0) {
        printf("Error: Invalid index!\n");
        return 0;
    }
    
    // Resize if necessary
    if (arr->size >= arr->capacity) {
        resize(arr, arr->capacity * 2);
    }
    
    // Shift elements to the right
    for (int i = arr->size; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    
    arr->data[index] = value;
    arr->size++;
    return 1;
}

int delete(DynamicArray *arr, int index) {
    if (index >= arr->size || index < 0) {
        printf("Error: Invalid index!\n");
        return 0;
    }
    
    // Shift elements to the left
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    
    arr->size--;
    
    // Shrink if necessary (if size is 1/4 of capacity)
    if (arr->size > 0 && arr->size <= arr->capacity / 4) {
        resize(arr, arr->capacity / 2);
    }
    
    return 1;
}

int access(DynamicArray *arr, int index) {
    if (index >= arr->size || index < 0) {
        printf("Error: Invalid index!\n");
        return -1;
    }
    return arr->data[index];
}

void print_array(DynamicArray *arr) {
    printf("[");
    for (int i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i < arr->size - 1) printf(", ");
    }
    printf("]\n");
}

void free_array(DynamicArray *arr) {
    free(arr->data);
    free(arr);
}

int main() {
    DynamicArray *arr = create_dynamic_array(2);
    printf("Created dynamic array with initial capacity: %d\n", arr->capacity);
    
    // Demonstrate auto-resizing by appending elements
    printf("\nAppending elements (watch for resizing):\n");
    for (int i = 1; i <= 8; i++) {
        printf("Appending %d...\n", i * 10);
        append(arr, i * 10);
        printf("  Size: %d, Capacity: %d, Array: ", arr->size, arr->capacity);
        print_array(arr);
    }
    
    // Access elements
    printf("\nAccessing elements:\n");
    printf("  Element at index 0: %d\n", access(arr, 0));
    printf("  Element at index 7: %d\n", access(arr, 7));
    
    // Insert at specific position
    printf("\nInserting 25 at index 2:\n");
    insert_at(arr, 2, 25);
    printf("  Size: %d, Capacity: %d, Array: ", arr->size, arr->capacity);
    print_array(arr);
    
    // Delete element and watch shrinking
    printf("\nDeleting elements (watch for shrinking):\n");
    while (arr->size > 2) {
        delete(arr, arr->size - 1);
        printf("  Size: %d, Capacity: %d, Array: ", arr->size, arr->capacity);
        print_array(arr);
    }
    
    free_array(arr);
    return 0;
}
