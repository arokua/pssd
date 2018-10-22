#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class FoxAndMountainEasy{
    public:
    
    string possible(int n, int start, int end, string history){
        string c = "";
        if (start + n == end){
            if (history.find("D") != string::npos ) {
                return "NO";
            }
            else {
                return "YES";
            }
        }else if (start - n == end){
            if (history.find("U") != string::npos ) {
                return "NO";
            }else {
                return "YES";
            }
        }else if (start + n < end){
            return "NO";
        }else if (start - n > end){
            return "NO";
        }
        else {
            int inc = (n + end - start) / 2;
            int dec = n - inc;
            int myH = start;
            string s ="";
            for (int i = 0; i < n; i++){
                if (dec > 0){
                    s += 'D';
                    dec--;
                }else if (inc > 0) {
                    s += 'U';
                    inc--;
                }else {
                    break;
                }
                
            }
            
            if (s.find(history) != string::npos){
                    return "YES";
            }
            bool fail = false;
            while (next_permutation(s.begin(), s.end())){
                for (int i = 0; i < s.length() ;i++){
                    if (s[i] == 'D' && myH - 1 <0){
                        myH = start;
                        fail = true;
                        break;
                    }if (s[i] == 'D'){
                            myH--;
                    }else {
                            myH++;
                    }
                    
                }if (!fail){
                    if (s.find(history) != string::npos){
                        return "YES";
                    }
                }
                myH = start;
                fail = false;
            }
            return "NO";
        }
    }
};