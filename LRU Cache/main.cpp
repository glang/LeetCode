#include "source.cpp"
#include <iostream>

using namespace std;

int main() {
	LRUCache cache(10);
	cache.set(1, 10);
	cache.set(2, 20);

	cout << cache.get(2) << endl << cache.get(1) << endl;

	return 0;
}