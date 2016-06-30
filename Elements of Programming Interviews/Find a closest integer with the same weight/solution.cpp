/*

100111000

*/

#include <iostream>

unsigned long closestWithSameWeight(unsigned long input) {
  int size = sizeof(input);
  for (int i = 0; i < size - 1; ++i) {
    if (((input >> i) & 1) != ((input >> (i + 1)) & 1)) {
      input ^= (1UL << i) | (1UL << (i + 1));
      return input;
    }
  }
}

int main() {
	std::cout << closestWithSameWeight(7UL) << std::endl;
	return 0; 
}