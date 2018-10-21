#include <string>

using namespace std;

class DifferentStrings {
    public:
    int Diff(string a, string b){
        int c = 0;
        for (int i = 0; i < int(a.length()); i ++){
            if (a[i] != b[i]){
                c++;
            }
        }
        return c;
    }
    
    int minimize(string A, string B){
        if (A.length() == B.length()){
            return Diff(A,B);
        }
        int re = B.length();    
        for (int i = 0; i < B.length(); i++){
            if ( i > B.length() - (A.length() - 1)){
                break;
            }
            string s = B.substr(i, A.length());
            re = min(re, Diff(A, s));
        }
        
        return re;
    }
};