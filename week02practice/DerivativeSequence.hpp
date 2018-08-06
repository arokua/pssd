#include <vector>
#include <iostream>

using namespace std;

class DerivativeSequence {
    public:
    vector<int> derSeq(vector<int> a, int n){
        vector<int> re;
        re = a;
        while (n > 0){
            re = different(re);
            n -=1;
        }
        return re;
    }
    
    vector<int> different(vector<int> aVi){
        vector<int> re2;
        for (int i = 0; i < aVi.size() - 1; i++){
            re2.push_back(aVi[i+1] - aVi[i]);            
        }
        cout << endl;
        return re2;
    }
};