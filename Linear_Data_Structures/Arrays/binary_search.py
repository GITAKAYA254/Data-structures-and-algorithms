"""
Binary Search Implementation
Clean implementation of binary search with comments
Requires a sorted array to work correctly
"""

def binary_search(arr, target):
    """
    Binary search implementation
    Time Complexity: O(log n)
    Space Complexity: O(1) for iterative version
    
    Args:
        arr: Sorted array to search in
        target: Value to search for
    
    Returns:
        Index of target if found, -1 otherwise
    """
    left = 0
    right = len(arr) - 1
    
    while left <= right:
        # Find middle index (prevents overflow in other languages)
        mid = left + (right - left) // 2
        
        # Check if target is at mid
        if arr[mid] == target:
            return mid
        
        # If target is smaller, search left half
        elif arr[mid] > target:
            right = mid - 1
        
        # If target is larger, search right half
        else:
            left = mid + 1
    
    # Target not found
    return -1


def binary_search_recursive(arr, target, left=0, right=None):
    """
    Binary search recursive implementation
    Time Complexity: O(log n)
    Space Complexity: O(log n) due to recursion stack
    
    Args:
        arr: Sorted array to search in
        target: Value to search for
        left: Left boundary index
        right: Right boundary index
    
    Returns:
        Index of target if found, -1 otherwise
    """
    if right is None:
        right = len(arr) - 1
    
    if left > right:
        return -1
    
    mid = left + (right - left) // 2
    
    if arr[mid] == target:
        return mid
    elif arr[mid] > target:
        return binary_search_recursive(arr, target, left, mid - 1)
    else:
        return binary_search_recursive(arr, target, mid + 1, right)


# Demonstration
if __name__ == "__main__":
    # Create a sorted array
    sorted_arr = [2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78]
    print("Sorted Array:", sorted_arr)
    
    # Test iterative binary search
    print("\nIterative Binary Search:")
    test_values = [5, 23, 67, 10, 100]
    for value in test_values:
        result = binary_search(sorted_arr, value)
        if result != -1:
            print(f"  Searching for {value}: Found at index {result}")
        else:
            print(f"  Searching for {value}: Not found")
    
    # Test recursive binary search
    print("\nRecursive Binary Search:")
    for value in test_values:
        result = binary_search_recursive(sorted_arr, value)
        if result != -1:
            print(f"  Searching for {value}: Found at index {result}")
        else:
            print(f"  Searching for {value}: Not found")
    
    # Find boundaries
    print("\nFinding boundaries:")
    print(f"  First element: index {binary_search(sorted_arr, sorted_arr[0])}")
    print(f"  Last element: index {binary_search(sorted_arr, sorted_arr[-1])}")
    print(f"  Middle element: index {binary_search(sorted_arr, sorted_arr[len(sorted_arr)//2])}")
