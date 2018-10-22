#include <algorithm>

#include <vector>



using namespace std;



class BigBurger{

    public:

    int maxWait(vector<int> a, vector<int> s){

        
 if (a.size() == 1){
            return 0;

        }


        int tiMe = 0;

        tiMe = a[0] + s[0];

        int wait ;

        
if (tiMe >= a[1]){

            wait = tiMe - a[1];

            tiMe += s[1];

        }
        else {
            tiMe = a[1];
            wait = 0;
        }
        int i = 2;
        while ( i <a.size() ){
            if (tiMe >= a[i]){
                
                wait = max(tiMe - a[i], wait);
                tiMe += s[i];
            }
            else {
                wait = 0;
                tiMe = a[i];
            }
            i++; 
        }
        return wait;
    }
};