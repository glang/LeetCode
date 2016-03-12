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
            char prev = p.at(pidx - 1);
            if (prev == '.') {
               if (pidx == p.size() - 1)
                  return true;
               else {
                  while (sidx < s.size() && s.at(sidx) != p.at(pidx + 1))
                     sidx++;
                  if (sidx == s.size() && p.at(pidx + 1) != '.') 
                     return false;   
                  pidx++;                           
               }
            }
            while (sidx < s.size() && s.at(sidx) == prev)
               sidx++;
            while (pidx < p.size() - 1 && prev == p.at(pidx + 1))
               pidx++;

            pidx++;
         }
         else if (pidx == p.size() - 1 || (pidx < p.size() - 1 && p.at(pidx + 1) != '*'))
            return false;
         else 
            pidx++;
      }

      return sidx == s.size() && pidx == p.size();
   }
};

int main() {
   if (Solution::isMatch("aaaa", "a*aa")) {
      cout << "match" << endl;
   } else {
      cout << "not match" << endl;
   }

   return 0;
}

//.*a
//.*a*