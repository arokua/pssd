#include <iostream>
#include <vector>
#include <string>

using namespace std;

class GoodHours{
    public:
    int counter = 0;
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
    
    int howMany(string beforeTime, string AFterTime){
        if (beforeTime == AFterTime){
            return counter;
        }
        if (isGood(AFterTime) && counter == 0){
            counter++;
        }
        
        
        else if (isGood(beforeTime)){
            counter++;
        }
        
        
        // Make the next before time
        string nextMin = "";
        if (beforeTime.substr(3,2) == "59"){
            nextMin = ":00";
            if (beforeTime.substr(0,2) == "23"){
                nextMin = "00" + nextMin;
            }else {
                if (beforeTime[0] = '0' && beforeTime[1] != '9'){
                    nextMin = '0' + to_string(beforeTime[1] - 47) + ":" + nextMin;
                }else {
                    nextMin = to_string(stoi(beforeTime.substr(0,2)) + 1) + ":" + nextMin;
                }
                
            }
            
        }
        
        else {
            if (beforeTime[3] == '0' && beforeTime[4]!= '9'){
                nextMin = beforeTime.substr(0,2) + ":0" + to_string(stoi(beforeTime.substr(3,2)) + 1);
            }else {
                nextMin = beforeTime.substr(0,2) + ":" +to_string(stoi(beforeTime.substr(3,2)) + 1);
            }
        }
        
        return howMany(nextMin,AFterTime);
        
    }
    
};
