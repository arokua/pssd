#include <iostream>
#include <vector>

using namespace std;


class 	FibonacciDiv2 {
    public:
    int find(int N){
        int steps = N*2;
        
        int i = 1;
        int i2 = 2;
        // Making the Fib list
        vector<int> Fibbon;
        Fibbon.push_back(0);
        Fibbon.push_back(1);
        Fibbon.push_back(1);
        
        
        while (i2 < 31){
            
            Fibbon.push_back(Fibbon[i2] + Fibbon[i]);
            i += 1;
            i2 ++; 
            
        }
        
        // Start searching
        
        for (int n = 0; n < 32; n ++){
            if (steps > abs(N - Fibbon[n])){
                steps = abs(N-Fibbon[n]);
            }
        }
        
        return steps;
        }
};