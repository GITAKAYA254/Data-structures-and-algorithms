"""
Stack implementation using Python list (array-based).
Time Complexity: Push O(1), Pop O(1), Peek O(1)
"""


class Stack:
    """Stack implementation using Python list."""
    
    def __init__(self):
        """Initialize an empty stack."""
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

    def __str__(self):
        """String representation of the stack."""
        return f"Stack({self.items})"


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
