#include <string>

using namespace std;

class JumpyNum{
    public:
    int isJumpy(int n){
        string s = to_string(n);
        if (int(s.length()) == 1){
            return true;
        }else{
            int count = 0;
            for (int i = 0; i < int(s.length()) - 1;i++){
                if (s[i] - s[i+1] > 1){
                    
                    count ++;
                }else if (s[i +1] - s[i] > 1){
                    
                    count++;
                }
            }
            
            if (count == int(s.length()) -1){
                return true;
            }else {
                return false;
            }
        
        }
    }
    
    
    int howMany(int low, int high){
        long counter = 0;
        for (int i = low; i < high + 1; i++){
            if (isJumpy(i)){
                counter += 1;
            }
        }
        return counter;
    }
};