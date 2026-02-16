#include <stdio.h>

/*
 * Binary Search Implementation
 * Clean implementation of binary search with comments
 * Requires a sorted array to work correctly
 */

/*
 * Iterative binary search
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * 
 * Returns: Index of target if found, -1 otherwise
 */
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        // Find middle index (prevents overflow)
        int mid = left + (right - left) / 2;
        
        // Check if target is at mid
        if (arr[mid] == target) {
            return mid;
        }
        
        // If target is smaller, search left half
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        
        // If target is larger, search right half
        else {
            left = mid + 1;
        }
    }
    
    // Target not found
    return -1;
}

/*
 * Recursive binary search
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) due to recursion stack
 * 
 * Returns: Index of target if found, -1 otherwise
 */
int binary_search_recursive(int arr[], int target, int left, int right) {
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    }
    else if (arr[mid] > target) {
        return binary_search_recursive(arr, target, left, mid - 1);
    }
    else {
        return binary_search_recursive(arr, target, mid + 1, right);
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

int main() {
    // Create a sorted array
    int sorted_arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int size = sizeof(sorted_arr) / sizeof(sorted_arr[0]);
    
    printf("Sorted Array: ");
    print_array(sorted_arr, size);
    
    // Test iterative binary search
    printf("\nIterative Binary Search:\n");
    int test_values[] = {5, 23, 67, 10, 100};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);
    
    for (int i = 0; i < num_tests; i++) {
        int result = binary_search(sorted_arr, size, test_values[i]);
        if (result != -1) {
            printf("  Searching for %d: Found at index %d\n", test_values[i], result);
        }
        else {
            printf("  Searching for %d: Not found\n", test_values[i]);
        }
    }
    
    // Test recursive binary search
    printf("\nRecursive Binary Search:\n");
    for (int i = 0; i < num_tests; i++) {
        int result = binary_search_recursive(sorted_arr, test_values[i], 0, size - 1);
        if (result != -1) {
            printf("  Searching for %d: Found at index %d\n", test_values[i], result);
        }
        else {
            printf("  Searching for %d: Not found\n", test_values[i]);
        }
    }
    
    // Find boundaries
    printf("\nFinding boundaries:\n");
    printf("  First element: index %d\n", binary_search(sorted_arr, size, sorted_arr[0]));
    printf("  Last element: index %d\n", binary_search(sorted_arr, size, sorted_arr[size - 1]));
    printf("  Middle element: index %d\n", binary_search(sorted_arr, size, sorted_arr[size / 2]));
    
    return 0;
}
