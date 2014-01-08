
class Tree:

  def __init__(self, root):
    self.value = root
    self.root  = None
    self.left  = None
    self.right = None


  def insert_left(self, value):
    temp = Tree(value)
    if self.left == None:
      temp.root = self.root
    else:
      temp.root = self.left
    self.left  = temp


  def insert_right(self, value):
    temp = Tree(value)
    if self.right == None:
      temp.root = self.root
    else:
      temp.root = self.right
    self.right  = temp


  def get_left(self):
    if self.left:
      return self.left
    return None


  def get_right(self):
    if self.right:
      return self.right
    return None


  def get_parent(self, node):
    return self.root


  def search(self, value):
    found = False
    left  = self.left
    right = self.right

    if self.value == value:
     found = True

    while left != None and right != None and found == False:
      if left.value == value:
        found = True
      else:
        left = left.root

      if right.value == value:
        found = True
      else:
        right = right.root

    return found



if __name__ == '__main__':

  tree = Tree(2)
  tree.insert_left(4)
  tree.insert_right(5)
  tree.insert_left(16)
  tree.insert_right(26)

  print tree.search(2)
  print tree.get_left().value
  print tree.get_left().root.value
