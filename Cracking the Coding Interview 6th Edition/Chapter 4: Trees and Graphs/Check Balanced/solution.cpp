
//O(NlogN) verison

bool checkBalanced(shared_ptr<Node> root) {
   if (root == nullptr) {
      return true;
   }

   int leftTreeHeight = treeHeight(node->left);
   int rightTreeHeight = treeHeight(node->right);

   if (abs(leftTreeHeight - rightTreeHeight) > 1) {
      return false;
   } else {
      return checkBalanced(root->left) && checkBalanced(root->right);
   }
   
}

int treeHeight(shared_ptr<Node> node) {
   if (node == nullptr) {
      return 0;
   } 

   return 1 + max(treeHeight(node->left), treeHeight(node->right));
}

///O(N) version

bool checkBalanced(shared_ptr<Node> root) {
   if (root == nullptr) {
      return true;
   }

   return treeHeight(root->left) != INT_MIN && treeHeight(root->right) != INT_MIN;   
}

int treeHeight(shared_ptr<Node> node) {
   if (node == nullptr) {
      return 0;
   } 

   int leftTreeHeight = treeHeight(node->left);
   int rightTreeHeight = treeHeight(node->right);

   if (leftTreeHeight == INT_MIN || rightTreeHeight == INT_MIN || abs(leftTreeHeight - rightTreeHeight) > 1) {
      return INT_MIN;
   } else {
      return 1 + max(treeHeight(node->left), treeHeight(node->right));
   }
}

/*

     o
  o     o
o  o   o  o

*/