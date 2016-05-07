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
		return bsearch(key, array, size/2 + isOdd, startIndex + size/2);
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
	cout << bsearch(2, arr2, 9, 0) << endl;
	cout << bsearch(3, arr2, 9, 0) << endl;
	cout << bsearch(4, arr2, 9, 0) << endl;
	cout << bsearch(1, arr2, 9, 0) << endl;
	cout << bsearch(7, arr2, 9, 0) << endl;
}