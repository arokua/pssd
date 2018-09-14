#include <iostream>
#include <vector>
#include "SimpleDuplicateRemover.hpp"

using namespace std;

int main(){
	SimpleDuplicateRemover A;

	vector<int> C;

	C.push_back(1);
	C.push_back(5);
	C.push_back(5);
	C.push_back(1);
	C.push_back(6);
	C.push_back(6);
	C.push_back(1);



	A.process(C);
	cout <<endl;
}