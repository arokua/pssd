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
    
    int colsPair(vector<string> col){
        string s = col[0];
        int currentI = 0;
        int p = 0;
        for (int i =1 ; i < col.size(); i++){
            if (i != currentI && col[i] == s){
                p++;
            }if (col[i] != s){
                s = col[i];
                currentI = i;
            }
        }
        return p;
    }
    
    int NonDup(vector<string> col){
        string s = col[0];
        int re;
        for (int i = 1; i < col.size() - 1; i++){
            if (s != col[i] && col[i] != col[i + 1]){
                s = col[i + 1];
                re++;
            }
        }
        return re;
    }
    
    string isPossible(vector<string> lor){
        sort(lor.begin(), lor.end());
        int n = distinctCol(lor);
        int n2 = colsPair(lor);
        int l = lor.size();
        if (n < 3){
            return "NO";
        }else if (n > 5){
            return "YES";
        }else if (n == 3){
            
            if (n2 == 3){
                return "YES";
            }else {
                return "NO";
            }
        }else if (n == 4){
            if (0 < NonDup(lor) < 3  ){
                return "YES";
            }else {
                return "NO";
            }
        }else {
            if (n2 == 1  ){
                return "YES";
            }else {
                return "NO";
            }
        }
        
    }
    
};