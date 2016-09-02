/*
max heap of smaller half
min heap of larger half

3 1 4 1 5 9 2

[3] []
3

[3] [1]
[1] [3]
2

[1, 4] [3]
[1, 3] [4]
3

[1, 3] [1, 4]
[1, 1] [3, 4]
2

*/


int computeMedian(istream instream) {
	int i;
	priority_queue<int, vector<int>, less<>> smaller_half;
	priority_queue<int, vector<int>, greater<>> larger_half;
	bool even = true;

	while (instream >> i) {
		if (even) {
			smaller_half.emplace(i);
		} else {
			if (smaller_half.size() > larger_half.size()) {
				larger_half.emplace(i);
			} else {
				smaller_half.emplace(i);
			}
		}

		if (larger_half.empty()) {
			cout << i << " ";
			even = !even;
			continue;
		}

		if (smaller_half.top() > larger_half.top()) {
			int smaller_top = smaller_half.top();
			int larger_top = larger_half.top();
			smaller_half.pop();
			larger_half.pop();
			smaller_half.emplace(larger_top);
			larger_half.emplace(smaller_top);
		}

		even = !even;

		float median;

		if (even) {
			median = (smaller_half.top() + larger_half.top()) / 2.0;
		} else {
			median = smaller_half.size() > larger_half.size() ? smaller_half.top() : larger_half.top();
		}
			
		cout << median << " ";
	}

	cout << endl;
}