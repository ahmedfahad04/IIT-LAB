class Node:
    def __init__(self, key):
        self.children = []
        self.value = key
        self.parent = None

    def add_child(self, childNode):
        childNode.parent = self
        self.children.append(childNode)

    def print_child(self):

        space = ' ' * self.get_level() * 2
        print(space + self.value)

        if self.children:
            for child in self.children:
                child.print_child()

    def get_level(self):

        level = 0
        p = self.parent
        while p is not None:
            level += 1
            p = p.parent

        return level


def build_tree():
    product = Node('Electronics')

    laptop = Node('Laptop')
    gaming_laptop = Node('Gaming Laptop')
    usual_laptop = Node('Usual Laptop')

    TV = Node('TV')
    TV.add_child(Node('HITACHI'))
    TV.add_child(Node('LG'))

    laptop.add_child(gaming_laptop)
    laptop.add_child(usual_laptop)

    gaming_laptop.add_child(Node('Asus'))
    gaming_laptop.add_child(Node('Gigabyte'))
    usual_laptop.add_child(Node('Dell'))
    usual_laptop.add_child(Node('Hp'))

    product.add_child(laptop)
    product.add_child(TV)
    product.print_child()


if __name__ == '__main__':
    build_tree()
