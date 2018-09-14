#include <iostream>
#include "KokoBananas.hpp"
#include <vector>

using namespace std;

int main() {
	KokoBananas K;
	vector<int> a;
	a.push_back(4);
	a.push_back(9);
	a.push_back(5);
	
	cout <<K.lastHand(a,18)<<endl;
}