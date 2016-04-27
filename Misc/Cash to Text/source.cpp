#include <iostream>
#include <vector>

using namespace std;

vector<string> englishOnes = {"and", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> englishTens = {"", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninty"};
vector<string> englishTeens = {"ten", "eleven", "twelve", "thriteen", "fourteen", "fifteen", "sisteen", "seventeen", "eighteen", "nineteen"};

string toText(int number) {
	string res = "";
	int hundred = number / 100;
	int ten = number % 100 / 10;
	int ones = number % 10;

	if (hundred > 0)
		res += englishOnes.at(hundred) + " hundred ";
	if (ten > 1)
		res += englishTens.at(ten) + " ";
	if (ten == 1)
		res += englishTeens.at(ones) + " "; 
	else if (ones > 0)
		res += englishOnes.at(ones) + " ";

	return res;
}

string cash2text(unsigned long long input) {
	string res = "";

	int tril = input / 1000000000000;
	int bil = input / 1000000000 % 1000;
	int mil = input / 1000000 % 1000;
	int thous = input / 1000 % 1000;
	int ones = input % 1000;

	if (tril > 0)
		res += toText(tril) + "trillion ";
	if (bil > 0)
		res += toText(bil) + "billion ";
	if (mil > 0)
		res += toText(mil) + "million ";
	if (thous > 0)
		res += toText(thous) + "thousand ";
	if (ones > 0)
		res += toText(ones);

	return res;
}

int main() {
	cout << cash2text(111111111111111) << endl;
}