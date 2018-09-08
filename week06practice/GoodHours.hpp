#include <iostream>
#include <vector>
#include <string>

using namespace std;

class GoodHours{
    private:
    int counter = 0;
    public:
    
    int digitsMultiS(string s2){
        int m = 1;
        for (int i = 0; i < s2.length(); i++){
            m *= s2[i] - 48;
        }
        return m;
    }
    
    bool isGood(string s){
        
        s.erase(2,1);
        
        if (s[0] - 48 == digitsMultiS(s.substr(1,3)) ){
            return true;
        }else if (digitsMultiS(s.substr(0,2)) ==  digitsMultiS(s.substr(2,2)) ){
            return true;
        }
        else if (digitsMultiS(s.substr(0,3)) ==  s[3] - 48 ){
            return true;
        }else {
            return false;
        }
    }
    
    string After1Min(string s){
        string nextMin = "";
        if (s.substr(3,2) == "59"){
            nextMin = ":00";
            if (s.substr(0,2) == "23"){
                nextMin = "00" + nextMin;
            }else {
                if (s[0] == '0' && s[1] != '9'){
                    
                    nextMin = '0' + to_string(s[1] - 47)  + nextMin;
                }else {

                    nextMin = to_string(stoi(s.substr(0,2)) + 1)  + nextMin;

                }
                
            }
            
        }
        
        else {
            if (s[3] == '0' && s[4]!= '9'){
                nextMin = s.substr(0,2) + ":0" + to_string(stoi(s.substr(3,2)) + 1);
            }else {
                nextMin = s.substr(0,2) + ":" +to_string(stoi(s.substr(3,2)) + 1);
            }
        }
        
        return nextMin;
    }
    
    int howMany(string beforeTime, string AFterTime){      
        
            if (isGood(AFterTime) && counter == 0){
                counter++ ;
                if (AFterTime == beforeTime){
                    int a = counter;
                    counter = 0;
                    return a;
                }
            }
            if (isGood(beforeTime) && beforeTime!= AFterTime) {
                counter++;
            }
            if (beforeTime!= AFterTime){
                return howMany(After1Min(beforeTime),AFterTime);
            }else {
                int a = counter;
                counter = 0;
                return a;
            }
    }  
};
