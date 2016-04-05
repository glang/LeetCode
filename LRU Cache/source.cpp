#include <map>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
    	maxSize = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
        	return -1;
        } else {
			order.splice(order.begin(), order, std::find(order.begin(), order.end(), key));
        	return cache[key];
        }
    }
    
    void set(int key, int value) {
		if (cache.size() == maxSize) {
			cache.erase(order.back());
			order.pop_back();
		}

		cache[key] = value;

        auto iter = std::find(order.begin(), order.end(), key);		
	
		if (iter != order.end()) {
			order.splice(order.begin(), order, iter);
		} else {
			order.push_front(key);
		}
    }

private:
	int maxSize;
	map<int, KeyIter> cache;
	list<int> order;

	struct KeyIter {
		int key;
		list<int>::iterator iter;

		KeyIter(int k, list<int>::iterator i) : key(k), iter(i) {
		}
	};
};