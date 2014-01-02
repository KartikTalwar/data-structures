
class PriorityQueueList:

  def __init__(self):
    self.data = []
    self.min_index = None
    self.min_value = None


  def insert(self, data):
    if self.min_index == None:
      self.min_index = 0
      self.min_value = data
      self.data.append(data)
    else:
      if data < self.min_value:
        self.min_value = data
        self.min_index = len(self.data)

      self.data.append(data)


  def peek_min(self):
    if len(self.data) > 0:
      return self.data[self.min_index]


  def remove_min(self):
    if len(self.data) < 1:
      return

    del self.data[self.min_index]

    new_min = self.data[0]

    for i in range(len(self.data)):
      if self.data[i] < new_min:
        new_min = self.data[i]
        self.min_value = new_min
        self.min_index = i



if __name__ == '__main__':

  queue = PriorityQueueList()
  queue.insert(2)
  queue.insert(1)
  queue.insert(0.4)
  queue.insert(4)

  print 'Peeking min:', queue.peek_min()
  print 'Removing min:', queue.remove_min()
  print 'Peeking min:', queue.peek_min()

