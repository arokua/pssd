#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class ImportantTasks{
    public:
    int maxVec(vector<int> v){
        int m = v[0];
        for (int i = 1; i< v.size(); i++){
            m = max(m,v[i]);
        }
        return m;
    }
     int total = 0;   
    int maximalCost(vector<int> i, vector<int> c){
        if (maxVec(c) < maxVec(i)){
            if (total == 0){
                return -1;
            }else {
                return total;
            }
        }
        
        if (i.size() == 0 || c.size() == 0) {
            return total;
        }
        else if (maxVec(c) >= maxVec(i)){
            total += 1;
            c.erase(max_element(c.begin(),c.end()));
            i.erase(max_element(i.begin(),i.end()));
            return maximalCost(i,c);
        }
    }
};