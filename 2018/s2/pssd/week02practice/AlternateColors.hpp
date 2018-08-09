#include <iostream>
#include <string>

using namespace std;

class AlternateColors{
    private:
        long sum = 0;
        int t = 1;
    public:
    void storeSum(long s){
        sum = s;
    }
    long getSum(){
        return sum;
    }
    
    void storeTurn(int t1){
        t = t1;
    }
    int getTurn(){
        return t;
    }
    
    string getColor(long r, long g, long b, long k){
        long sumNow = getSum();
        int turn = getTurn();
        
        string colors[3] = {"RED","GREEN","BLUE"};
        
        if (sumNow == k){
            return colors[turn - 1];
        }
        else if (sumNow < k){
            storeSum(sumNow += 1);
            if (r > 0 && turn == 1){
                r -= 1;
                if ( g > 0){
                    turn = 2;
                }else if (b > 0){
                    turn = 3;
                }
                else  {
                    turn = 1;
                }
            }else if (g > 0 && turn == 2){
                g -= 1;
                if ( r > 0){
                    turn = 1;
                }else if (b > 0){
                    turn = 3;
                }
                else  {
                    turn = 2;
                }
            }else if (b > 0 && turn == 3){
                b -= 1;
                if ( r > 0){
                    turn = 1;
                }else if (g > 0){
                    turn = 2;
                }
                else  {
                    turn = 3;
                }
            }
            storeTurn(turn);
            return getColor(r,g,b,k);
        }
    }
        
};