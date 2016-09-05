/*
Array version
*/

struct item {
	int data;
	int arraysIndex;
	int arrayIndex;

	bool operator>(item other) {
		data > other.data;
	}
}

vector<int> mergeSortedArrays(vector<vector<int>> arrays) {
	vector<int> result;
	priority_queue<item, vector<item>, greater<item>> = heap;

	for (int i = 0; i < arrays.size(); ++i) {
		heap.emplace(item{array[0], i, 0});
	}

	while (!head.empty()) {
		item smallest = heap.top();
		heap.pop();
		result.push_back(smallest.data);
		if (!heap.empty() && smallest.arrayIndex < arrays[smallest.arraysIndex].size() - 1) {
			heap.emplace(item{arrays[arraysIndex][smallest.arrayIndex + 1], smallest.arraysIndex, smallest.arrayIndex + 1});
		}
	}

	return result;
}