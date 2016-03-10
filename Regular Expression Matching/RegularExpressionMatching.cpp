#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
   static bool isMatch(string s, string p) {
      char sidx = 0, pidx = 0;

      if (p.at(pidx) == '.' || 
         (((pidx + 1 < p.size() && p.at(pidx + 1) != '*')
          || pidx == p.size() - 1) && s.at(sidx) == p.at(pidx))) {
         sidx++;
         pidx++;
      } else {
         return false;
      }

      return true;
   }
};

int main() {
   if (Solution::isMatch("test", "tesg")) {
      cout << "match" << endl;
   } else {
      cout << "not match" << endl;
   }

   return 0;
}