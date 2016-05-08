/*
PROBLEM: Implement a function to perform a binary search on a sorted array
of integers to find the index of a given integer. Comment on the efficiency of this
search, and compare it with other search methods.
*/

#include <iostream>

using namespace std;

int bsearch(int key, int* array, int size, int startIndex) {
	int midVal = array[startIndex + size/2];

	if (midVal == key) {
		return startIndex + size/2; 
	} else if (key < midVal) {
		return bsearch(key, array, size/2, startIndex);
	} else {
		int isOdd = size%2 ? 0 : 1;
		return bsearch(key, array, size/2, startIndex + size/2 + isOdd);
	}
}

int bsearchIter(int key, int *array, int size) {
	int low = 0, high = size - 1, mid = size / 2;

	while(1) {
		int midVal = array[mid];

		if (midVal == key) {
			return mid;
		} else if (key < midVal) {
			high = mid - 1;
			mid = low + (high - low) / 2;
		} else {
			low = mid + 1;
			mid = low + (high - low) / 2;
		}
	}
}

int main() {
	int arr[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	cout << bsearch(2, arr, 9, 0) << endl;
	cout << bsearch(3, arr, 9, 0) << endl;
	cout << bsearch(4, arr, 9, 0) << endl;
	cout << bsearch(1, arr, 9, 0) << endl;
	cout << bsearch(8, arr, 9, 0) << endl;

	int arr2[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	cout << bsearch(2, arr2, 8, 0) << endl;
	cout << bsearch(3, arr2, 8, 0) << endl;
	cout << bsearch(4, arr2, 8, 0) << endl;
	cout << bsearch(1, arr2, 8, 0) << endl;
	cout << bsearch(7, arr2, 8, 0) << endl;

	int arr3[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	cout << bsearchIter(2, arr3, 9) << endl;
	cout << bsearchIter(3, arr3, 9) << endl;
	cout << bsearchIter(4, arr3, 9) << endl;
	cout << bsearchIter(1, arr3, 9) << endl;
	cout << bsearchIter(8, arr3, 9) << endl;

	int arr4[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	cout << bsearchIter(2, arr4, 8) << endl;
	cout << bsearchIter(3, arr4, 8) << endl;
	cout << bsearchIter(4, arr4, 8) << endl;
	cout << bsearchIter(1, arr4, 8) << endl;
	cout << bsearchIter(7, arr4, 8) << endl;
}