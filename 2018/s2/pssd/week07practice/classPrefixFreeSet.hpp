#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrefix(string a, string b){
		if (a.length() > b.length()) return isPrefix(b, a);
		if (b.substr(0, ( int(a.length() )) ) == a ) return true;
		return false;
	}
class PrefixFreeSets {
public:
	PrefixFreeSets();
	int maxElements(vector<string>);
};

PrefixFreeSets::PrefixFreeSets(){}

int PrefixFreeSets::maxElements(vector<string> words){
	//Sort the list 
	sort(words.begin(), words.end());
	int re = 1;
	int temp = 1;
	for (int i = 0; i < int( words.size() ) - 1; i++){
        for (int j = i  + 1; j < int(words.size()); j++){
            if (!isPrefix(words[i], words[j]) and !isPrefix(words[j], words[j - 1])){
                temp++;
            }
        }
        re = max(re, temp);
        temp = 1;
	}
	return max(re, temp);
}