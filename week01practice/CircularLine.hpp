#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>   

using namespace std;

class CircularLine {
    public:
    int longestTravel( vector<int> t){
        int max= 0;
        int currentSum = 0;
        int subLength = 2;
        int length = t.size();
        int distance = 10;
        bool minDisTrue;
        
        for (int i = 0; i < length; i ++){
            for (int j = 0 ; j < subLength; j ++){
                currentSum += t[i];
            }
            
            if (currentSum > max ) {
                max = currentSum;
            }
            
            currentSum = 0;
        }
            
            
        
        return max;
    }
};