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
        	auto iter = std::find(order.begin(), order.end(), key);
        	int val = *iter;
        	order.erase(iter);
        	order.push_front(val);

        	return cache[key];
        }
    }
    
    void set(int key, int value) {
		if (cache.size() == maxSize) {
			cache.erase(cache.find(order.back()));
			order.pop_back();
		}

		cache[key] = value;
		
		if (std::find(order.begin(), order.end(), key) != order.end()) {
			get(key);
		} else {
			order.push_front(key);
		}
    }

private:
	int maxSize;
	map<int, int> cache;
	list<int> order;
};