#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n;
    cin >> n;
    
    string letters;
    for (int i = 0; i < 26; i++) {
        letters.push_back('a' + i);
    }
    
    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        sort(line.begin(), line.end());
        
        string intersect;
        back_insert_iterator<string> insIter(intersect);
        set_intersection(letters.begin(), letters.end(), line.begin(), line.end(), insIter);
        letters = intersect;
    }
    
    cout << letters.size() << endl;
    
    return 0;
}
