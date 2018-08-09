#include <iostream>

using namespace std;

class Truckloads {
    public:
    int numTrucks(int numCrates, int loadSize){
        if ( numCrates <= loadSize  ){
            return 1; // One truck if the crates are just enougth
        }else { // If not, we go for recursion
            // IF the pile is even, the total piles id doubles normally
            if ( numCrates% 2 == 0){
                return 2 * numTrucks(numCrates / 2, loadSize);
            }
            // Otherwise it is half pile and half pile inceased by one more value
            else {
                return numTrucks(numCrates / 2, loadSize) + numTrucks((numCrates / 2) + 1, loadSize);
            }
        }
    }
    
};