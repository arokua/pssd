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
        long answer = LONG_MAX;
        long target = h * w * l;
        for (int i = 0; i < cubes.size(); i++){
            //Volume of a single i-th cube
            long singleVolume = pow(pow(2, i), 3);
            if (target % singleVolume == 0){
			//Amount of i-cubes that can fill the box 
                long quotient = target / singleVolume;
                if (quotient <= cubes[i] ){
                   answer = min(answer, quotient);
                }
            } 

        }
        if (answer != LONG_MAX) return answer;
        else return -1;
    }
};