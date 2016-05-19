#include <list>
#include <forward_list>
#include <string>
#include <memory>

using namespace std;

struct Node {
	int val;
	shared_ptr<Node> next;

	Node(int value) : val(value) {};
};

list<int> sumList(list<int> A, list<int> B) {
	int carry = 0;
	list<int> result;
	list<int>::iterator aIter = A.begin();
	list<int>::iterator bIter = B.begin();

	while (aIter != A.end() && bIter != B.end()) {
		int sum = carry;

		if (aIter != A.end()) {
			sum += *aIter;
			++aIter;
		}

		if (bIter != B.end()) {
			sum += *bIter;
			++bIter;
		}

		if (sum > 9) {
			carry = 1;
			result.push_back(sum - 10);
		} else {
			carry = 0;
			result.push_back(sum);
		}
	}

	if (carry == 1) {
		result.push_back(1);
	}

	return result;
}


typedef shared_ptr<Node> sp;

void sumListsRecurse(list<sp> result, sp Anode, sp Bnode, int prevcarry) {
	if (Anode == nullptr && Bnode == nullptr && prevcarry == 0) {
		return;
	}

   int sum = prevcarry;

   if (Anode != nullptr) {
      sum += Anode->val;
   }

   if (Bnode != nullptr) {
      sum += Bnode->val;
   }

   int carry = 0;

   if (sum > 9) {
   	carry = 1;
   	sum = sum - 10;
   }

   result.push_back(make_shared<Node>(sum));
   sumListsRecurse(result, Anode != nullptr ? Anode->next : nullptr, Bnode != nullptr ? Bnode->next : nullptr, carry);
}


//solution if order is switched, where 123 is 1 -> 2 -> 3

list<int> sumListsReverse(forward_list<int> A, forward_list<int> B) {
	string Astring(A.begin(), A.end()), Bstring(B.begin(), B.end());
	int Anum = stoi(Astring), Bnum = stoi(Bstring);
	int sum = Anum + Bnum;
	string sumString = "" + sum;
	return list<int>(sumString.begin(), sumString.end());
}

/*
9 9 9
1
0 0 0 1

9 9 9 
1
1 0 0 0
*/

/*
sum lists

9 9 9
2 1
*/
int main() {
	
}