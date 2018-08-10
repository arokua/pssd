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
                    
                    gotIt = false;
                    
                    S += numbers[i] - 48;
                    if ( i > 0){
                        re += 1;
                    }

                    
                }
                else if (S == sum){
                        listOfV.push_back(re);
                        gotIt = true;

                        break;
                    }

            }
            
            
            if (gotIt == false){
                charLength += 1;
            }
            
        }
        if (charLength > 1){
            cout <<"FAILED\n";
            for (int i = 0; i < numbers.length(); i++){
                int longerNum = stoi(numbers.substr(i, charLength));
                
                re = 0;        
                
                swapping = numbers.substr(i + charLength, charLength);
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