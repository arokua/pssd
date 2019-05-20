#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class PrefixFreeSet {
public:
	bool isPrefix(string a, string b){
		if (a.length() > b.length()) return isPrefix(b, a);
		if (b.substr(0, ( int(a.length() )) ) == a ) return true;
		return false;
	}
	int maxElements(vector<string> words){
		//Sort the list 
		sort(words.begin(), words.end());
		int re = 1;
		int temp = 1;
		for (int i = 0; i < int( words.size() ) - 1; i++){
			if (!isPrefix(words[i], words[i + 1])){
				temp++;
			}else {
				re = max(re, temp);
				temp = 1;
			}
		}
		return max(re, temp);
	}
};