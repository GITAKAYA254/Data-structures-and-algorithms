"""
Stack implementation using a linked list (node-based).
Offers fine-grained memory control and no amortized resizing overhead.
Time Complexity: Push O(1), Pop O(1), Peek O(1)
"""


class Node:
    """Node for the linked list."""
    
    def __init__(self, data):
        """Initialize a node with data and next pointer."""
        self.data = data
        self.next = None


class Stack:
    """Stack implementation using a linked list."""
    
    def __init__(self):
        """Initialize an empty stack."""
        self.top = None
        self.size_count = 0

    def push(self, data):
        """Insert an element at the top."""
        new_node = Node(data)
        new_node.next = self.top
        self.top = new_node
        self.size_count += 1

    def pop(self):
        """Remove and return the top element."""
        if self.top is None:
            return None
        popped = self.top.data
        self.top = self.top.next
        self.size_count -= 1
        return popped

    def peek(self):
        """View the top element without removing."""
        if self.top is None:
            return None
        return self.top.data

    def is_empty(self):
        """Check if the stack is empty."""
        return self.top is None

    def size(self):
        """Get the number of elements."""
        return self.size_count

    def __str__(self):
        """String representation of the stack."""
        elements = []
        current = self.top
        while current:
            elements.append(str(current.data))
            current = current.next
        return f"Stack([{' -> '.join(elements)}])"


if __name__ == "__main__":
    # Demo
    stack = Stack()
    print("Empty stack:", stack)
    
    print("\nPushing 10, 20, 30:")
    stack.push(10)
    stack.push(20)
    stack.push(30)
    print(stack)
    
    print("\nPeek:", stack.peek())
    print("Size:", stack.size())
    
    print("\nPopping:")
    while not stack.is_empty():
        print(f"  Popped: {stack.pop()}")
    
    print("Empty again:", stack.is_empty())
