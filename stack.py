
class Stack(object):

  def __init__(self):
    self.data = []

  def push(self, value):
    self.data.append(value)

  def pop(self):
    if len(self.data) > 0:
      last = self.data[len(self.data)-1]
      del self.data[len(self.data)-1]
      return last

  def peek(self):
    return self.data[len(self.data)-1]

  def empty(self):
    return len(self.data) == 0



if __name__ == '__main__':

  stk = Stack()
  stk.push(1)
  stk.push(2)
  stk.push(3)
  print stk.pop() == 3
  print stk.peek() == 2
  stk.pop()
  stk.pop()
  print stk.empty() == True
  

