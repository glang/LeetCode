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
        	cache[key][1]++;
        	return cache[key][0]);
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
	map<int, vector<int>> cache;
};