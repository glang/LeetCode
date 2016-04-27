#include <vector>
 
using namespace std;
 
class TreeAndVertex{
public:
      int get(vector <int> tree) {
      int max = 1;
        
        for (int i = 0; i < tree.size(); ++i) {
            int cur = 1;
            for (int j = 0; j < tree.size() - 1; ++j) {
                if (tree[j] == i)
                    ++cur;
            }
            
            max = std::max(max, cur);
        }
        
        return max;
    }
};