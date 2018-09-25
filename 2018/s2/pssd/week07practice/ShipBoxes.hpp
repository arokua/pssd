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
        int re;
        // Length-width-height
        
        int maxL = max(a[0], b[0]); // comparing original values at same index
        int maxH = max(a[2], b[2]);
        int maxW = max(a[1], b[1]);
        
        int max01 = max(a[0],b[1]);
        int max10 = max(a[1],b[0]);
        int max02 = max(a[0],b[2]);
        int max20= max(a[2],b[0]);
        int max12 = max(a[1],b[2]);
        int max21 = max(a[2],b[1]);
        
        vector<int> dims;
        dims.reserve(3);
        
        // First way
        dims[0] = a[0] + b[0];
        dims[2] = maxH;
        dims[1] = maxW;
        re = TotalArea(dims[0], dims[1], dims[2]);
        re = min(TotalArea(dims[0],dims[2],dims[1]), re);
        re = min(TotalArea(dims[1],dims[2],dims[0]), re);
        re = min(TotalArea(dims[1],dims[0],dims[2]), re);
        re = min(TotalArea(dims[2],dims[0],dims[1]), re);
        re = min(TotalArea(dims[2],dims[1],dims[0]), re);
        
        
        //2nd
        dims[0] = a[0] + b[1];
        dims[1] = max10;
        dims[2] = maxH;
        re = min(TotalArea(dims[0],dims[1],dims[2]), re);
        re = min(TotalArea(dims[0],dims[2],dims[1]), re);
        re = min(TotalArea(dims[1],dims[2],dims[0]), re);
        re = min(TotalArea(dims[1],dims[0],dims[2]), re);
        re = min(TotalArea(dims[2],dims[0],dims[1]), re);
        re = min(TotalArea(dims[2],dims[1],dims[0]), re);
        
        //3rd
        dims[0] = a[0] + b[2];
        dims[1] = maxW;
        dims[2] = max20;
        re = min(TotalArea(dims[0],dims[1],dims[2]), re);
        re = min(TotalArea(dims[0],dims[2],dims[1]), re);
        re = min(TotalArea(dims[1],dims[2],dims[0]), re);
        re = min(TotalArea(dims[1],dims[0],dims[2]), re);
        re = min(TotalArea(dims[2],dims[0],dims[1]), re);
        re = min(TotalArea(dims[2],dims[1],dims[0]), re);            
        
        //4th
        dims[0] = a[0] + b[2];
        dims[1] = max21;
        dims[2] = max10;
        re = min(TotalArea(dims[0],dims[1],dims[2]), re);
        re = min(TotalArea(dims[0],dims[2],dims[1]), re);
        re = min(TotalArea(dims[1],dims[2],dims[0]), re);
        re = min(TotalArea(dims[1],dims[0],dims[2]), re);
        re = min(TotalArea(dims[2],dims[0],dims[1]), re);
        re = min(TotalArea(dims[2],dims[1],dims[0]), re);
        
        //5th
        re = min(TotalArea(a[0] + b[0], maxW,max21), re);
        
        //6th
        re = min(TotalArea(a[0] + b[2], max12,max20), re);
        
        //7th
        re = min(TotalArea(a[1] + b[0], max01,maxH), re);
        
        //8th
        re = min(TotalArea(a[1] + b[0], max02,max21), re);
        
        //9th
        re = min(TotalArea(a[1] + b[1], maxL,maxH), re);
        
        //10th
        re = min(TotalArea(a[1] + b[1], max02,max20), re);
        
        //11th
        re = min(TotalArea(a[1] + b[2], max01,max20), re);
        
        //12th
        re = min(TotalArea(a[1] + b[2], maxL,max21), re);
        
        //13th
        re = min(TotalArea(a[2] + b[0], max01,max12), re);
        
        //14th
        re = min(TotalArea(a[2] + b[0], max02,maxW), re);
        
        //15th
        re = min(TotalArea(a[2] + b[1], max10,max02), re);
        
        //16th
        re = min(TotalArea(a[2] + b[1], max12,maxL), re);
        
        //17th
        re = min(TotalArea(a[2] + b[2], maxL,maxW), re);
        
        //18th
        re = min(TotalArea(a[2] + b[2], max01,max10), re);
        
        return re;
    }
};