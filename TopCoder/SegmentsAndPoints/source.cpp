#include <vector>
#include <string>
using namespace std;
 
class SegmentsAndPoints {
public:
    string isPossible(vector <int> p, vector <int> l, vector <int> r) {
      for (int i = 0; i < p.size(); ++i) {
            int found = false;
            for (int j = 0; j < p.size(); ++j) {
                if (p[i] >= l[j] && p[i] <= r[j]) {
          found = true;
                    break;
                }    
            }
            if (!found)
                return "Impossible";
        }
        
        return "Possible";
    }
};