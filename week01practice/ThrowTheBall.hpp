#include <iostream>

using namespace std;

class ThrowTheBall {
    public:
    int timesThrown(int N, int M, int L){

        int currentPlayer = 1;
        int times = 0;
        int BHBT[N][1] ; //ballHoldernBallTimes
        BHBT[0][0] = 1;
        // 
        for (int i = 1;i < N; i++){
            BHBT[i][0] = 0;
        }
        while (true){
            
            if (BHBT[currentPlayer - 1][0] == M){
                break;
            }
            //Decicding player holding the ball
            times += 1;
            if (BHBT[currentPlayer - 1][0] % 2 == 0){
                if ((currentPlayer  + L) % N != 0){
                    currentPlayer = (currentPlayer + L) % N;
                }else {
                    currentPlayer = N;
                }
            }else if (BHBT[currentPlayer - 1][0] % 2 != 0){
                if ((currentPlayer  - L) % N != 0){
                    currentPlayer = (currentPlayer - L + N) % N;
                }else {
                    currentPlayer = N;
                }
            }
            
            //Increase the times holding it
            BHBT[currentPlayer-1][0] += 1;
            
        }
        
        return times;
    }
};