#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <ctime>
#include <map>
#include <string> 
#include <fstream>
using namespace std;

int power2(int n){
    return n * n;
}

vector<string> takeInput(){
    // Get 1 line input from console
    // Split them by spaces and store to a vector
    string in;
    vector<string> pp;
    
    getline (std::cin, in);
    int len = in.length(); //length of input
    string temp = ""; //tempoary string
    for (int i = 0; i < len; i++){
        char current = in.at(i);
        if (current != ' ' && current != '\t'){
        	//Ignore tabs
        	temp += current;
        }
        else{
        	if (temp != "") pp.push_back(temp);
            temp ="";
        }
        if (i == len - 1){
            if (temp != "") pp.push_back(temp);
        }
    }
    return pp;
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
    
    vector<int> shortestDistance(){
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
    int maxV; // Max speed;
    int miV; // Min Speed;
    double Rent; //... as name suggest
    Tour t;// storing a tour information here
    public:
    //Intitalsing the thief 
    TheThief(){
    };
    void setSpeed1(int v1){
    	maxV = v1;
    }
    void setSpeed2(int v2){
    	miV = v2;
    }
    void setRent(double R){
    	Rent = R;
    }
    void setWeight(int W){
    	maxWeight = W;
    }
    
    void setTrip(Tour p){
    	t = p;
    }
    //Get a new item
    void aStolable(int m, int Prof, int Location){
        Item temp(m, Prof, Location);
        StuffList.push_back(temp);
    }
    
    void action(){
        // Begining getting picking order
        vector<int> ShortestTripNoSteal = t.shortestDistance(); // The original trip when no items to be stole
        int CitiesWithItems = ShortestTripNoSteal.size() - 1;// n - 1 value
        int index = 1; //The nth city from the first city
        
        int currentWeight = 0; // Present knapsack weight
        vector<int> pickingOrder;
        while (currentWeight <= maxWeight){ /// Checking if the knap sack is not full
            int now = ShortestTripNoSteal[index];// Current City to check
            int val = 0; // Comparision val
            int ItemNode = -1; // The node of the item
            int oldNode;
            int tempWeight; // A temporary weight to check 
            int chosenWeight; // and increment the knapsack weight
            double current_speed;

            if (index <= CitiesWithItems){ 
                for (int i = 0; i < StuffList.size(); i++){ //Go through the items list 
                    if (StuffList[i].getSpecs('c') == now) { // Check if the item is at the current city and it is not taken
                        tempWeight = StuffList[i].getSpecs('W');
                        if (currentWeight + tempWeight <= maxWeight){ 
                        	//This item can be added to knap sack
      
                            // Now check if it is the maximum value
                            if (val <= StuffList[i].getSpecs('V')){
                                // The current item is more valuable than the previous one
                                val = StuffList[i].getSpecs('V');
                                chosenWeight = tempWeight;
                                oldNode = ItemNode;
                                ItemNode = StuffList[i].getSpecs('I');
                                //bag's weight increases
                                currentWeight += chosenWeight;
                                //Remove chosen item from the list
                                StuffList.erase(StuffList.begin() + i);
                                pickingOrder.push_back(ItemNode);
                            }                            
                        }
                    }
                }
                index++;
            }
            else if (index > CitiesWithItems){
                if (currentWeight <= maxWeight && StuffList.size() > 0) index = 1;
                else break;
            }
            
        }
        //Print output to file
        ofstream result;
        result.open("fnl_soln.ttp");

        //Trip order
        result <<"[";
        for (int c = 0; c < CitiesWithItems + 1; c++){
            result << ShortestTripNoSteal[c];
            if(c < CitiesWithItems) result << ",";
        }
        result <<"]\n";
        //Picking order
        result <<"[";
        for (int i = 0; i < pickingOrder.size(); i++){
            result << pickingOrder[i];
            if(i < pickingOrder.size() - 1) result << ",";
        }
        result <<"]\n";
		result.close();
    }
};

int main(){
	/*
	Given test case on myuni
	Tour a;
	a.addCity(0, 0);
    a.addCity(10, 0);
    a.addCity(0, 10);
    a.addCity(10, 10);
    
    TheThief tt(0.1, 1, 1.00, 100, a);
    tt.aStolable(1,10,2);
    tt.aStolable(1,40,4);
    tt.aStolable(5,20,3);
    tt.aStolable(1,10,2);
    tt.aStolable(5,20,3);
    tt.aStolable(9,40,4);
    tt.action();*/
	// get input
	
	int current_line = 1;
	vector<string> input ;
	Tour tour;
	Tour T;
	//Number of cities
	int n;
	//Max weight
	int W;
	//Speed
	double v_Min;
	double v_Max;
	double rent;
	TheThief t2;
	while (true){
	    input = takeInput();
	    //Break when input is empty, meaning end of file
	    if (input.size() == 0) {
	    	break;
	    }
	    if (input[0] == "DIMENSION:") n = stoi(input.back());
	    //Get knapsack weight
	    else if (input[0] == "CAPACITY") W = stoi(input.back());
	    //Get the speed constraints
	    else if (input[0] == "MIN") v_Min = stod(input.back());
	    else if (input[0] == "MAX") v_Max = stod(input.back());
	    else if (input[0] == "RENTING") rent = stod(input.back());
	    //read in city specs
	    if (current_line < n + 11 && current_line > 10) {
	    	//cout <<current_line ;cout <<endl;
	    	T.addCity(stoi( input[1].c_str()), stoi(input[2].c_str()));
	    }
	    
	    //read in items specs
	    else if (current_line == n + 11) {
	    	//Add para to thief
	    	t2.setSpeed1(v_Min);
	    	t2.setSpeed2(v_Max);
	    	t2.setRent(rent);
	    	t2.setWeight(W);
	    	t2.setTrip(T);
	    }
	    else if (current_line > n + 11) {
	    	t2.aStolable(stoi(input[2].c_str()), stoi(input[1].c_str()), stoi(input[3].c_str()));
	    }
	    current_line ++;
	}
	t2.action();
	
}