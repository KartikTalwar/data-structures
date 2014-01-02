
class Node:

  def __init__(self, value=None, next=None):
    self.data = value
    self.next = next


  def get_value(self):
    return self.data


  def get_next(self):
    return self.next


  def set_value(self, value):
    self.data = value


  def set_next(self, next):
    self.next = next



class SinglyLinkedList:

  def __init__(self):
    self.head = None


  def is_empty(self):
    return self.head == None


  def insert(self, value):
    self.head = Node(value, self.head)


  def length(self):
    curr  = self.head
    count = 0

    while curr != None:
      count += 1
      curr = curr.get_next()

    return count


  def contains(self, value):
    curr  = self.head
    found = False

    while curr != None and found == False:
      if curr.get_value() == value:
        found = True
      else:
        curr = curr.get_next()

    return found


  def remove(self, value):
    curr = self.head
    prev = None
    found = False

    while found == False:
      if curr.get_value() == value:
        found = True
      else:
        prev = curr
        curr = curr.get_next()

    if prev == None:
      self.head = curr.get_next()
    else:
      prev.set_next(curr.get_next())


  def reverse(self):
    curr = self.head
    last = None

    while curr != None:
      nxt = curr.get_next()
      curr.set_next(last)
      last = curr
      curr = nxt

    self.head = last


  def display(self):
    curr = self.head
    data = []

    while curr != None:
      data.append(curr.get_value())
      curr = curr.get_next()

    print data



if __name__ == '__main__':

  ll = SinglyLinkedList()
  ll.insert(3)
  ll.insert(2)
  ll.insert(42)
  ll.insert(4)

  print 'Length:', ll.length()
  print 'Searching 42:', ll.contains(42)
  print 'Removing 42:', ll.remove(42)
  print 'Searching 42:', ll.contains(42)

  ll.display()
  print 'Reversing:', ll.reverse()
  ll.display()

