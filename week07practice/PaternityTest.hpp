#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class PaternityTest{
    public:
    vector<int> possibleFathers(string child, string mother, vector<string> men){
        vector<char> d;
        vector<int> n;
        bool c = false;
        int matchT = 0;
        vector<int> posG;
        
        for (int i = 0; i < child.length(); i++){
            if (child[i] != mother[i]){
                d.push_back(child[i]);
                n.push_back(i);
            }
        }
        if (mother == child){
            c = true;
        }
        
        for (int i = 0; i < int(men.size()); i++){
            string dadbe = men[i];
            for (int j = 0; j < child.length(); j++){
                if (!c){
                    if (dadbe[j] == child[j] && any_of(n.begin(),n.end(),[=](int x){return x == j;}) ){
                        matchT++;
                    }
                }
                else{
                    if (dadbe[j] == child[j] ) {
                        matchT++;
                    }
                }
                
            }
            
            if (matchT >= int(child.length()) / 2){
                posG.push_back(i);
            }
            matchT = 0;
        }
        
        return posG;
    }
};