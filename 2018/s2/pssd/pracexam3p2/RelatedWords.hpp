#include <string>

using namespace std;
class RelatedWords{
public:
	bool just1distinct(string s){
		 
		for (int i = 1; i < s.length(); i++){
			if (s[0] != s[i]){
				return false;
			}
		}
		return true;
	}
	int minRemoval(string A, string B){
		bool a = just1distinct(A);
		bool b = just1distinct(B);
		int l = A.length();
		if (a && b){
			return 0;
		}
		int rem = 0;
		if ( a != b){
			for (int i = 0; i < l; i ++){
				if (A[i] - B[i] != 0){
					rem ++;
				}
			}
			return rem;
		}
	}
};