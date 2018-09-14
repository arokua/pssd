#include <iostream>
#include "KokoBananas.hpp"
#include <vector>

using namespace std;

int main() {
	KokoBananas K;
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);
	cout <<K.vecEqual(a)<<endl;
}