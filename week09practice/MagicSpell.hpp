#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class MagicSpell{
    public:
    string re1(string spell){
        string s = "";
        for (int i = 0; i <int(spell.length()); i++){
            if (spell[i] == 'A' || spell[i] == 'Z'){
                s =  spell[i] + s;
            }else {
                s = s + '|';
            }
        }
        return s;
    }
    
    string fixTheSpell(string ss){
        string re = re1(ss);
        for (int i = 0; i < ss.length(); i++){
            if (re[i] == '|'){
                re[i] = ss[i];
            }
        }
        return re;
    }
};