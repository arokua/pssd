#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class TimeTravellingCellar{
	private:
		vector<int> getMax(vector<int> v){
			vector<int> re1 ;
			re1.reserve(2);
			re1[0] = -1;
			for (int i = 0; i < v.size() ;i++){
				re1[0] = max(re1[0], v[i]);
				if (re1[0] == v[i]){
				    re1[1] = i;
				}
			}

			return re1;
		}
		
		vector<int> getMin(vector<int> v){
			vector<int> re2 ;
			re2.reserve(2);
			re2[0] = 10000000;
			for (int i = 0; i < v.size() ;i++){
				re2[0] = min(re2[0], v[i]);
				if (re2[0] == v[i]){
				    re2[1] = i;
				}
			}

			return re2;
		}

		
	public:
		int determineProfit(vector<int> profit, vector<int> decay){
			if (getMax(profit)[1] != getMin(decay)[1]){
			    cout << getMax(profit)[0] << " " << getMin(decay)[0]<< endl;
			    return getMax(profit)[0] - getMin(decay)[0];
			}else {
			    return -1;
			}
		}
};