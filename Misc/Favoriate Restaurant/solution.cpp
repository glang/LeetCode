#include <map>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
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

unordered_map<string, int> genPlaceRankMap(vector<string>& list) {
    unordered_map<string, int> placeMap;

    for (string s : list) {
        placeMap[s] = placeMap.size();
    }

    return placeMap;
}

string better_fav_res(vector<string>& res1, vector<string>& res2) {
    unordered_map<string, int> placeRank1 = genPlaceRankMap(res1);
    unordered_map<string, int> placeRank2 = genPlaceRankMap(res2);

    sort(res1.begin(), res1.end());
    sort(res2.begin(), res2.end());
    unordered_set<string> common;
    set_intersection(res1.begin(), res1.end(), res2.begin(), res2.end(), inserter(common, common.end()));

    int min = -1;
    string place = "Yelpwich";
    
    for (string s : common) {
        int itemRank = placeRank1[s] + placeRank2[s];
        if (min == -1 || itemRank < min) {
            min = itemRank;
            place = s;
        }
    }

    return place;
}

int main() {
    vector<string> res1{"one", "two", "three"};
    vector<string> res2{"three", "nine", "two"};

    cout << fav_restaurant(res1, res2) << endl;
    cout << better_fav_res(res1, res2) << endl;
}