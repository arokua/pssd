#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class AlternateColors{
    public:
    string getCurrentFrom2(long c1, long c2, long k, string s1, string s2){
        long m = min( c1, c2);
        bool kOdd;
        if (k % 2 == 0){
            kOdd= false;
        }else {
            kOdd = true;
        }
        
        if ( k <= m){
            
            if (kOdd){
                return s1;
            }else {
                return s2;
            }
        }else if (c1 ==0){
            return s2;
        }else if (c2 == 0){
            return s1;
        }else if (k > m/2 && k <m ){
            return getCurrentFrom2(c1 - (m/2), c2 -(m/2), k - m, s1, s2);
        }else {
            return getCurrentFrom2(c1-m, c2-m,k-2*m,s1,s2);
        }
        
    }
    string getColor(long r, long g, long b, long k){
        string current = "L";
        string start;
        long minVal = min(r,min(g,b));
        k -= 3*minVal;
        r -= minVal;
        g -= minVal;
        b -= minVal;
        if (k == 0){
            return "BLUE";
        }
        
        if (r > 0 && b > 0){
            return getCurrentFrom2(r,b,k,"RED", "BLUE");
        }
        else if (r > 0 && g > 0){
            return getCurrentFrom2(r,b,k,"RED", "GREEN");
        }else if (g > 0 && b > 0){
            return getCurrentFrom2(g,b,k, "GREEN","BLUE");
        }else if ( r > 0 && g == b){
            return "RED";
        }
        else if ( g > 0 && r == b){
            return "GREEN";
        }else if ( b > 0 && g == r){
            return "BLUE";
        }
        cout<<minVal;
        return "\nLOP";
    }
    
};