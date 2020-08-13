class ListNode:
    def __init__(self,data):
        self.data =data
        self. next = None
        return
    
    def has_value(self,value):
        if self.data == value:
            return True
        else:
            return False

class SingleLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        return

    def add(self,num):
        
        if not isinstance(num, ListNode):
            num = ListNode(num)
        if self.head is None:
            self.head = num
        else:
            self.tail.next = num
        
        self.tail = num
        return

    def lengthOfLinkedList(self):
        count = 0 
        currentNode =self.head
        while currentNode is not None:
            count += 1
            currentNode = currentNode.next
        return count

    def output_list(self):
        currentNode =self.head
        while currentNode is not None:
            print(currentNode.data)
            currentNode = currentNode.next
        return
    
node1 = ListNode(15)
node2 = ListNode(8.2)
item3 = "Berlin"
node4 = ListNode(15)

track = SingleLinkedList()
print("track length: %i" % track.lengthOfLinkedList())

for current_item in [node1, node2, item3, node4]:
    track.add(current_item)
    print("track length: %i" % track.lengthOfLinkedList())
    track.output_list()
