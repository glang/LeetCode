/*
ID: granger1
LANG: C++
TASK: test
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream in("test.in");
	ofstream out("test.out");
	int a, b;

	in >> a >> b;
	out << a + b << endl;

	return 0;
}