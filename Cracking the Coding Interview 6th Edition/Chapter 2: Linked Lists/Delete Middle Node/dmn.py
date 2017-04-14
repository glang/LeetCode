def delete_middle_node(node):
   node.data = node.next.data
   node.next = node.next.next