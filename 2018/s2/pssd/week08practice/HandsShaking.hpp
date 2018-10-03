#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class HandsShaking{
    public:
    map<int, long> holder;
    long countPerfect(int n){
        if (n < 6){
            holder[n] = n/2;
            return n/2;
        }
        else if (n == 6){
            holder[n] = 5;
            return 5;
        }else if (holder.find(n) != holder.end()) {
            
            return holder[n];  
        }else {
            long sum = 0;
            for (int i = 0; i < n; i+=2){
            
                if (i == 0){
                    sum += countPerfect(n- i - 2);
                }else if ( n - i - 2 == 0){
                    sum += countPerfect(i);
                }else {
                    sum += countPerfect(i) * countPerfect(n - i - 2);
                }
            }
            holder[n] = sum;
            return sum;
        }
            
        
    }
    
};