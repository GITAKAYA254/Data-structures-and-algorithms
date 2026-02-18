# Stacks

## 1. Definition

A **stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle. The last element added to the stack is the first one removed.

Elements can only be:

- **Pushed** (inserted) at the top.
- **Popped** (removed) from the top.

---

## 2. Basic Operations

| Operation | Description                              |
| --------- | ---------------------------------------- |
| Push      | Insert an element at the top             |
| Pop       | Remove and return the top element        |
| Peek      | View the top element without removing it |
| isEmpty   | Check if the stack is empty              |

---

## 3. Time Complexity

| Operation | Complexity |
| --------- | ---------: |
| Push      |       O(1) |
| Pop       |       O(1) |
| Peek      |       O(1) |
| Search    |       O(n) |

---

## 4. Implementation Using Python List

Python lists provide dynamic array behavior, making them ideal for stack implementation.

````python
class Stack:
    """Stack implementation using Python list."""
    def __init__(self):
        self.items = []

    def push(self, item):
        """Insert an element at the top."""
        self.items.append(item)

    def pop(self):
        """Remove and return the top element."""
        if not self.is_empty():
            return self.items.pop()
        return None

    def peek(self):
        """View the top element without removing."""
        if not self.is_empty():
            return self.items[-1]
        return None

    def is_empty(self):
        """Check if the stack is empty."""
        return len(self.items) == 0

    def size(self):
        """Get the number of elements."""
        return len(self.items)
---

## 5. Implementation Using Linked List

Stacks can also be implemented using linked lists for fine-grained memory control.

```python
class Node:
    """Node for the linked list."""
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    """Stack implementation using a linked list."""
    def __init__(self):
        self.top = None

    def push(self, data):
        """Insert an element at the top."""
        new_node = Node(data)
        new_node.next = self.top
        self.top = new_node

    def pop(self):
        """Remove and return the top element."""
        if self.top is None:
            return None
        popped = self.top.data
        self.top = self.top.next
        return popped

    def peek(self):
        """View the top element without removing."""
        if self.top is None:
            return None
        return self.top.data
````

---

## 6. Advantages

- Simple and intuitive to implement.
- Efficient push and pop operations (O(1)).
- Ideal for recursion and backtracking problems.
- Predictable and bounded behavior.

---

## 7. Disadvantages

- Limited access — only the top element is directly accessible.
- Not suitable when random access to elements is required.

---

## 8. Real-World Applications

### Function Call Stack

- When a function is called, it is pushed onto the **call stack** as a _stack frame_.
- When the function returns, its frame is popped off.
- Recursive functions depend entirely on stack behavior.
- **Stack overflow** occurs if the call stack exceeds memory limits (deep recursion).

### Undo/Redo Operations

- Text editors (Word, VS Code, etc.) use stacks to manage undo and redo history.
- Each action is pushed; undo pops the most recent action.

### Expression Evaluation

- Converting infix notation to postfix notation.
- Evaluating postfix (reverse Polish) expressions.

### Syntax Parsing

---

## 9. Understanding Call Stack Behavior

Every running program maintains a call stack managed by the operating system.

When a function is called:

1. A **stack frame** (containing local variables, return address, parameters) is created.
2. The frame is pushed onto the call stack.
3. Execution jumps to the function.
4. On return, the frame is popped, execution resumes in the calling function.

If recursion is too deep, the stack fills up → **stack overflow** → program crash.

---

## 10. Key Takeaways

- Stacks enforce **disciplined access** — only one end (top) is accessible.
- They are the natural choice for problems involving:
  - Recursion and backtracking
  - Undo/redo mechanisms
  - Expression evaluation and parsing
  - Function calls (managed by the OS)

Think of it as:

- **Arrays** = memory geometry (contiguous, indexed).
- **Linked lists** = memory flexibility (non-contiguous, needs pointers).
- **Stacks** = memory discipline (one-end-only access).
