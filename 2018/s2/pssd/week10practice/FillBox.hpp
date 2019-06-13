#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

long pow(int base, int P){
    if (P == 0) return 1;
    return pow(base, P - 1) * base;
}
class FillBox{
    public:
    int minCubes(int h, int w, int l, vector<int> cubes){
        long answer = 0;
        long target = h * w * l;
        
        for (int i = cubes.size() - 1; i > - 1; i--){
            //Volume of a single i-th cube
            long singleVolume = pow(pow(2, i), 3);
            long quotient = target / singleVolume;
            if (target == 0 ) break;
            
            if(target / singleVolume <= cubes[i]) 
            {
              target -= singleVolume * quotient;
              if (answer == 0) answer = quotient;
              else answer += quotient;
            }else {
              target -= singleVolume * cubes[i];
              if (answer == 0) answer = cubes[i];
              else answer +=cubes[i];
            }
        }
        if (target == 0) return answer;
        else return -1;
    }
};