"""
Doubly linked list implementation and demo
"""

class Node:
    """Node for doubly linked list"""
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class DoublyLinkedList:
    """Doubly linked list with basic operations."""
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def insert_at_head(self, data):
        new_node = Node(data)
        new_node.next = self.head
        if self.head:
            self.head.prev = new_node
        self.head = new_node
        if self.tail is None:
            self.tail = new_node
        self.size += 1

    def insert_at_tail(self, data):
        new_node = Node(data)
        if self.tail:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node
        else:
            self.head = self.tail = new_node
        self.size += 1

    def search(self, key):
        current = self.head
        while current:
            if current.data == key:
                return True
            current = current.next
        return False

    def delete(self, key):
        current = self.head
        while current:
            if current.data == key:
                if current.prev:
                    current.prev.next = current.next
                else:
                    self.head = current.next
                if current.next:
                    current.next.prev = current.prev
                else:
                    self.tail = current.prev
                self.size -= 1
                return True
            current = current.next
        return False

    def traverse_forward(self):
        current = self.head
        while current:
            yield current.data
            current = current.next

    def traverse_backward(self):
        current = self.tail
        while current:
            yield current.data
            current = current.prev

    def __len__(self):
        return self.size


if __name__ == "__main__":
    dl = DoublyLinkedList()
    for v in [1, 2, 3]:
        dl.insert_at_tail(v)
    print("Forward:", list(dl.traverse_forward()))
    print("Backward:", list(dl.traverse_backward()))

    dl.insert_at_head(0)
    print("After insert_at_head(0) Forward:", list(dl.traverse_forward()))

    dl.delete(2)
    print("After delete(2) Forward:", list(dl.traverse_forward()))
    print("Length:", len(dl))
