#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
   static bool isMatch(string s, string p) {
      int sidx = 0, pidx = 0;

      while (sidx < s.size() && pidx < p.size()) {
         if (p.at(pidx) == '.' || s.at(sidx) == p.at(pidx)) {
            sidx++;
            pidx++;
         } 
         else if (p.at(pidx) == '*') {
            if (p.at(pidx - 1) == '.') return true;
            while (s.at(sidx) == p.at(pidx - 1)) {
               sidx++;
            }
            pidx++;
         }
         else if (pidx == p.size() || (pidx < p.size() && p.at(pidx + 1) != '*')) {
            return false;
         }
      }

      return sidx == s.size() && pidx == p.size();
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

//            cout << "s: " << sidx << ", p: " << pidx << endl;