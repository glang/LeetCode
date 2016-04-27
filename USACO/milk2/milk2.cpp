/*
ID: granger1
PROG: milk2
LANG: C++11
*/

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
	int a;
	int b;
};

bool smallerA(Pair first, Pair second) {
	return first.a < second.a || (first.a == second.a && first.b <= second.b);
}

int main() {
	ifstream in("milk2.in");
	ofstream out("milk2.out");

	int n, work, idle = 0;
	in >> n;

	vector<Pair> list;

	for (int i = 0; i != n; ++i) {
		Pair temp;
		in >> temp.a >> temp.b;
		list.push_back(temp);
	}

	sort(list.begin(), list.end(), smallerA);

	Pair beg = list.at(0), prev, cur;
	prev = beg;
	work = beg.b - beg.a;

	for (int i = 1; i != n; ++i) {
		cur = list.at(i);

		if (beg.b >= cur.b) // if cur is within the range of beg
			continue;
		if (cur.a > prev.b) { // if a gap exists
			if (idle < cur.a - prev.b)
				idle = cur.a - prev.b;
			if (work < prev.b - beg.a)
				work = prev.b - beg.a;
			beg = cur;
		} else {
			beg.b = cur.b;
		}

		prev = cur;
	}

	if (n == 1)
		idle = 0;

	out << work << " " << idle << endl;

	return 0;
}