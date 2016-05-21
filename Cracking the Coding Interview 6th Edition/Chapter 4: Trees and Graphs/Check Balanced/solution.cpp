bool checkBalanced(shared_ptr<Node> root) {
   if (root == nullptr) {
      return true;
   }

   return abs(treeHeight(root->left) - treeHeight(root->right)) > 1;
}

int treeHeight(shared_ptr<Node> node) {
   if (node == nullptr) {
      return 0;
   } 

   return max(treeHeight(node->left), treeHeight(node->right));
}

/*

     o
  o     o
o  o   o  o

*/