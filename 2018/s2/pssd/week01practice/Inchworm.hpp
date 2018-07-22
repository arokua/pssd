#include <iostream>
using namespace std;

class Inchworm {
    
    public:
        Inchworm(){}
        int lunchtime(int branch, int rest, int leaf){
            int leafEaten = 0;
            bool allValid = true;
            if (!( 0 < branch < 1000000) ){
                cout << "Invalid branch number\n";
                allValid = false;
            }
            if (!( 0 < rest< 1000)){
                cout << "Invalid rest number\n";
                allValid = false;
            }
            if (!( 0 < leaf< 1000)){
                cout << "Invalid leaf number\n";
                allValid = false;
            }
            
            if (allValid == true){
                    
                for (int i = 0; i < (branch / leaf) + 1; i++){
                    if ( (i * leaf ) % rest == 0){
                        leafEaten +=1;
                    }
                    else{
                        leafEaten +=0;
                    }
                }
                return leafEaten;
            }
            else {
                return -1;
            }
            
        }
};