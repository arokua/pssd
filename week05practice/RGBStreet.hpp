#include <vector>
#include <algorithm>

using namespace std;

class RGBStreet {
    public:
        int getNum(string s, int position) {
            vector <int> n;
            int R = 0;

            int Rlength = 0;

            int G = 0;
            int Glength = 0;

            int B = 0;
            int Blength = 0;
            int mark = 0;

            for (int i = 0; i < int(s.length()); i++) {

                if (s[i] != ' ') {
                    
                    if (mark == 0) {
                        
                        Rlength += 1;
                        
                    } else if (mark == 1) {
                        
                        Glength += 1;
                    } else if (mark == 2) {
                        
                        Blength += 1;
                    } else if (mark > 2) {
                        break;
                    }
                } else if (s[i] == ' ') {
                    mark += 1;
                }
                
                
            }
            
            if (Rlength == 1){
                R = s[0] - 48;
            }else {
                R = stoi(s.substr(0,Rlength));
            }
            
            if (Blength == 1){
                B = s[s.length() - 1] - 48;
            }else {
                B = stoi(s.substr(Rlength + Glength +2 ,s.length()));
            }
            
            if (Glength == 1){
                G = s[Rlength + 1] - 48;
            }else {
                G = stoi(s.substr(Rlength + 1 ,Rlength + Glength + 1));
            }
            
            
            n.push_back(R);
            n.push_back(G);
            n.push_back(B);
            return n[position - 1];
        }
        
        int estimateCost(vector<string> ns){
            // Creating 3 vectors storing r ,g ,b values
            int sum = 3001;
            vector<int> r;
            vector<int> g;
            vector<int> b;
            
            for (int i = 0; i < int(ns.size()); i++){
                r.push_back(getNum(ns[i], 1));
                g.push_back(getNum(ns[i], 2));
                b.push_back(getNum(ns[i], 3));
                cout << r[i] << " " <<g[i]<<" "<< b[i] <<endl;
            }
            
            for(int i = 0; i < int(r.size()) ; i++){
                sum = min(sum, r[i] + g[i] +b[i]);
            }
            return sum;
        }
};