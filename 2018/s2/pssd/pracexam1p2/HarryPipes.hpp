#include <string>
#include <algorithm>

using namespace std;

class HarryPipes
{
public:
	int pipeLen(string sub){
		int l = 0;
		int gotted;
		for (int i = 0; i< sub.length(); i++){
				if (sub[i] == '.'){
					gotted = l;
					l = 0;
				}else {
					l++;
				}

		}
		return gotted;
	}

	string rearrange(string s){
		string ret;
		for (int i = 0; i < int(s.length()); i++){
			for (int j = 0; j < int(s.length()); j++){
				pipeLen(s.substr(i,j);
			}
		}
		return ret;
	}
	
};