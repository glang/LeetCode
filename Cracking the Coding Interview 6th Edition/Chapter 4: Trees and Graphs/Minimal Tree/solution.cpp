void minimalTree(const vector<int>& list, int low, int high, shared_ptr<Node> node) {
	int midIdx = low + (high - low) / 2;
	auto newNode = make_shared<Node>(list.at(midIdx));

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