#include <vector>
#include <algorithm>

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
	int n ;
	int lastHand(vector<int>hands, int K){
		n = maxVec(hands)[0];
		if (K == 0){
			return n;

		}



		else {
			if (!hasDuplicate( hands, maxVec(hands)[1] ) ){
				hands[maxVec(hands)[0]] -= 1;
				return lastHand(hands, K -1);
			}

			
		}
	}
};