#include <iostream>
#include "KokoBananas.hpp"
#include <vector>

using namespace std;

int main() {
	KokoBananas K;
	vector<int> a;
	a.push_back(5);
	a.push_back(8);
	a.push_back(0);
	
	cout <<K.lastHand(a,4)<<endl;
}