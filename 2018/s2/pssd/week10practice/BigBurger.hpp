#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



class BigBurger{

    public:

    int maxWait(vector<int> a, vector<int> s){

        
 if (a.size() == 1){
            return 0;

        }


        int tiMe;

        tiMe = a[0] + s[0];

        int wait = 0;
        
        int i = 1;
        
        while ( i <a.size() ){
            if (tiMe >= a[i]){
                wait = max(tiMe - a[i], wait);
                tiMe += s[i];
            }
            else {
                wait = max(wait, s[i+1]);
                tiMe = a[i] + s[i];
                
            }
            i++; 
        }
        return wait;
    }
};