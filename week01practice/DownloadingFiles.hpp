#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class DownloadingFiles{
    public:
    double actualTime(vector<string> tasks){
        double toRe = 0;
        
        
        
        
        vector<pair <double,double>> SpdnT; // Spedd and time in double
        
        // Getting two seperate values;
        
        for (int i = 0; i < tasks.size(); i++){
            for (int j = 0; j < tasks[i].length();j++){
                if (tasks[i][j] == ' '){
                    
                    SpdnT.push_back(make_pair(stod(tasks[i].substr(0,j)), stod(tasks[i].substr(j+1, tasks[i].length() - 1))));
                    
                    break;
                }
            }
        }
        
        //Start looping over arrays elements to sort and calculate
        
        for (int n = 0; n < SpdnT.size(); n ++){
            
            double free = 0;// Speed left over
            double SmallestTime = 10000;
            int aPos = 0;
            for ( int a = 0; a < SpdnT.size(); a ++){
                // Getting the fastest time
                if (SpdnT[a].second > 0 and SpdnT[a].second < SmallestTime){
                    SmallestTime = SpdnT[a].second;
                }
            }
            
            toRe += SmallestTime;
            cout << toRe<<endl;
            // Decrease all current times by the min time
            for (int b = 0; b < SpdnT.size(); b++){
                SpdnT[b].second -= SmallestTime;
                if (SpdnT[b].second <=0){
                    SpdnT[b].second = 0;
                    free += SpdnT[b].first;
                }
                
                if ( SpdnT[b].second >0){
                    aPos = b;
                    
                }
        
                SpdnT[aPos].second = SpdnT[aPos].first*SpdnT[aPos].second/(SpdnT[aPos].first + free);
                SpdnT[aPos].first += free;
            }
        }
                
        
        return toRe;
    }
};