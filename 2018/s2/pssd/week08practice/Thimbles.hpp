#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Thimbles{
    public:
    bool firstBall(vector<string> s,bool calledB4){
        for (int i = 0; i < int(s.size()); i ++){
            for (int j = 0; j < 3; j++){
                if (s[i][j] == '1' && calledB4 == false){
                    return true;
                }
            }
        }
        return false;
    }
    
    int currentIn = 1;
    
    void swapBall(string s){
        if ( s[0] - 48 == currentIn){
            currentIn = s[2] - 48;
        }else if (s[2] - 48 == currentIn){
            currentIn = s[0] -48;
        }
        
    }
    
    
    int thimbleWithBalls(vector<string> swaps){
        for (int i = 0; i <swaps.size(); i++){
            swapBall(swaps[i]);
        }
        return currentIn;
    }
    
};