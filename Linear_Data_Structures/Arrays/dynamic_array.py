"""
Dynamic Array Implementation
Simulate dynamic array resizing manually (like ArrayList in Java or vector in C++)
"""

class DynamicArray:
    """A dynamic array that automatically resizes when capacity is reached"""
    
    def __init__(self, initial_capacity=2):
        """Initialize dynamic array with initial capacity"""
        self.data = [None] * initial_capacity
        self.capacity = initial_capacity
        self.size = 0
    
    def resize(self, new_capacity):
        """Resize array to new capacity"""
        new_data = [None] * new_capacity
        
        # Copy existing elements
        for i in range(self.size):
            new_data[i] = self.data[i]
        
        self.data = new_data
        self.capacity = new_capacity
        print(f"  [Resized array from capacity {len(self.data)} // 2 to {new_capacity}]")
    
    def append(self, value):
        """Add element at the end"""
        # If full, double the capacity
        if self.size >= self.capacity:
            self.resize(self.capacity * 2)
        
        self.data[self.size] = value
        self.size += 1
    
    def insert_at(self, index, value):
        """Insert element at specific index"""
        if index > self.size or index < 0:
            raise IndexError("Invalid index!")
        
        # Resize if necessary
        if self.size >= self.capacity:
            self.resize(self.capacity * 2)
        
        # Shift elements to the right
        for i in range(self.size, index, -1):
            self.data[i] = self.data[i - 1]
        
        self.data[index] = value
        self.size += 1
    
    def delete(self, index):
        """Delete element at specific index"""
        if index >= self.size or index < 0:
            raise IndexError("Invalid index!")
        
        # Shift elements to the left
        for i in range(index, self.size - 1):
            self.data[i] = self.data[i + 1]
        
        self.size -= 1
        
        # Shrink if necessary (if size is 1/4 of capacity)
        if self.size > 0 and self.size <= self.capacity // 4:
            self.resize(self.capacity // 2)
    
    def access(self, index):
        """Access element at specific index"""
        if index >= self.size or index < 0:
            raise IndexError("Invalid index!")
        return self.data[index]
    
    def get_capacity(self):
        """Get current capacity"""
        return self.capacity
    
    def get_size(self):
        """Get current size"""
        return self.size
    
    def __str__(self):
        """String representation of array"""
        elements = [str(self.data[i]) for i in range(self.size)]
        return "[" + ", ".join(elements) + "]"


# Demonstration
if __name__ == "__main__":
    arr = DynamicArray(initial_capacity=2)
    print(f"Created dynamic array with initial capacity: {arr.get_capacity()}")
    
    # Demonstrate auto-resizing by appending elements
    print("\nAppending elements (watch for resizing):")
    for i in range(1, 9):
        print(f"Appending {i * 10}...")
        arr.append(i * 10)
        print(f"  Size: {arr.get_size()}, Capacity: {arr.get_capacity()}, Array: {arr}")
    
    # Access elements
    print("\nAccessing elements:")
    print(f"  Element at index 0: {arr.access(0)}")
    print(f"  Element at index 7: {arr.access(7)}")
    
    # Insert at specific position
    print("\nInserting 25 at index 2:")
    arr.insert_at(2, 25)
    print(f"  Size: {arr.get_size()}, Capacity: {arr.get_capacity()}, Array: {arr}")
    
    # Delete element and watch shrinking
    print("\nDeleting elements (watch for shrinking):")
    while arr.get_size() > 2:
        arr.delete(arr.get_size() - 1)
        print(f"  Size: {arr.get_size()}, Capacity: {arr.get_capacity()}, Array: {arr}")
