#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <ctime>
#include <map>

using namespace std;

int power2(int n){
    return n * n;
}

class City{
    int Xcoor;
    int Ycoor;
    int nodeN;
    public:
    City(int x, int y, int n){
        Xcoor = x;
        Ycoor = y;
        nodeN = n;
    }
    int getX(){
        return Xcoor;
    }
    
    int getY(){return Ycoor;}
    
    int getIdentity(){
        return nodeN;
    }
};

class Tour{
    private:
    int counter = 1;
    vector<City> TargetPlaces;
    public:
    void addCity(int X, int Y){
        TargetPlaces.push_back(City(X, Y, counter));
        counter++;
    }
    
    void printCityList(){
        for (int i = 0; i < TargetPlaces.size(); i++){
            cout << TargetPlaces[i].getIdentity() << " " << TargetPlaces[i].getX() <<" " << TargetPlaces[i].getY() <<endl;
        }
    }
    
    double distance(City A, City B){
        return sqrt(power2(A.getX() - B.getX()) + power2(A.getY() - B.getY()) );
    }
    
    vector<City> getTargetLoc(){
        return TargetPlaces;
    }
    
    vector<int> shortestDistance(string pri){
        vector<int> nodes;
        int nC = TargetPlaces.size();
        nodes.reserve(nC );
        for (int i = 0; i < nC; i++){
            nodes.push_back(i + 1);
        }
        double minD = 1.0 * INT_MAX;
        double d = 0;
        for (int i = 0; i < nC - 1; i++){
            d += distance(TargetPlaces[i], TargetPlaces[i + 1]);
        }
        minD = min(d, minD);
        vector<int> re;
        re = nodes;
        while (next_permutation(nodes.begin(), nodes.end())){
            if (nodes[0] != 1){
                break;
            }
            d = 0;
            for (int i = 0; i < nC - 1; i++){
               d += distance(TargetPlaces[nodes[i] - 1], TargetPlaces[nodes[i + 1] - 1]);
            }
            if (d < minD){
                minD = d;
                re = nodes;
            }
        }
        
        if (pri == "YES"){
            for (int i = 0; i < nC; i++){
                cout << re[i];
                if (i < nC - 1){
                    cout << " ";
                }else {cout << endl;}
            }
        }
        return re;
    }
    
};

class Item{
    double weight; // Item weight
    double profit; // profit ...
    double VperW; // profit per uni weight value
    int atCity; //Store the Location
    int index; // Item index
    static int i;
    public:
    
    Item(double w, double p, int aC){
        weight = w;
        profit = p;
        VperW = p/w;
        atCity = aC;
        index = i;
        i++;
    }
    
    double getSpecs(char what){
        //Return the respective value of Item for usage
        if (what == 'P'){
            return profit;
        }
        else if (what == 'W'){
            return weight;
        }else if(what == 'V') {
            return VperW;
        }else if (what == 'I'){
            return index;
        }else {
            return atCity;
        }
    }
};

int Item::i = 1;

class TheThief{
    private:
    
    vector<Item> StuffList; // All the items possible to be stolen
    int maxWeight;// The weight of the knapsack
    int maxxV; // Max speed;
    int miV; // Min Speed;
    double Rent; //... as name suggest
    Tour t;// storing a tour information here
    public:
    //Intitalsing the thief and knapsack
    TheThief(int maV, int mV, int R, int W, Tour n){
        
        maxxV = maV;
        miV = mV;
        Rent = R;
        maxWeight = W;
        t = n;//mainly to get the tour name
    }
    
    //Get a new item
    void aStolable(int m, int Prof, int Location){
        Item temp(m, Prof, Location);
        StuffList.push_back(temp);
        
        
    }
    
    void action(){
        // Begining getting picking order
        vector<int> ShortestTripNoSteal = t.shortestDistance("YES"); // The original trip when no items to be stole
        int CitiesWithItems = ShortestTripNoSteal.size() - 1;// n - 1 value
        int index = 1; //The nth city from the first city
        
        int currentWeight = 0; // Present knapsack weight
        vector<int> pickingOrder;
        while (currentWeight < maxWeight){ /// Checking if the knap sack is not full
            int now = ShortestTripNoSteal[index];// Current City to check
            int val = 0; // Comparision val
            int ItemNode = -1; // The node of the item
            int oldNode;
            int tempWeight; // A tempoarily weight to check 
            int chosenWeight; // and increment the knapsack weight
            if (index < ShortestTripNoSteal.size()){ 
                for (int i = 0; i < StuffList.size(); i++){ //Go through the items list 
                    if (StuffList[i].getSpecs('c') == now) { // Check if the item is at the current city and it is not taken
                        tempWeight = StuffList[i].getSpecs('W');
                        if (currentWeight + tempWeight <= maxWeight){ //The item can be added to knap sack
                            // Now check if it is the maximum value
                            if (val < StuffList[i].getSpecs('V')){
                                // The current item is more valuable than the previous one
                                val = StuffList[i].getSpecs('V');
                                chosenWeight = tempWeight;
                                oldNode = ItemNode;
                                ItemNode = StuffList[i].getSpecs('I');
                            }
                            
                        }
                    }
                }
                currentWeight += chosenWeight;
                if (ItemNode > 0){
                    pickingOrder.push_back(ItemNode);
                }
                index++;
            }
            else if (index >= ShortestTripNoSteal.size()){
                break;
            }
            
        }
        
        for (int i = 0; i < pickingOrder.size(); i++){
            cout << pickingOrder[i] << " ";
        }
        cout <<endl;
    }
};

int main(){
    Tour a;
    a.addCity(0, 0);
    a.addCity(10, 0);
    a.addCity(0, 10);
    a.addCity(10, 10);
    
    TheThief tt(0.1, 1, 1.00, 100, a);
    tt.aStolable(1,50,3);
    tt.aStolable(2,49,3);
    tt.aStolable(5,9,4);

    tt.action();
}