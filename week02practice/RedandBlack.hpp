#include <iostream>
#include <string>

using namespace std;

class BlackandRed {
    public:
    int cut(string deck){
        
        int index = 0;
        int minVal = 100;
        
        bool correctCut =false;
        
        
        for (int i = 0; i < deck.length(); i++){
            swap(deck[i], deck[deck.length() - 1]);
            for (int j = 0; j < deck.length(); j ++){
                int nRed = 0;
                int nBlack = 0;
                
                if (nBlack < nRed){
                    correctCut = false;
                    cout << "FFF\n";
                    break;
                }else{
                    if (deck[i] == 'R'){
                        nRed+= 1;
                    }else if (deck[i] == 'B'){
                        nBlack += 1;
                    }
                    correctCut =true;
                }
                cout << correctCut << "\n";
            }
            
            if ( correctCut == true){
                index = i;
                
                if (minVal > index){
                minVal = index;
                cout << minVal <<endl;;
                }
            }
            
            
            swap( deck[deck.length() - 1], deck[i]);
            
        }
            
        return minVal;
        
    }
};