#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class FoxAndMountainEasy{
    public:
    
    string possible(int n, int start, int end, string history){
        string c = "";
        if (start + n < end){
            return "NO";
        }else if (start - n > end){
            return "NO";
        }
        else {
            int inc = (n + end - start) / 2;
            int dec = n - inc;
            if ((n +end - start) % 2 == 1){
                return "NO";
            }
            int hU = 0;
            int hD = 0;
            
            for (int i = 0; i < int( history.length()); i++ ){
                if (history[i] == 'U'){
                    hU++;
                    start++;
                }else {
                    hD++;
                    start--;
                }
                if (start < 0){
                    return "NO";
                }
            }
            if (hU > inc || hD >> dec){
                return "NO";
            }else {
                return "YES";
            }
        }
    }
};