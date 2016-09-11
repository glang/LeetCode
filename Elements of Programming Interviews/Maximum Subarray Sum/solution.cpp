int maxSumBruteForce(vector<int> &A) {
	int maxSum = A[0];
	int currentSum;

	for (int i = 0; i < A.size(); ++i) {
		currentSum = 0;
		for (int j = i; j < A.size(); ++j) {
			currentSum += A[j];
			maxSum = max(maxSum, currentSum);
		}
	}
}

int maxSumDP(vector<int> &A) {
	int maxSum = A[0], currentSum = A[0];

	for (int i = 1; i < A.size(); ++i) {
		currentSum = max(A[i], currentSum);
		maxSum = max(maxSum, currentSum);
	}

	return maxSum;
}