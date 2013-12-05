
class Queue(object):

  def __init__(self):
    self.data = []


  def is_empty(self):
    return len(self.data) == 0


  def dequeue(self):
    return self.data.pop()


  def enqueue(self, item):
    #self.data.insert(0, item)
    temp = []
    temp.append(item)

    for i in self.data:
      temp.append(i)

    self.data = temp


  def size(self):
    return len(self.data)



if __name__ == '__main__':

  q = Queue()
  q.is_empty()
  q.enqueue(2)
  q.enqueue(3)
  print q.dequeue()
  print q.dequeue()

