void minimalTree(const vector<int>& list, int low, int high, shared_ptr<Node> node) {
	if (high < low || high > list.size() - 1 || low < 0) {
      return;
   }

   int mid = low + (high - low) / 2;
	node->data = list.at(mid);
   node->left = make_shared<Node>();
   node->right = make_shared<Node>();

   minimalTree(list, low, mid - 1, node->left); //left
   minimalTree(list, mid + 1, high, node->right); //right
}

/*
     1 2 3 4 5 6 7 8

             5
        3         7
      2    4   6     8
    1
*/

int main() {
	auto root = make_shared<Node>();
	const vector<int> list({1, 2, 3, 4, 5, 6, 7, 8});

	minimalTree(list, 0, list.size() - 1, head);
}