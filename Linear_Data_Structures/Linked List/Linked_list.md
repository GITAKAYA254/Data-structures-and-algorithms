# Linked Lists

## 1. Definition

A **Linked List** is a linear data structure where elements (called _nodes_) are stored in **non-contiguous memory locations**.

Each node contains:

- **Data**
- **A reference (pointer) to the next node**

In a **Doubly Linked List**, each node also contains a pointer to the previous node.

Unlike arrays, linked lists do **not** rely on index-based memory calculation.  
They connect elements using references.

---

## 2. Memory Representation

Each node conceptually looks like this:

Example:

Key idea:

- Memory is **not contiguous**
- Nodes can exist anywhere in memory
- The structure is maintained logically through pointers

---

## 3. Types of Linked Lists

### 3.1 Singly Linked List

- Each node points to the next node
- Traversal is one-directional

### 3.2 Doubly Linked List

- Each node has:
  - `prev` pointer
  - `next` pointer
- Allows forward and backward traversal
- Uses more memory

### 3.3 Circular Linked List

- The last node points back to the head
- No `None` at the end
- Used in cyclic systems (e.g., scheduling)

# Linked Lists

## 1. Definition

A **linked list** is a linear data structure where elements (called "nodes") are stored in **non-contiguous memory locations**. Each node contains:

- **data** — the value stored in the node
- **pointer/reference** — the link to the next node (and optionally to the previous node in doubly linked lists)

Unlike arrays, linked lists do not use index-based addressing; they connect elements via references.

---

## 2. Memory Representation

Conceptually a node looks like:

```
[ data | next ]  ->  [ data | next ]  ->  [ data | next ] -> NULL
```

Key ideas:

- Memory is not contiguous.
- Nodes can be allocated anywhere in memory.
- Links (pointers) maintain the list structure.

---

## 3. Types of Linked Lists

### 3.1 Singly Linked List

- Each node points to the next node.
- Traversal is one-directional (head -> tail).

### 3.2 Doubly Linked List

- Each node has both `prev` and `next` pointers.
- Allows forward and backward traversal.
- Uses more memory per node.

### 3.3 Circular Linked List

- The last node points back to the head.
- Useful for cyclic behavior (e.g., round-robin scheduling).

---

## 4. Time Complexity (Singly Linked List)

| Operation            | Complexity |
| -------------------- | ---------: |
| Access by index      |       O(n) |
| Search               |       O(n) |
| Insert at head       |       O(1) |
| Insert at tail       |     O(n)\* |
| Delete (given value) |       O(n) |

\*Insert at tail is O(1) if a tail pointer is maintained.

---

## 5. Advantages

- Dynamic size (no fixed capacity).
- Efficient insertions and deletions when location is known.
- Does not require contiguous memory.

---

## 6. Disadvantages

- No random access — must traverse from the head.
- Extra memory overhead for pointers.
- Poor cache locality compared to arrays.

---

## 7. Basic Implementation (Singly Linked List)

```python
class Node:
    """Represents a single node in a singly linked list."""
    def __init__(self, data):
        self.data = data
        self.next = None


class SinglyLinkedList:
    """Simple singly linked list with basic operations."""
    def __init__(self):
        self.head = None

    def insert_at_head(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def traverse(self):
        current = self.head
        while current:
            print(current.data)
            current = current.next

    def search(self, key):
        current = self.head
        while current:
            if current.data == key:
                return True
            current = current.next
        return False
```

---

## 8. Comparison: Array vs Linked List

| Feature            |      Array |       Linked List |
| ------------------ | ---------: | ----------------: |
| Memory layout      | Contiguous |    Non-contiguous |
| Access speed       |       O(1) |              O(n) |
| Insertion (middle) |       O(n) |            O(1)\* |
| Memory overhead    |        Low | Higher (pointers) |
| Cache performance  |  Excellent |              Poor |

\*O(1) if you already have a reference to the insertion point.

---

## 9. Real-World Applications

- **Operating systems:** free-list management, process control blocks.
- **Web browsers:** history/forward-back navigation structures.
- **Hash tables:** chaining for collision resolution.
- **Stacks and queues:** implemented with linked lists for dynamic sizing.
- **Scheduling:** circular linked lists used in round-robin scheduling.

---

## 10. When to Use Linked Lists

Useful when:

- Data size changes frequently.
- Insertions and deletions are common.
- Contiguous memory allocation is difficult.

Not ideal when:

- Fast indexed access is required.
- Cache performance is important.

---

## 11. Key Concepts

- Arrays optimize for fast random access (indexing).
- Linked lists optimize for structural flexibility (easy insertion/deletion).
