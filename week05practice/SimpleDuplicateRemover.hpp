#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SimpleDuplicateRemover{
	public:
		/*bool vecFind(vector<int> V, int n){
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
		}*/

		vector<int> process(vector<int> sequence){
			vector<int>  ret;
			vector<int>  ter;
			ret.push_back(0);

			for (int i = sequence.size() - 1; i > -1; i--){
				if (!any_of(ret.begin(), ret.end(), [=](int t){return t == sequence[i];})){
					ret.push_back(sequence[i]);

				}
			}
			
			ret.erase(ret.begin() + 0);
			reverse(ret.begin(),ret.end());
			return ret;
		}
};