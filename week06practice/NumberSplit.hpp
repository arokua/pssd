#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class NumberSplit{
    public:
    int Intpower (int base, int expo) {
        int ans = 1;
        if (expo == 0){
            return 1;
        }
        else if ( expo > 0){
            for (int i = 0; i < expo; i ++){
                ans *= base;
            }
            return ans;
        }
        else if (expo < 0) {
            return 0;
        }
        else {
            return 0;
        }
    }
    int counter = 0;
    vector<int> owned;
    vector<int> splited;
    
    vector<int> splitNumber(int n, int parts, int l, int sameL){
        
        if (parts == 1 || int(to_string(n).length()) == 1){
            vector<int> re;
            splited.push_back(n);
            re = splited;
            splited.clear();
            return re;
        }
        
        splited.push_back(n / Intpower(10,l));
        if (sameL * l> int(to_string(n)).length() ){
            return splitNumber(n / Intpower(10,l), parts - 1, l, sameL - 1);
        }else {
            return splitNumber(n / Intpower(10,l), parts - 1, l -1, sameL);
        }
        
    }
        
