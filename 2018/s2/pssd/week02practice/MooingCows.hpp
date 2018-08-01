#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MooingCows{
    public:
    int dissatisfaction(vector<string> farmland){
        
        int Mintota = 100000;
        
        for (int i = 0; i < farmland.size(); i++){
            for(int j = 0; j < farmland[0].size(); j ++){                
                if (farmland[i][j] == 'C'){
                    int tota = 0;
                    for (int i2 = 0; i2 < farmland.size(); i2++){
                        for(int j2 = 0; j2 < farmland[0].size(); j2 ++){
                            if (farmland[i2][j2] == 'C')
                                tota += (i -i2 )* (i-i2) + (j-j2)*(j-j2);
                            
                        }
                    }
                    if (Mintota > tota)
                        Mintota = tota;
                
                }
                
            }
        }
        return Mintota;
    }
    
};