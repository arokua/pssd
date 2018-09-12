#include <string>

using namespace std;

class ExerciseMachine{
    public:
    int getSecs(string t){
        int sec = 0;
        sec = stoi(t.substr(t.length() - 2,2));
        sec+= 60*stoi(t.substr(t.length() - 5,2));
        sec += 3600*stoi(t.substr(0,2));
        return sec;
    }
    int calc(string tt ){
        
        int num = getSecs(tt);
        int a = 0;
        
        for (int i = 1; i < 101; i++){
            if ( num%i == 0){
                a = num/i;
            }
        }
        
        return a - 1;
    }
    int getPercentages(string tt){
        int num = getSecs(tt);
        int a = 0;
        
        for (int i = 1; i < 100; i++){
            if ( int((i *num) / 100) *100  == i*num){
                a++;
            }
        }
        
        return a;
    }
};