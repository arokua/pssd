#include <iostream>
#include <string>

using namespace std;

class AlternateColors{
    public:
    string getColor(long r, long g, long b, long k){
        long sumNow = 0;
        int turn = 1;
        while (sumNow < k){
            cout << turn << " ";
            if ( turn == 1 && r > 0){
                r -= 1;
                sumNow+=1;
                if (sumNow!= k){
                    turn += 1;
                    if (g > 0){
                        turn +=1;
                    }else if (b > 0){ 
                        turn += 2;
                    }else {
                        turn = 1;
                    }
                }
            }
            else if ( turn == 2 && g > 0){
                g -= 1;
                sumNow+=1;
                if (sumNow != k ){
                    if (b > 0){
                        turn +=1;
                    }else if (r > 0){ 
                        turn -= 2;
                    }else {
                        turn = 2;
                    }                }
            }
            
            else if ( turn == 3 && b > 0){
                r -= 1;
                sumNow+=1;
                    if (g > 0){
                        turn -= 1;
                    }else if (r > 0){ 
                        turn -= 2;
                    }else {
                        turn = 3;
                    }     
            }
        }
        
        if (turn == 1){
            return "RED";
        }else if (turn == 2){
            return "GREEN";
        }else if (turn == 3){
            return "BLUE";
        }
    }
};