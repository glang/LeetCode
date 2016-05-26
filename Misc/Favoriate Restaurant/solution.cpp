#include <map>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

string fav_restaurant(vector<string> res1, vector<string> res2) {
    map<string, int> placeRank;

    for (int i = 0; i < res1.size(); ++i) {
        auto res2Pos = find(res2.begin(), res2.end(), res1[i]);
        if (res2Pos != res2.end()) { //only enter in map if restaruant in both lists
            placeRank[res1[i]] = i + (res2Pos - res2.begin()); //combined rank
        }
    }

    if (placeRank.empty()) { //no restaurants in common
        return "Yelpwich";
    }

    pair<string, int> min = *placeRank.begin();

    for (pair<string, int> item : placeRank) {
        if (item.second < min.second) { //update min
            min = item;
        }
    }

    return min.first; //name of min combined rank
}

int main() {
    vector<string> res1{"one", "two", "three"};
    vector<string> res2{"three", "nine", "two"};

    cout << fav_restaurant(res1, res2) << endl;
}