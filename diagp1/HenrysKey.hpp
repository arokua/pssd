#include <iostream>
#include <string>

using namespace std;

class HenrysKey {
public:
	int howMany(string S){
		int much = 0;
		string key;
		string anotherKey = " ";
		string original = S;
		if (S.length() == 1){
			return 1;
		}else if (S.length() > 1){
			for (int i = 0; i<S.length(); i++){
				key = S.replace(i,1,"");
				if (key != anotherKey){
					much += 1;
					anotherKey = key;

				}
				S = original;
			}
			
			return much;


		}

		
	}	
};

