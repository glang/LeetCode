#include <unordered_map>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) : maxSize(capacity) {
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
        	return -1;
        } else {
			order.splice(order.begin(), order, cache[key].iter);
        	return cache[key].val;
        }
    }
    
    void set(int key, int value) {
		if (cache.size() == maxSize) {
			cache.erase(order.back());
			order.pop_back();
		}

		if (cache.find(key) != cache.end()) {
			cache[key].val = value;
			order.splice(order.begin(), order, cache[key].iter);
		} else {
			order.push_front(key);
			cache[key] = ValIter(value, order.begin());
		}
    }

private:
	struct ValIter {
		int val;
		list<int>::iterator iter;

		ValIter(int v, list<int>::iterator i) : val(v), iter(i) {
		}

		ValIter() {
		}
	};

	int maxSize;
	unordered_map<int, ValIter> cache;
	list<int> order;
};