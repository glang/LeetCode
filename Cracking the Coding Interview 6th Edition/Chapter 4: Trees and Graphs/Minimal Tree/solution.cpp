#include <vector>
#include <iostream>
#include <memory>

using namespace std;

struct Node {
	int data;
	shared_ptr<Node> left, right;

	Node(int val) : data(val) {};
};

shared_ptr<Node> minimalTree(const vector<int>& list, int low, int high) {
	if (high < low || high > list.size() - 1 || low < 0) {
      return nullptr;
   }

   int mid = low + (high - low) / 2;
	auto newNode = make_shared<Node>(list.at(mid));

   newNode->left = minimalTree(list, low, mid - 1);
   newNode->right = minimalTree(list, mid + 1, high);

   return newNode;
}

/*
      0 1 2 3 4 5 6 7

             3
        1         5
     0     2   4     6
                       7
            
*/

void print_pre(shared_ptr<Node> node) {
	if (node != nullptr) {
		cout << node->data << endl;
		print_pre(node->left);
		print_pre(node->right);
	}
}

int main() {
	const vector<int> list({0, 1, 2, 3, 4, 5, 6, 7});

	auto root = minimalTree(list, 0, list.size() - 1);
	print_pre(root);
}
