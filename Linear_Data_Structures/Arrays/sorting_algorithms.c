#include <stdio.h>
#include <string.h>

/*
 * Sorting Algorithms
 * Implementations of Bubble Sort, Selection Sort, and Merge Sort
 */

/*
 * Bubble Sort
 * Time Complexity: O(n²) worst and average case, O(n) best case
 * Space Complexity: O(1)
 * 
 * Compares adjacent elements and swaps them if they are in wrong order
 */
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int swapped = 0;
        
        // Last i elements are already in place
        for (int j = 0; j < size - i - 1; j++) {
            // Swap if element is greater than next element
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        
        // If no swaps occurred, array is sorted
        if (!swapped) break;
    }
}

/*
 * Selection Sort
 * Time Complexity: O(n²) in all cases
 * Space Complexity: O(1)
 * 
 * Finds minimum element in unsorted part and places it at the beginning
 */
void selection_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        // Find minimum element in remaining unsorted array
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // Swap minimum element with current position
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

/*
 * Merge helper function for merge sort
 * Combines two sorted subarrays
 */
void merge(int arr[], int left, int mid, int right) {
    // Calculate sizes
    int left_size = mid - left + 1;
    int right_size = right - mid;
    
    // Create temporary arrays
    int *left_arr = (int *)malloc(left_size * sizeof(int));
    int *right_arr = (int *)malloc(right_size * sizeof(int));
    
    // Copy data to temporary arrays
    for (int i = 0; i < left_size; i++) {
        left_arr[i] = arr[left + i];
    }
    for (int j = 0; j < right_size; j++) {
        right_arr[j] = arr[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
    
    // Compare and merge
    while (i < left_size && j < right_size) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements
    while (i < left_size) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    
    while (j < right_size) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
    
    free(left_arr);
    free(right_arr);
}

/*
 * Merge Sort
 * Time Complexity: O(n log n) in all cases
 * Space Complexity: O(n)
 * 
 * Divide and conquer algorithm that divides array into halves,
 * recursively sorts them, then merges them
 */
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;
        
        // Sort first half
        merge_sort(arr, left, mid);
        
        // Sort second half
        merge_sort(arr, mid + 1, right);
        
        // Merge sorted halves
        merge(arr, left, mid, right);
    }
}

void print_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

void copy_array(int src[], int dst[], int size) {
    memcpy(dst, src, size * sizeof(int));
}

int main() {
    // Test cases
    int test1[] = {64, 34, 25, 12, 22, 11, 90};
    int test2[] = {5, 2, 8, 1, 9, 3};
    int test3[] = {1, 2, 3, 4, 5};
    int test4[] = {5, 4, 3, 2, 1};
    
    int *tests[] = {test1, test2, test3, test4};
    int sizes[] = {7, 6, 5, 5};
    
    printf("==================================================\n");
    printf("BUBBLE SORT\n");
    printf("==================================================\n");
    for (int t = 0; t < 4; t++) {
        int arr[20];
        copy_array(tests[t], arr, sizes[t]);
        printf("Original: ");
        print_array(arr, sizes[t]);
        bubble_sort(arr, sizes[t]);
        printf("Sorted:   ");
        print_array(arr, sizes[t]);
        printf("\n");
    }
    
    printf("==================================================\n");
    printf("SELECTION SORT\n");
    printf("==================================================\n");
    for (int t = 0; t < 4; t++) {
        int arr[20];
        copy_array(tests[t], arr, sizes[t]);
        printf("Original: ");
        print_array(arr, sizes[t]);
        selection_sort(arr, sizes[t]);
        printf("Sorted:   ");
        print_array(arr, sizes[t]);
        printf("\n");
    }
    
    printf("==================================================\n");
    printf("MERGE SORT\n");
    printf("==================================================\n");
    for (int t = 0; t < 4; t++) {
        int arr[20];
        copy_array(tests[t], arr, sizes[t]);
        printf("Original: ");
        print_array(arr, sizes[t]);
        merge_sort(arr, 0, sizes[t] - 1);
        printf("Sorted:   ");
        print_array(arr, sizes[t]);
        printf("\n");
    }
    
    return 0;
}
