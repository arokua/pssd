#include <vector>
#include <algorithm>
#include <numeric>
#nclude <stdlib.h>

using namespace std;

class TomekPhone{
    public:
    int minKeystrokes(vector<int> f, vector<int> S){
        if ( f.size() > accumulate(S.begin(),S.end(),0) ){
            return -1;
        }
        else {
            return rand()%4000;
        }
    }
};
