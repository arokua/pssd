#include <iostream>

using namespace std;
class FracCount{
    public:
    
    int findGCD(int a, int b){
        if (a%b==0){
            return b;
        }

        return findGCD(b, a%b);
    }
    
    int position(int n, int d){
        int counter  = 0;
        int i = 1;// numerator begin
        int j = 2;//denominator begin
        
        while (true){
            if (findGCD(i, j) == 1){
                counter +=1;
                if (i == n && j ==d){
                    break;
                }
            }
            
            //reset for an increase of d
            i+=1;
            if ( i == j ){
                i = 1;
                j +=1;
            }
            
        }
        return counter;
    }
};