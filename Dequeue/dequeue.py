
class Dequeue(object):

  def __init__(self):
    self.data = []


  def add_front(self, item):
    self.data.insert(0, item)


  def add_rear(self, item):
    self.data.append(item)


  def remove_front(self):
    return self.data.pop(0)


  def remove_rear(self):
    return self.data.pop()


  def is_empty(self):
    self.data == []


  def size(self):
    return len(self.data)



if __name__ == '__main__':

  q = Dequeue()
  q.add_front(2)
  q.add_front(1)
  q.add_rear(3)
  q.add_rear(4)
  print q.remove_front()
  print q.remove_rear()

