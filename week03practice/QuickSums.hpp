#include <iostream>
#include <string>
#include <vector>

using namespace std;

class QuickSums{
    public:
    int minSums(string numbers, int sum){
        int re = 0;
        int charLength = 1;
        int S = 0; // the current sum
        string swapping;
        vector<int> listOfV;
        bool gotIt = true;
        
        if (charLength ==1){

            for (int i = 0; i < numbers.length(); i++){
                
                if (S!= sum){
                    re += 1;
                    gotIt = false;
                    
                    S += numbers[i];
                    if (S == sum){
                        listOfV.push_back(re);
                        gotIt = true;
                        break;
                    }
                }
            }
            
            
            charLength += 1;
            
        }else if (charLength > 1){
            cout <<"FAILED";
            for (int i = 0; i < numbers.length(); i++){
                int longerNum = stoi(numbers.substr(i, charLength));
                S = longerNum;
                if (S == sum){
                    break;
                }
                re = 0;                
                
                swapping = numbers.substr(i, charLength);
                for (int  j = 0; j < swapping.length(); j ++){
                    if (S == sum){
                        listOfV.push_back(re);
                        gotIt = true;
                        break;
                    }else {
                        re += 1;
                        S += swapping[j];
                        gotIt = false;
                    }
                }
            }
       
        }if (gotIt == true){
            return re;
        }else {
            return -1;
        }
    }
};