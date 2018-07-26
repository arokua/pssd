#include <iostream>
using namespace std;

class EggCartons{
    public:
    int minCartons(int n){
        int sum = 0;
        int minSum = 100;
        if ( n < 6 or n %2 !=0){
            return -1;
        }else{
            for (int i = 0; i <1 + n/6; i++){
                
                for (int j = 0; j <1 + n /8; j++){
                    
                    if (6* i +j*8 == n){
                        sum = i + j;

                        if (sum < minSum ){
                            minSum = sum;
                        }
                    }
                }
            }
            if (sum == 0){
                return -1;
            }else{
                return minSum;
            }
        }
    }
};