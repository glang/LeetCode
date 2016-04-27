/*
ID: granger1
PROG: transform
LANG: C++11
*/

#include <fstream>
#include <vector>

using namespace std;

void input(ifstream &in, int &N, vector<vector<char>> &matrix) {
	for (int i = 0; i < N; ++i) {
		string temp;
		
		in >> temp;
		matrix.push_back(vector<char>());

		for (int j = 0; j < N; ++j) {
			matrix.at(i).push_back(temp.at(j));
		}
	}
}

vector<vector<char>>& rotate90(vector<vector<char>> &orig) {
	vector<vector<char>> rotated;

	for (int i = 0; i < orig.size(); ++i) {
		vector<char> vec;
		
		for (int j = orig.at(0).size() - 1; j >= 0; --j) {
			vec.push_back(orig.at(j).at(i));
		}
		
		rotated.push_back(vec);
	}

	orig = rotated;
	return orig;
}

vector<vector<char>>& mirror(vector<vector<char>> &orig) {
	vector<vector<char>> mirror = orig;

	for (auto& vec : mirror) {
		for (int i = 0; i < mirror.size()/2; ++i) {
			char swap = vec.at(i);
			vec.at(i) = vec.at(vec.size() - i - 1);
			vec.at(vec.size() - i - 1) = swap;
		}
	}

	orig = mirror;
	return orig;
}

int main() {
	ifstream in("transform.in");
	ofstream out("transform.out");

	int N;
	vector<vector<char>> orig, final;
	in >> N;

	input(in, N, orig);
	input(in, N, final);

	for (int i = 0; i < 3; i++) {
		if (final == rotate90(orig)) {
			out << i + 1 << endl;
			return 0;
		}
		if (final == mirror(orig)) {
			out << 5 << endl;
			return 0;
		}
		mirror(orig);
	}

	if (final == rotate90(orig)) {
		out << 6 << endl;
		return 0;
	}
	if (final == mirror(orig)) {
		out << 4 << endl;
		return 0;
	}

	out << 7 << endl;

	return 0;
}