#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ShipBoxes{
    public:
    int RectArea(int a, int b){
        return a * b;
    }
                        
    int TotalArea(int a, int b, int c){
        /* a* b is the top
        b * c is the side
        a* c is the end */
        return 2 * b*(a+c) + 4 * a * c;
    }
    
    int bestCost(vector<int> a, vector<int> b){
    
        //a[0] + b[0]
        vector<int> dimensions;
        dimensions.reserve(3);
        dimensions.push_back(a[0] + b[0]);
        dimensions.push_back(a[1]);
        dimensions.push_back(a[2]);
        
        int re;
        re = TotalArea(dimensions[0], dimensions[1], dimensions[2]);
        while (next_permutation(dimensions.begin(),dimensions.end())){
            re = min(TotalArea(dimensions[0], dimensions[1], dimensions[2]), re);
        }
        
        
        dimensions[0] = b[0] + a[0];
        dimensions[1] = b[1];
        dimensions[2] = b[2];
        re = min(re,TotalArea(dimensions[0], dimensions[1], dimensions[2]));
        while (next_permutation(dimensions.begin(),dimensions.end())){
            re = min(TotalArea(dimensions[0], dimensions[1], dimensions[2]), re);
        }
        
        return re;
    }
};