#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CellRemoval{
    public:
    vector<int> deleteCell(vector<int> cells, int unlucky){
        vector<int> newZ;
        vector<int> grandChildren;
        cout<<unlucky<<endl;
        
        for (int i = 0; i < int(cells.size()); i++){
            if (i != unlucky && cells[i] != unlucky && cells[i] != unlucky){
                newZ.push_back(cells[i]);
            }
            
            if (cells[i] == unlucky){
                grandChildren.push_back(i);
            }
            
            if ( cells[i] == -1 && i == unlucky){
                newZ.push_back(-1);
            }
        }
        
        for (int i = 0; i < newZ.size(); i++){
            cout << newZ[i] <<" ";
        }cout<<"Z\n";
        
        
        if ( grandChildren.size() == 1){
            newZ = deleteCell(newZ, grandChildren[0]);
        }
        else if (grandChildren.size() == 2){
            int a = grandChildren[0];
            int b = grandChildren[1];
            newZ = deleteCell(newZ,a);
            newZ = deleteCell(newZ,b);
        }
        if (grandChildren.size() == 0){
            return newZ;
        }   
    }
    
    int cellsLeft(vector<int> c, int d){
        if (c[d] == -1){
            return 0;
        }else {
            vector<int> z = deleteCell(c, d);
            sort(z.begin(),z.end());
            int l = 0;
            for (int i = 0; i < z.size() - 1; i++){
                if (z[i] != z[i + 1]){
                    l++;
                }
            }
            return l;
        }
    }
};