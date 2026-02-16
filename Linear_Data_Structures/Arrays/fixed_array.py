"""
Fixed Array Implementation
Manual size-limited array class to demonstrate memory thinking
"""

class FixedArray:
    """A fixed-size array implementation to demonstrate memory constraints"""
    
    def __init__(self, size):
        """Initialize a fixed-size array"""
        self.data = [None] * size
        self.size = size
        self.count = 0  # Number of elements actually stored
    
    def insert(self, value):
        """Insert element at the end if space available"""
        if self.count >= self.size:
            raise OverflowError("Array is full!")
        self.data[self.count] = value
        self.count += 1
    
    def insert_at(self, index, value):
        """Insert element at specific index"""
        if index > self.count or index < 0:
            raise IndexError("Invalid index!")
        if self.count >= self.size:
            raise OverflowError("Array is full!")
        
        # Shift elements to the right
        for i in range(self.count, index, -1):
            self.data[i] = self.data[i - 1]
        
        self.data[index] = value
        self.count += 1
    
    def delete(self, index):
        """Delete element at specific index"""
        if index >= self.count or index < 0:
            raise IndexError("Invalid index!")
        
        # Shift elements to the left
        for i in range(index, self.count - 1):
            self.data[i] = self.data[i + 1]
        
        self.data[self.count - 1] = None
        self.count -= 1
    
    def access(self, index):
        """Access element at specific index"""
        if index >= self.count or index < 0:
            raise IndexError("Invalid index!")
        return self.data[index]
    
    def is_full(self):
        """Check if array is full"""
        return self.count >= self.size
    
    def is_empty(self):
        """Check if array is empty"""
        return self.count == 0
    
    def get_capacity(self):
        """Get total capacity"""
        return self.size
    
    def get_count(self):
        """Get current element count"""
        return self.count
    
    def __str__(self):
        """String representation of array"""
        elements = [str(self.data[i]) for i in range(self.count)]
        return "[" + ", ".join(elements) + "]"


# Demonstration
if __name__ == "__main__":
    # Create fixed array of size 5
    arr = FixedArray(5)
    print(f"Created fixed array with capacity: {arr.get_capacity()}")
    
    # Insert elements
    print("\nInserting elements:")
    for i in range(1, 6):
        arr.insert(i * 10)
        print(f"  Inserted {i * 10}: {arr}")
    
    print(f"\nArray is full: {arr.is_full()}")
    
    # Try to insert when full (will raise error)
    try:
        arr.insert(100)
    except OverflowError as e:
        print(f"Error: {e}")
    
    # Access elements
    print("\nAccessing elements:")
    print(f"  Element at index 0: {arr.access(0)}")
    print(f"  Element at index 4: {arr.access(4)}")
    
    # Insert at specific position
    print("\nInserting 25 at index 1:")
    arr.delete(4)  # Make space first
    arr.insert_at(1, 25)
    print(f"  {arr}")
    
    # Delete element
    print("\nDeleting element at index 2:")
    arr.delete(2)
    print(f"  {arr}")
    
    print(f"\nCurrent count: {arr.get_count()}/{arr.get_capacity()}")
