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