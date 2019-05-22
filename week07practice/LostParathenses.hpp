#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Assuming input is always correct
using namespace std;

#ifndef LOSTPARATHENSES_H
#define LOSTPARATHENSES_H

static vector<string> ops;
class LostParathenses {
public:
	LostParathenses();
	int minResult(string e);
	int calc(vector<string>, vector<int>);
};
#endif

vector<int> parse_int(string s){
	vector<int> re;
	string temp = "";
	int n;
	for(int i = 0; i < int(s.length()); i++){
		if (s[i] != '+' and s[i] != '-' and isdigit(s[i])) temp += s[i];
		else {
			if (s[i] == '+') ops.push_back("add");
			else if (s[i] == '-') ops.push_back("sub");
			n = stoi(temp.c_str());
			re.push_back(n);
			temp = "";
		}
	}
	re.push_back( stoi(temp.c_str()) );
	return re;
}
LostParathenses::LostParathenses() {}

int LostParathenses::calc(vector<string> operands, vector<int> operators){
	int result;
	int ofBrack = operators[0];
	vector<int> sumList;
	for (int i = 0; i < operands.size(); i++){
		if (operands[i] == "add") ofBrack += operators[i + 1];
		else {
			sumList.push_back(ofBrack);
			ofBrack = operators[i + 1];
		}
	}
	sumList.push_back(ofBrack);
	result = sumList[0];
	return result;
}
int LostParathenses::minResult(string e) {
	return calc(ops, parse_int(e));
}

