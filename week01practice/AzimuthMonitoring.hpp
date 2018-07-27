#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AzimuthMonitoring {
    public:
    int getAzimuth(vector<string> instructions){
        int angle = 0;
        int x = 0;
        for (int i = 0; i < instructions.size(); i ++){
            if (instructions[i] == "RIGHT"){
                angle += 90;
            }else if(instructions[i] == "LEFT"){
                angle -= 90; 
                
            }else if(instructions[i] == "TURN AROUND"){
                angle += 180;
            }else if (instructions[i] == "HALT"){
                break;
            }else{
                if (instructions[i].find("RIGHT") == 0){
                    
                    instructions[i].replace(0,6,"");
                    angle += stoi(instructions[i]);    
                    
                }else if (instructions[i].find("LEFT") == 0){
                    instructions[i].replace(0,5,"");
                    angle -= stoi(instructions[i]);              
                }
            }
        }

	while (angle < 0){
                    angle += 360;
         }
        return angle%360;
    }
};