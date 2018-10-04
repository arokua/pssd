#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class FillBox{
    public:
    int Base2Pow(int n){
        if (n == 0){
            return 1;
        }
        return 2*Base2Pow(n - 1);
    }
    
    int cubeVolume(int side){
        return Base2Pow(side) * Base2Pow(side) * Base2Pow(side);
    }
    
    int vol(int l, int h, int w){
        return l * h * w;
    }
    
    vector<int> cVolList(vector<int> cubes){
        vector<int> re;
        re.reserve(cubes.size());
        for (int i = 0; i < cubes.size(); i ++){
            if (cubes[i] > 0){
                re.push_back(cubeVolume(i));
            }else {
                re.push_back(0);
            }
        }
        return re;
    }
    
    int sum = 0;
    int comparision(int tar, vector<int> Vlist, vector<int> cubes, int index){
        if (cubes[index] * Vlist[index] >= tar){
            sum = tar/Vlist[index];
            int n = sum;
            sum = 0;
            return n;
        }
        
        return cubes[index] + comparision(tar - cubes[index] * Vlist[index],Vlist,cubes, index -1);
    }
    
    int minCubes(int le, int he, int wi, vector<int> cubes){
        int Target = vol(le,he,wi);
        int checker= 0;
        for (int i = 0; i < cubes.size(); i++){
            checker += cubes[i] * cVolList(cubes)[i];
        }
        if (checker < Target){
            return -1;
        }else{
            return comparision(Target, cVolList(cubes),cubes, cubes.size() - 1);
        }
    }
};