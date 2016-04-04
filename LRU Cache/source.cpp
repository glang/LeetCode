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
			order.erase(std::find(order.begin(), order.end(), key));
			order.push_front(key);
        	return cache[key];
        }
    }
    
    void set(int key, int value) {
		if (cache.size() == maxSize) {
			cache.erase(cache.find(order.back()));
			order.pop_back();
		}

		cache[key] = value;

        auto iter = std::find(order.begin(), order.end(), key);		
	
		if (iter != order.end()) {
			order.erase(iter);
		}
		
		order.push_front(key);
    }

private:
	int maxSize;
	map<int, int> cache;
	list<int> order;
};