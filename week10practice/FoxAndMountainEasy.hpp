#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class FoxAndMountainEasy{
    public:
    vector<string> makeTrip(int n, int start, int end){
        vector<string> re;
        re.reserve(n + 1);
        string s = "";
        if (start + n == end){
            for(int i = 0; i < n; i++){
                s +='U';
            }
            re.push_back(s);
        }else if (start - n == end){
            for(int i = 0; i < n; i++){
                s +='D';
            }re.push_back(s);
            
        }else{
            
            vector<int> h;
            int ups = (end + n -start) / 2;
            int downs = n - ups;
            for (int i = 1; i < n; i ++){
                if (ups > 0){
                    h.push_back(0);
                    s +='U';
                    ups--;
                }if (ups == 0){
                    h.push_back(1);
                    s += 'D';
                }
            }
            re.push_back(s);
            int myH = start;
            while (next_permutation(h.begin(), h.end() )){
                s = "";
                for (int i = 0; i < h.size(); i++){
                    
                    if (h[i] == 0){
                        s+= 'U';
                    }else {
                        if (myH - 1 > -1){
                            s+= 'D';
                        }else {
                            s = "";
                            break;
                        }
                    }
                }
                if (s != ""){
                    re.push_back(s);
                }
            }

        }
        return re;
    }
    
    int upCounter(string s){
        int n = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == 'U'){
                n++;
            }
        }
        return n;
    }
    
    string possible(int n, int s, int end, string history){
        vector<string> li = makeTrip(n, s, end) ;
        
        for (int i = 0; i < li.size(); i++){
            string c = li[i];
            if (c.find(history) != string::npos){
                return "YES";
            }
        }
        return "NO";
    }
};