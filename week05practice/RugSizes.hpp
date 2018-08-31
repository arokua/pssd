#include <iostream>
#include <vector>

using namespace std;

class RugSizes{
    public:
    int rugCount (int area){
        int sum = 1;
        
        for (int i = 1; i < area; i++){
            if (area % i == 0){
                
                int a = area /i;
                if (i> a){
                    break;
                }
                if((i != a) && (i%2==0) && (a%2==0)){
                    sum += 0;
                }
                else if (i > 1){
                    sum ++;
                }
            }
        }
        return sum;
    }
};