# Arrays

## Definition

An **array** is a collection of elements of the **same type**, stored in **contiguous memory locations**. Each element can be accessed directly using an **index**, allowing **fast random access**.

- **Contiguous memory**: elements are stored one after another in memory.
- **Index-based access**: allows retrieving or modifying any element in constant time.

---

## Memory Representation

The memory address of an element at index `i` is calculated as:

Where:

- `base_address` is the address of the first element
- `index` is the element's position
- `element_size` is the size of each element in memory

This formula explains why **access is O(1)**.

---

## Time Complexity Table

| Operation       | Complexity     |
| --------------- | -------------- |
| Access          | O(1)           |
| Search          | O(n)           |
| Insert (end)    | O(1) amortized |
| Insert (middle) | O(n)           |
| Delete          | O(n)           |

---

## Advantages

- Fast random access
- Memory locality (cache-friendly)
- Simple structure

## Disadvantages

- Fixed size for static arrays
- Expensive insertions and deletions
- Memory resizing cost for dynamic arrays

---

## Real-World Applications

Arrays are used in:

- Image processing (pixel grids)
- Machine learning (vectors, matrices, tensors)
- Game boards and simulations
- Databases temporary storage

Tools like **NumPy** provide highly optimized arrays in Python.

---

## Algorithms That Depend on Arrays

- Binary Search
- Sorting algorithms
- Matrix operations

---

## Code Examples

### basic_array.py

- Simple list usage: access, insert, delete, traverse

### fixed_array.py

- Manual size-limited array class to demonstrate memory thinking

### dynamic_array.py

- Simulate dynamic array resizing manually

### binary_search.py

- Clean implementation of binary search with comments

### sorting_algorithms.py

- Bubble Sort
- Selection Sort
- Merge Sort (optional later)

---

## Applications.md (Conceptual)

Arrays are used inside:

- Operating Systems
  • Process scheduling → Queue
  • Memory management → Linked List
  • File system → Tree
- AI systems
- Databases
  • Indexing → B-Trees
  • Hash tables → Fast lookups
- Game engines
