#include <iostream>
#include <string>

using namespace std;

int IntPow(int base, int n){
    if (n == 0){
        return 1;
    }
    return base * IntPow(base, n -1);
}

class JumpyNum{
    public:

    
    int howMany(int low, int high){
        int counter = 0;
        
        if (low == high){
            if (low % IntPow(10, int(to_string(low).length() - 1) ) == 0){
                return 0;
            }
        }
        for (int i = low; i < high + 1; i++){
            string s = to_string(i);
            int n = 0;
            int len = s.length();
            if (i < 10){

                counter++;

            }if (i == 10){
                counter+= 0;
            }if (19 < i < 91 && i % 10 == 0 ){
                counter++;
            }if (i > 99 && i % IntPow(10, int(len - 1) ) == 0){
                counter += 0;
            }
            else {
                for (int j = 0; j < len; j++ ){
                    int c = int(s[j]) - int(s[j + 1]) ;
                    if (c != 0 and c != -1 and c != 1 ){
                        n++;
                    } 
                }
                
                if (n == len  - 1){
                    counter++;
                }
            }           
        }
        
        return counter;
    }
};