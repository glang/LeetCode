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
		int isOdd = size%2 == 1 ? 1 : 0;
		return bsearch(key, array, size/2 + isOdd, startIndex + size/2);
	}
}

int main() {
/*
	int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << bsearch(3, arr, 9, 0) << endl;
	cout << bsearch(4, arr, 9, 0) << endl;
	cout << bsearch(5, arr, 9, 0) << endl;
	cout << bsearch(1, arr, 9, 0) << endl;
	cout << bsearch(9, arr, 9, 0) << endl;
*/
	int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	cout << bsearch(3, arr, 8, 0) << endl;
	cout << bsearch(4, arr, 8, 0) << endl;
	cout << bsearch(5, arr, 8, 0) << endl;
	cout << bsearch(1, arr, 8, 0) << endl;
	cout << bsearch(8, arr, 8, 0) << endl;
}	

/*
[1 2 3 4] 5 [6 7 8 9]

bs(9, arr, 9, 0)
	midVal = arr[4] = 5
	bs(9, arr, 4, 5)
		midVal = arr[7] = 8;
		bs(8, arr, 2, 8);
			midVal = arr[9]; // out of range

*/