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
            cout << TargetPlaces[i].getIdentity() << " ";
            cout << TargetPlaces[i].getX() << " " << TargetPlaces[i].getY() <<endl;
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