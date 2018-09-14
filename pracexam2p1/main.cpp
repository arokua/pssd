#include <iostream>
#include "KokoBananas.hpp"
#include <vector>

using namespace std;

int main() {
	KokoBananas K;
	vector<int> a;
	a.push_back(13);
	a.push_back(75);
	a.push_back(24);
	a.push_back(55);


	cout <<K.lastHand(a,140)<<endl;
}