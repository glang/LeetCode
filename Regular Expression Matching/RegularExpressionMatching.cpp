#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
   static bool isMatch(string s, string p) {
      int sidx = 0, pidx = 0;

      for (int i = 0; i < p.size(); ++i) {
         if (p.at(pidx) == '.' || 
            (((pidx + 1 < p.size() && p.at(pidx + 1) != '*')
             || pidx == p.size() - 1) && s.at(sidx) == p.at(pidx))) {
            cout << "s: " << sidx << ", p: " << pidx << endl;
            sidx++;
            pidx++;
         } else {
            return false;
         }
      }

      return true;
   }
};

int main() {
   if (Solution::isMatch("test", "test")) {
      cout << "match" << endl;
   } else {
      cout << "not match" << endl;
   }

   return 0;
}