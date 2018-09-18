#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Thimbles{
    private:
    int currentIn = 1;
    public:
    void swapBall(string s){
        if ( s[0] - 48 == currentIn){
            currentIn = s[2] - 48;
        }else if (s[2] - 48 == currentIn){
            currentIn = s[0] -48;
        }
        
    }
    
    int thimbleWithBall(vector<string> swaps){
        for (int i = 0; i <swaps.size(); i++){
            swapBall(swaps[i]);
        }
        int c = currentIn;
        currentIn = 1;
        return c;
        
    }
    
};