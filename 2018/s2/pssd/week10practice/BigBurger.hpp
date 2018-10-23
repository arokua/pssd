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
            tiMe = max(tiMe, a[i]);
            wait = max(wait, tiMe - a[i]);
            tiMe += s[i];
            i++; 
        }
        return wait;
    }
};