/*
Array version
*/

#include <vector>
#include <queue>

using namespace std;

struct item {
	int data;
	int arraysIndex;
	int arrayIndex;

	bool operator>(item other) const {
		data > other.data;
	}
};

vector<int> mergeSortedArrays(vector<vector<int>> arrays) {
	vector<int> result;
	priority_queue<item, vector<item>, greater<item>> heap;

	for (int i = 0; i < arrays.size(); ++i) {
		heap.emplace(item{arrays[i][0], i, 0});
	}

	while (!heap.empty()) {
		item smallest = heap.top();
		heap.pop();
		result.push_back(smallest.data);
		if (smallest.arrayIndex < arrays[smallest.arraysIndex].size() - 1) {
			heap.emplace(item{arrays[smallest.arraysIndex][smallest.arrayIndex + 1], smallest.arraysIndex, smallest.arrayIndex + 1});
		}
	}

	return result;
}

int main() {}