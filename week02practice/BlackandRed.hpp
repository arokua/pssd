#include <iostream>
#include <string>

using namespace std;

class BlackandRed {
    public:
    int cut(string deck){
        
        
        int minVal = deck.length();
        
        bool correctCut =false;
        
        cout << "Length "<< deck.length()<<endl;
        for (int i = 0; i < deck.length(); i++){
            string cutteddeck = deck.substr(i, deck.length() - i) + deck.substr(0, i);
            int nRed = 0;
            int nBlack = 0;
            for (int j = 0; j < cutteddeck.length(); j ++){
                
                
                if (cutteddeck[j] == 'R'){
                        nRed += 1;
                }else if (cutteddeck[j] == 'B'){
                    nBlack += 1;
                }
                
                if (nBlack < nRed){
                    break;
                }
                else if (!(nBlack < nRed)){
                    if (j == cutteddeck.length() - 1){
                        
                        if (minVal > i){
                            minVal = i;
                        }
                    }
                }
                
                    
                
            }
            
            
        }
            
        return minVal;
        
    }
};