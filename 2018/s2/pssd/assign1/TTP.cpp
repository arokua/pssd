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
    int counter = 0;
    vector<City> TargetPlaces;
    // adjacency matrix
    vector<vector<double>> adjacency;
    public:
    void addCity(int X, int Y){
        TargetPlaces.push_back(City(X, Y, counter));
        counter++;
        updateAdjacency();
    }

    void updateAdjacency(){
        vector<double> newRow;
        if (counter == 1){
            newRow.push_back(0.0);
            adjacency.push_back(newRow);
            return;
        }else if (counter > 1){
            for (int b = 0; b < counter-1; b++){
                double next_dist = distance(TargetPlaces[b], TargetPlaces[counter - 1]);
                adjacency[b].push_back(next_dist);
            }
            for (int i = 0; i < counter ; i++){
                if (i != counter -1) newRow.push_back(adjacency[i][counter-1]);
                else newRow.push_back(0.0);
            }
            adjacency.push_back(newRow);
        }
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
    
    int nearestCity(int now, int status[]){
        int re = 1;
        double smallest_distance = 1.0*INT_MAX;
        for (int i = 1; i < TargetPlaces.size(); i++ ){
            if (*(status + i) != 1 && i != now) {//Haven't pass this city
                double this_distance = adjacency[i][now];
                if (this_distance < smallest_distance && this_distance>0){
                    re = i;
                    smallest_distance = this_distance;
                }
                
            }
        }
        *(status + re) = 1;
        return re;
    }

    void printAdjacency(){
      for (int c = 0; c < TargetPlaces.size(); c++){
          for (int c1 = 0; c1 < TargetPlaces.size(); c1++){
              printf("%.2f\t", adjacency[c][c1]);
          }cout <<"\n";
      }
      
    }
    int arraySum(int arr[], int n){
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += arr[i];
        }
        return sum;
    }
    vector<int> shortestDistance(){
        //Return the shortest tour;
        vector<int> order;
        order.push_back(1);
        int status[counter];
        status[0] = 1;
        for (int i = 1; i < counter; i++){
            status[i] = 0;
        }
        int nextNode = nearestCity(0, status) + 1;        
        counter--;
        while (counter > 0){
            order.push_back(nextNode);
            nextNode = nearestCity(nextNode - 1, status) + 1;
            counter--;
        }
        return order;
        
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
        ofstream result;
        result.open("fnl_soln.ttp");

        //Trip order
        
        for (int c = 0; c < CitiesWithItems + 1; c++){
            result << ShortestTripNoSteal[c];
            if(c < CitiesWithItems) result << ",";
        }
        result <<"\n";

        cout <<"[";
        for (int c = 0; c < CitiesWithItems + 1; c++){
            cout << ShortestTripNoSteal[c];
            if(c < CitiesWithItems) cout << ",";
        }
        cout <<"]\n";
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
        
        //Picking order
        for (int i = 0; i < pickingOrder.size(); i++){
            result << pickingOrder[i];
            if(i < pickingOrder.size() - 1) result << ",";
        }
        result <<"\n";
    }
};

int main(){
	/*	Given test case on myuni
	Tour a;
	a.addCity(0, 0);
    a.addCity(10, 0);
    a.addCity(0, 10);
    a.addCity(10, 10);
    
    TheThief tt;
    tt.setSpeed1(0.1);
    tt.setSpeed2(1);
    tt.setRent(1.0);
    tt.setWeight(100);
    tt.setTrip(a);

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