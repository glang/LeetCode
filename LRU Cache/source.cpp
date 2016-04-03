#include <map>
#include <list>
#include <algorithm>

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
        	int temp = find(order.begin(), order.end(), key);

        	return cache[key];
        }
    }
    
    void set(int key, int value) {
    	if (cache.size() >= maxSize) {
    		cache.erase(cache.find(order.back()));
    		order.pop_back();
    	}

		cache[key] = value;
		order.push_front(key);
    }

private:
	int maxSize;
	map<int, int> cache;
	list<int> order;
};