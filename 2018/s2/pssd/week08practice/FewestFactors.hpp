#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class FewestFactors {
public:
	int baseNTo(int n, int power){
		int ans = 1;
		if (power == 0){
			return 1;
		}
		for (int i = 0; i < power; i++){
			ans *= n;
		}
		return ans;
	}

	int makeNums(vector<int> digits){
		int num = 0;
		for (int i = digits.size() - 1; i > -1; i--){
			num += digits[i]* baseNTo(10,digits.size() - i - 1);
			
		}
		return num;
	}

	bool checkPrime(int n){
		for (int i = 2; i < (n / 2) + 1; i++){
			if (n % i == 0){
				return false;
			}
		}
		return true;
	}

	int nFactor(int n){
		if (checkPrime(n)){
			return 2;
		}
		int re = 2;
		for (int i = 2; i < n / 2; i ++){
			if (n % i == 0){
				re++;
			}
		}
		return re;
	}

	int number(vector<int> digits){
		sort(digits.begin(), digits.end());
		int currentNum = makeNums(digits);
		int currentFac = nFactor(currentNum);
		int minN = currentNum;
		int minF = currentFac;
		
		int compare = 0;
        
		while (next_permutation(digits.begin(), digits.end())){
		    currentNum = makeNums(digits);
		    currentFac = nFactor(currentNum);
		    
		    if ( minF == currentFac){
		        minN = min(currentNum, minN);
		    }else if (minF > currentFac){
		        minF = currentFac;
		        minN = currentNum;
		    }
		}
		
		return minN;
	}
};