#include <vector>
#include <algorithm>

using namespace std;

class TaliluluCoffee{
    public:
    
    int maxTip(vector<int> tips){
        sort(tips.rbegin(),tips.rend());
        int re = 0;
        for (int i = 0; i < tips.size(); i++){
            int a = tips[i] - i;
            if (a >= 0){
                re += a;
            }
        }
        
        
        return re;
    }
    
};