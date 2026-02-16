"""
Sorting Algorithms
Implementations of Bubble Sort, Selection Sort, and Merge Sort
"""

def bubble_sort(arr):
    """
    Bubble Sort
    Time Complexity: O(n²) worst and average case, O(n) best case
    Space Complexity: O(1)
    
    Compares adjacent elements and swaps them if they are in wrong order
    Multiple passes until array is sorted
    """
    n = len(arr)
    
    # Traverse through all array elements
    for i in range(n):
        swapped = False
        
        # Last i elements are already in place
        for j in range(0, n - i - 1):
            # Swap if element is greater than next element
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        
        # If no swaps occurred, array is sorted
        if not swapped:
            break
    
    return arr


def selection_sort(arr):
    """
    Selection Sort
    Time Complexity: O(n²) in all cases
    Space Complexity: O(1)
    
    Finds minimum element in unsorted part and places it at the beginning
    """
    n = len(arr)
    
    # Traverse through all array elements
    for i in range(n):
        # Find minimum element in remaining unsorted array
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        
        # Swap minimum element with current position
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    
    return arr


def merge(arr, left, mid, right):
    """
    Merge helper function for merge sort
    Combines two sorted subarrays
    """
    # Create copies of subarrays
    left_arr = arr[left:mid + 1]
    right_arr = arr[mid + 1:right + 1]
    
    i = j = 0
    k = left
    
    # Compare and merge
    while i < len(left_arr) and j < len(right_arr):
        if left_arr[i] <= right_arr[j]:
            arr[k] = left_arr[i]
            i += 1
        else:
            arr[k] = right_arr[j]
            j += 1
        k += 1
    
    # Copy remaining elements
    while i < len(left_arr):
        arr[k] = left_arr[i]
        i += 1
        k += 1
    
    while j < len(right_arr):
        arr[k] = right_arr[j]
        j += 1
        k += 1


def merge_sort(arr, left=0, right=None):
    """
    Merge Sort
    Time Complexity: O(n log n) in all cases
    Space Complexity: O(n)
    
    Divide and conquer algorithm that divides array into halves,
    recursively sorts them, then merges them
    """
    if right is None:
        right = len(arr) - 1
    
    if left < right:
        # Find the middle point
        mid = (left + right) // 2
        
        # Sort first half
        merge_sort(arr, left, mid)
        
        # Sort second half
        merge_sort(arr, mid + 1, right)
        
        # Merge sorted halves
        merge(arr, left, mid, right)
    
    return arr


# Demonstration
if __name__ == "__main__":
    # Test arrays
    test_cases = [
        [64, 34, 25, 12, 22, 11, 90],
        [5, 2, 8, 1, 9, 3],
        [1, 2, 3, 4, 5],  # Already sorted
        [5, 4, 3, 2, 1],  # Reverse sorted
    ]
    
    print("=" * 50)
    print("BUBBLE SORT")
    print("=" * 50)
    for arr in test_cases:
        original = arr.copy()
        result = bubble_sort(arr)
        print(f"Original: {original}")
        print(f"Sorted:   {result}\n")
    
    print("=" * 50)
    print("SELECTION SORT")
    print("=" * 50)
    for arr in test_cases:
        original = arr.copy()
        result = selection_sort(arr)
        print(f"Original: {original}")
        print(f"Sorted:   {result}\n")
    
    print("=" * 50)
    print("MERGE SORT")
    print("=" * 50)
    for arr in test_cases:
        original = arr.copy()
        result = merge_sort(arr)
        print(f"Original: {original}")
        print(f"Sorted:   {result}\n")
