#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Arrows{
	public:
	int longestArrow(string s) {
		int Alen = 0;
		int counter = 0;
		int maxLen = 0;
		bool beginL1;
		bool beginL2;
		bool beginR;
		// check if there are arrows
		for (int i = 0; i <s.length(); i++){
			if ( s.at(i) == '-'  ){
				counter += 1;		
			}
		}
		cout << counter - s.length() <<endl;
		if (counter == s.length()){
			return -1;
		}

		// <-= arrows first
		for (int i = 0; i <s.length(); i++){
			if ( s.at(i) == '<'){
				Alen = 1;
				beginL1 = true;
				beginL2 = true;
			}if ((i >0) and (beginL1 == true) ){
				if ( (s.at(i) == '>') or s.at(i) =='=' or s.at(i) == '<'){
					maxLen = max(maxLen, Alen);
					Alen = 0;
					beginL1 == false;
				}
				else {
					cout <<i <<" "<<Alen <<endl;
					Alen += 1;
				}
			}

			if ((i >1) and (beginL2 == true) ){
				if ( (s.at(i) == '>') or s.at(i) =='-' or s.at(i) == '<'){
					maxLen = max(maxLen, Alen);
					Alen = 0;
					beginL2 == false;

				}
				else {
					Alen += 1;
				}
			}			
		}

		return maxLen;
	}
};