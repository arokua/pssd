#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TaliluluCoffe{
    public:
    int maxTips(vector<int> tips){
        vector<int> orderToServe;
        int re = 0;
        for (int i = 0; i < tips.size(); i++){
            orderToServe.push_back(i);
            re += tips[i] - i;
        }
        int newTips = 0;
        while (next_permutation(orderToServe.begin(), orderToServe.end())){
            for (int i = 0; i < tips.size(); i++){
                if (tips[i] - orderToServe[i] > 0){
                    newTips += tips[i] - orderToServe[i];
                }

            }
            
            re = max(newTips, re);
            newTips = 0;
        }
        
        return re;
    }
    
};