class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.level = 0
        self.data = key

    def addNode(self, leafNode):

        p = self
        # print("P:",p.data, ", L:",leafNode.data)

        if leafNode.data < p.data:
            if self.left is None:
                self.left = leafNode
                self.level = 1
                # print("New Left: ", leafNode.data)

            else:
                self.left.addNode(leafNode)
                self.level += 1
                # print("Left: ", leafNode.data)
        else:
            if self.right is None:
                self.right = leafNode
                # print("New Right ", leafNode.data)

            else:
                self.right.addNode(leafNode)
                # print("Right: ", leafNode.data)


def inOrderTraverse(node):
    if node is not None:
        inOrderTraverse(node.left)
        print(node.data, end=' ')
        inOrderTraverse(node.right)


def height(node):
    if node is None:
        return 0
    else:
        return 1 + max(height(node.left), height(node.right))


root = Node(3)
root.addNode(Node(2))
root.addNode(Node(4))
root.addNode(Node(1))
root.addNode(Node(15))
root.addNode(Node(10))
root.addNode(Node(16))

inOrderTraverse(root)
print("Height: ", height(root))
