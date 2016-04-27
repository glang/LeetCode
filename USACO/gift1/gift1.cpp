/*
ID: granger1
PROG: gift1
LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Money {
	int account;
	int given;
};

int main() {
	ifstream in("gift1.in");
	ofstream out("gift1.out");

	int NP;
	in >> NP;	
	
	unordered_map<string, Money> map;
	vector<string> insertOrder;

	for (int i = 0; i != NP; ++i) {
		string name;
		Money cash{};
		in >> name;
		map.emplace(name, cash);
		insertOrder.push_back(name);
	}

	for (int i = 0; i != NP; ++i) {
		string name;
		int totalMoney, numPeople, leftover = 0, dividedMoney;
		
		in >> name >> totalMoney >> numPeople;
		
		if (numPeople == 0) {
			continue;
		}
		
		leftover = totalMoney % numPeople;
		map.at(name).account += leftover;
		map.at(name).given = totalMoney;
		totalMoney -= leftover;
		dividedMoney = totalMoney / numPeople;
		
		for (int i = 0; i != numPeople; ++i) {
			string receiver;
			in >> receiver;
			map.at(receiver).account += dividedMoney;
		}
	}

	for (auto &x : insertOrder) {
		Money cur = map.at(x);
		out << x << " " << cur.account - cur.given << endl;
	}

	return 0;
}