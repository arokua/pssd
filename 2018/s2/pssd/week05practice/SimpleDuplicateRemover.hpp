#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SimpleDuplicateRemover{
	public:
		bool vecFind(vector<int> V, int n){
			sort(V.begin(), V.end());
			int counter = 0;
			for (int i = 0; i < V.size(); i++){
				if (V[i] == n){
					return true;
					break;
				}else {
					counter += 1;
					if (counter == V.size()- 1){
						return false;
					}
				}
			}
		}

		vector<int> process(vector<int> sequence){
			vector<int>  ret;
			ret.push_back(0);

			for (int i = sequence.size()-1; i>-1;i--){
				if (vecFind(ret,sequence[i]) == false){
					cout << sequence[i]<<endl;
					ret.push_back(sequence[i]);
				}else if (vecFind(ret,sequence[i]) == true) {
					continue;
				}
			}
			ret.erase(ret.begin() + 0);
			return ret;
		}
};