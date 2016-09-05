/*
        5
    3        3
  1   2    2    1

*/

#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

bool isSymm(Node *root) {
	return !root || checkSymm(root->left, root->right);
}

bool checkSymm(Node *left, Node *right) {
	if (!left && !right) {
		return true;
	} else if (left && right) {
		return left->data == right->data &&
		 checkSymm(left->left, right->right) &&
		 checkSymm(left->right, right->left);
	} else {
		return false;
	}
}