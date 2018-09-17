#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class MinimalDifference{
    public:
    int sumDigits(int n){
        if (n < 10 && n > -1){
            return n;
        }
        
        string s = to_string(n);
        
        int re = 0;
        
        for (int i = 0; i < int( s.length()) ; i++){
            re += s[i] -48;
        }
        
        return re;
    }
    
    int minDiff = 999999999;
    
    int absolute(int a){
        if (a < 0){
            return -a;
        }else {return a;}
    }
    
    int findNumber(int A, int B, int C){
        int target = sumDigits(C);
        int re;
        for (int i = A; i < B + 1; i++){
            if (minDiff >absolute(sumDigits(i) - sumDigits(C))){
                minDiff = absolute(sumDigits(i) - sumDigits(C));
                re = i;
            }
        }
        
        
        minDiff = 0;
        return re;
    }
        
    
};