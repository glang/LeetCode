#include <map>
#include <vector>

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
        	return cache[key];
        }
    }
    
    void set(int key, int value) {
    	if (cache.size() < maxSize) {
    		cache[key] = value;
    	} else {

    	}
    }

private:
	int maxSize;
	map<int, int> cache;
};