"""
Basic Array Operations
Demonstrates simple list usage: access, insert, delete, traverse
"""

# Create a basic array (list in Python)
arr = [1, 2, 3, 4, 5]
print("Original array:", arr)

# Access element at index
print("\nAccess Operations:")
print(f"Element at index 0: {arr[0]}")
print(f"Element at index 4: {arr[4]}")

# Insert element
print("\nInsert Operations:")
arr.insert(2, 10)  # Insert 10 at index 2
print(f"After inserting 10 at index 2: {arr}")

# Delete element
print("\nDelete Operations:")
arr.pop(2)  # Remove element at index 2
print(f"After deleting element at index 2: {arr}")

# Traverse array
print("\nTraverse Operations:")
print("Iterating through array:")
for i, value in enumerate(arr):
    print(f"  Index {i}: {value}")

# Append element
print("\nAppend Operations:")
arr.append(6)
print(f"After appending 6: {arr}")

# Modify element
print("\nModify Operations:")
arr[0] = 100
print(f"After changing first element to 100: {arr}")

# Get length
print(f"\nLength of array: {len(arr)}")
