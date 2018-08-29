#include <iostream>

using namespace std;

class ChristmasTree {
    public:
    long factorial(int n){
        if ( n<=1){
            return n;
        }
        return n*factorial(n-1);
    }
    
    long combinatoric(int n, int k) {
        return factorial(n)/(factorial(k)*(factorial(n-k)));
    }
    
    long theLoop(int N, int r, int g, int b, int nLoop){
        long sum = 0;
        if ( r< 0 or g <0 or b<0){
            return 0;
            //base case1
        }
        if (nLoop == N){
            return 1;
            //base case2
        }
        
        if (nLoop% 3==0){
            sum += theLoop(N, r-nLoop/3, g - nLoop /3, b -nLoop/3,nLoop+1)*combinatoric(nLoop,nLoop /3) *combinatoric(2*nLoop/3,nLoop/3);
        }
        
        if (nLoop %2 == 0) {
            // divides into the possible paths for r g b
            sum += theLoop(N, r-nLoop/2, g - nLoop /2, b,nLoop+1)*combinatoric(nLoop,nLoop /2);
            sum += theLoop(N, r-nLoop/2, g, b - nLoop/2, nLoop+1)*combinatoric(nLoop,nLoop /2);
            sum += theLoop(N, r, g- nLoop/2, b-nLoop/2,nLoop+1)*combinatoric(nLoop,nLoop /2);
        }
        
        
        
            sum += theLoop(N, r-nLoop, g , b,nLoop+1);
            sum += theLoop(N, r, g -nLoop , b,nLoop+1);
            sum += theLoop(N, r, g , b -nLoop,nLoop+1);
        
        
        return sum;
    }
    long decorationWays(int N, int r, int g, int b){
        
            return theLoop(N + 1,r,g,b,1);
        
    }
};