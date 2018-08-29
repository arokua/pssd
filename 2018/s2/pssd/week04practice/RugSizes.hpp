#include <iostream>
#include <vector>

using namespace std;

class RugSizes{
    public:
    int RugCount (int area){
        int sum = 0;
        
        for (int i = 1; i < (area+1) /2 +1; i++){
            if (area % i == 0){
                
                int a = area /i;
                if((i != a) && (i%2==0) && (a%2==0)){
                    sum += 0;
                }
                else{
                    sum ++;
                }
            }
        }
        return sum;
    }
};