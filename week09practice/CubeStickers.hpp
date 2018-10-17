#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class CubeStickers{
    public:
    int distinctCol(vector<string> col){
        
        string s = col[0];
        int re = 1;
        for (int i = 1; i < col.size(); i++){
            if (s != col[i]){
                s = col[i];
                re++;
            }
        }
        return re;
    }
    
    int countDups(vector<int> dat){
        int c = 0;
        for (int i = 0; i < dat.size(); i++){
            if (dat[i] > 1){
                c++;
            }
        }
        return c;
    }
    
    vector<int> countElements(vector<string> V){
        vector<int> a;
        int re = 1;
        string s = V[0];
        for (int i = 1; i < V.size(); i++){
            if (s == V[i]){
                re++;
                
            }else {
                s = V[i];
                a.push_back(re);
                re = 1;
            }
        }
        a.push_back(re);
        return a;
    }
    
    int single(vector<int> dat){
        int c = 0;
        for (int i = 0; i < dat.size(); i++){
            if (dat[i] == 1){
                c++;
            }
        }
        return c;
    }
    
    string isPossible(vector<string> lor){
        sort(lor.begin(), lor.end());
        int n = distinctCol(lor);
        int n2 = single(countElements(lor));
        int l = lor.size();
        if (n < 3){
            return "NO";
        }else if (n > 5){
            return "YES";
        }else if (n == 3 || n == 5){
            
            if (n == 3 && n2 ==0 ){
                return "YES";
            }else if (n == 5 && l > 5){
                return "YES";
            }else {
                return "NO";
            }
        }else if (n == 4){
            if (countDups(countElements(lor)) == 2  ){
                return "YES";
            }else {
                return "NO";
            }
        }
        
    }
    
};