#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class ChangingString {
    public:
    int distance(string A, string B, int k){
        int dist = 0;
        for (int i = 0; i < k; i++){
            dist += abs(B[i] - A[i]);
        }
        return dist;
    }
    
};