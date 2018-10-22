#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class FoxAndMountainEasy{
    public:
    vector<string> makeTrip(int n, int start, int end){
        if (start + n == end){
            vector<string> re;
            re.reserve(n + 1);
            string s = "";
            for(int i = 0; i < n; i++){
                s +='U';
            }re.push_back(s);
            return re;
        }else if (start - n == end){
            vector<string> re;
            re.reserve(n + 1);
            string s = "";
            for(int i = 0; i < n; i++){
                s +='D';
            }re.push_back(s);
            return re;
        }else{
            vector<string> re;
            vector<int> h;
            re.reserve(n + 1);
            int ups = (end + n -start) / 2;
            int downs = n - ups;
            string s = "";
            for (int i = 0; i < n; i ++){
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
            while (next_permutation(h.begin(), h.end())){
                s = "";
                for (int i = 0; i < h.size(); i++){
                    if (h[i] == 0){
                        s+= 'U';
                    }else {
                        s+= 'D';
                    }
                }
                re.push_back(s);
                
            }
            
            return re;
        }
        
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
        int nUps = upCounter(history);
        if (s == end){
            if (nUps <= n / 2){
                return "YES";
            }
            else {
                return "NO";
            }
        }
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