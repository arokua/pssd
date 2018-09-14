#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class KokoBananas {
public:
	vector<int> maxVec(vector<int> v){
		vector<int> re; // pos, val
		re.reserve(2);
		int c = 0;
		for (int i = 0; i < v.size(); i++) {
			c = max(c,v[i]);
			if (v[i] == c){
				re[0] = i;
				re[1] = c;
			}

		}

		return re;
	}

	vector<int> minVec(vector<int> v){
		vector<int> re; // pos, val
		re.reserve(2);
		int c = 0;
		for (int i = 0; i < v.size(); i++) {
			c = min(c,v[i]);
			if (v[i] == c){
				re[0] = i;
				re[1] = c;
			}

		}

		return re;
	}

	bool vecEqual(vector<int> v){
		int c = v[0];
		for (int i = 1; i < v.size(); i++){
			if (v[i] != c){
				return false;
			}
		}
		return true;
	}
	bool hasDuplicate(vector<int> v, int d){
		int counter = 0;
		for (int i = 1; i < v.size(); i++){
			if (v[i] == d){
				counter ++;
			}
		}
		if (counter > 1){
			return true;
		}
	}

	vector<int> findDuplicatePos(vector<int> a, int d2Pos){
		vector<int> z;
		int known = a[d2Pos];
		for (int i = 0; i < a.size(); i++){
			if (a[i] == known && i != d2Pos){
				z.push_back(i);
			}
		}

		return z;
	}	

	int n ;
	int lastHand(vector<int>hands, int K){

		if (!hasDuplicate(hands, maxVec(hands)[1]) ){
			n = maxVec(hands)[0];
		}else {

			n= minVec(findDuplicatePos(hands,maxVec(hands)[0]) )[0] ;
		}
		if (K == 0){
			return n;

		}



		else {
			hands[maxVec(hands)[0]] -= 1;
			return lastHand(hands, K -1);			
		}
		cout << n;
	}
};