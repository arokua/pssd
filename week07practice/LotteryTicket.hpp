#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class LotteryTicket {
    public:
    string buy(int price, int a, int b, int c, int d){
        string go = "POSSIBLE";
        string nGo = "IM" + go;
        int arr[4] = {a, b,c, d};
        sort(arr, arr + 4);
        if (price < arr[0] or price > 4 * arr[3]) return nGo;
        for (int i = 0; i < 4; i++){
            int sum = arr[i];
            for (int j = i + 1; j < 4; j++){
                if (sum == price) return go;
                sum += arr[j];
            }
            if (sum == price) return go;            
        }
        return nGo;
    }
};