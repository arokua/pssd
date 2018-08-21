#include <vector>
#include <algorithm>

using namespace std;

class FewestFactors{
    private:
    int totalFactor(int a){
        int tot = 0;
        for (int i = 1;i < a + 1; i++){
            if (a%i == 0){
                tot++;
            }
        }
        return tot;
    }
    
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
    
    public:
    int number(vector<int> digits){
        sort(digits.begin(),digits.end());
        int iS = 0;
        int ret ;
        
        for (int i = 0; i < digits.size();i ++){
            iS += Intpower(10,digits.size() - i - 1) * digits[i];
        }
        
        ret = iS;
        while (next_permutation(digits.begin(),digits.end() )){
            if (totalFactor(ret)> totalFactor(iS)){
                ret = iS;
            }
            iS = 0;
            for (int i = 0; i < digits.size();i ++){
                iS += Intpower(10,digits.size() - i - 1) * digits[i];
            }

        }
        
        return ret;
    }
};