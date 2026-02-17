"""
Singly linked list implementation and demo
"""

class Node:
    """Node for singly linked list"""
    def __init__(self, data):
        self.data = data
        self.next = None


class SinglyLinkedList:
    """Singly linked list with basic operations."""
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def insert_at_head(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
        if self.tail is None:
            self.tail = new_node
        self.size += 1

    def insert_at_tail(self, data):
        new_node = Node(data)
        if self.tail:
            self.tail.next = new_node
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
        prev = None
        current = self.head
        while current:
            if current.data == key:
                if prev:
                    prev.next = current.next
                else:
                    self.head = current.next
                if current == self.tail:
                    self.tail = prev
                self.size -= 1
                return True
            prev = current
            current = current.next
        return False

    def traverse(self):
        current = self.head
        while current:
            yield current.data
            current = current.next

    def __len__(self):
        return self.size


if __name__ == "__main__":
    lst = SinglyLinkedList()
    for v in [10, 20, 30]:
        lst.insert_at_tail(v)
    print("Initial list:", list(lst.traverse()))

    lst.insert_at_head(5)
    print("After insert_at_head(5):", list(lst.traverse()))

    lst.insert_at_tail(40)
    print("After insert_at_tail(40):", list(lst.traverse()))

    print("Search 30:", lst.search(30))
    print("Delete 20:", lst.delete(20))
    print("After delete(20):", list(lst.traverse()))
    print("Length:", len(lst))
