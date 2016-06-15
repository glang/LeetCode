int maxProfit(vector<int> &A) {
	int maxProfit = 0, minSoFar = A[0];

	for (int i = 1; i < A.size() - 1; ++i) {
		maxProfit = max(maxProfit, A[i] - minSoFar);
		minSoFar = min(minSoFar, A[i]);
	}

	return maxProfit;
}

int main() {
	
}