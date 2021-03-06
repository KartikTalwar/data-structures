
class Set(object):

  def __init__(self):
    self.data = {}


  def add(self, value):
    if value not in self.data:
      self.data[value] = value


  def clear(self):
    self.data = {}


  def contains(self, value):
    if value in self.data:
      return True
    return False


  def equals(self, comp):
    if self.size() != comp.size():
      return False

    for item in self.data:
      if not comp.contains(item):
        return False

    return True


  def is_empty(self):
    return len(self.data) == 0


  def remove(self, value):
    if value in self.data:
      del self.data[value]


  def size(self):
    return len(self.data)


  def display(self):
    return self.data.keys()



if __name__ == '__main__':

  new_set = Set()
  new_set.add(1)
  new_set.add(3)
  new_set.add(3)
  new_set.add(4)

  cmp_set = Set()
  cmp_set.add(1)
  cmp_set.add(3)

  print new_set.display() == [1,3,4]
  print new_set.size() == 3
  new_set.remove(4)
  print new_set.display() == [1,3]
  print new_set.is_empty() == False
  print new_set.contains(3) == True
  print new_set.equals(cmp_set) == True
