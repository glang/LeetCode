 0   1  2  3   4    5
-6  -2  8  9  15  200

 0   1  2  3   4    5
-6  -2  0  1   2  200

//brute force
int magicIndex(int *array, int size) {
	for (int i = 0; i < size; ++i) {
		if (array[i] == i) {
			return i;
		}
	}

	return -1;
}

//optimized O(n) solution
int magicIndex(int *array, int size) {
	int i = 0;

	while (i < size) {
		if (array[i] == i) {
			return i;
		} else if (array[i] > i) {
			i = array[i];
		} else {
			++i;
		}
	}

	return -1;
}


//recursive solution
int magicIndex(int *array, int size) {
	return magicIndex(array, size, 0, size - 1)
}

int magicIndex(int *array, int size, int low, int high) {
	if (high < low || low < 0 || high > size - 1) {
		return -1;
	}  

	int mid = (low + high) / 2;
	int midVal = array[mid];
	int leftVal, rightVal;

	if (mid == midVal) {
		return mid;
	} else if (midVal < mid) {
		leftVal = magicIndex(low, midVal); 
		rightVal = magicIndex(mid + 1, high);
	} else {
		leftVal = magicIndex(low, mid - 1); 
		rightVal = magicIndex(midVal, high);
	}

	if (leftVal != -1) return leftVal;
	else if (rightVal != -1) return rightVal;
	else return -1;
}
