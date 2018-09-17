#include <string>

using namespace std;

class LotteryTicket {
    public:
    string buy(int price, int a, int b, int c, int d){
        string go = "POSSIBLE";
        string nGo = "IM" + go;
        
        if (price == a || price == b || price == c || price == d){
            return go;
        }
        else if (price == a + b){
            return go;
        }else if (price == a + c){
            return go;
        }else if (price == a + d){
            return go;
        }
        else if (price == b + c ) {
            return go;
        }
        else if (price == b + d){
            return go;
        }
        else if (price == c + d ){
            return go;
        }
        else if (price == a + b + c){
            return go;
        }
        else if (price == a + b + d){
            return go;
        }
        else if (price == b + c + d){
            return go;
        }
        else if ( price == a+ b+ c+ d){
            return go;
        }
        
        else {
            return nGo;
        }
    }
};