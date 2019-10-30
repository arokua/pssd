#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
class CorporationSalary{
    private:
    map <int, vector<int> > relationships;
    vector<long> salaries;// Individual salaries
    vector<int> deep_level;
    int max_level = 0;
    public:
    void print_employees(){
        for (int i = 0; i < relationships.size(); i++){
            cout << "employee number: "<<i <<" has : ";
            for (int j = 0; j < relationships[i].size(); j++){
                cout << relationships[i][j] <<" ";
            }
            cout << "; inverse salary level: " << deep_level[i] << endl;
            cout << "Salary: " << salaries[i] <<endl;
        }
        cout << "-------------------------------------\n";
    }
    int getDepths(int ID, int level){
        if (level == 0 || relationships[ID].size() == 0) deep_level[ID] = 0;
        else if (deep_level[ID] == -1){
            for (int i = 0; i < relationships[ID].size(); i++){
                deep_level[ID] = max(deep_level[ID], getDepths(relationships[ID][i], level - 1));
            }
            deep_level[ID]++;
        }
        return deep_level[ID];
    }

    long getSalary(int ID, int children){
        if (children == 0) salaries[ID]=1;
        if (salaries[ID] == 0){
            salaries[ID] = 0;
            for (int i = 0; i < children; i++){
                int this_guy = relationships[ID][i];
                salaries[ID] += getSalary(this_guy, relationships[this_guy].size());
            }
        }
        return salaries[ID];
    }
    void print_employee(int employ_no){
        cout << "employee number: "<<employ_no <<" has : ";
        for (int i = 0; i < relationships[employ_no].size(); i++){
            cout << relationships[employ_no][i] <<" ";              
        }
        //cout << "\ninverse salary level: " << deep_level[employ_no] << endl;
        cout << "\nSalary: " << salaries[employ_no] <<endl;
        cout << "------kakaka---\n";
    }
    long totalSalary(vector<string> relations){
        int totalworkers = relations.size();
        for (int i = 0; i < totalworkers; i++){
            salaries.push_back(0);
            deep_level.push_back(-1);
        }
        //Start adding employees to the map
        for (int e = 0; e < totalworkers; e++){
            relationships[e].reserve(0);
            for (int c = 0; c < int(relations[e].length()); c++){
                if (relations[e][c] == 'Y') relationships[e].push_back(c);                
            }
        }
        //Calculate employees -management order for each employees
        for (int e = 0; e < totalworkers; e++){
            max_level = max(max_level, getDepths(e, relationships[e].size()));
        }
        //print_employees();
        //Calculate all the salaries
        long result = 0;
        int counter = 0; //Start calculating from lowest level
        while (counter < max_level+1){
            //cout << "Inverse salary level " <<counter <<endl;
            for (int k = 0; k < totalworkers; k++){
                if (deep_level[k] == counter) 
                { //Current lowest employee with calculateable salary
                  result += getSalary(k, relationships[k].size());
                  //print_employee(k);
                }
            }
            counter++;
        }
        relationships.clear();
        salaries.clear();
        deep_level.clear();
        max_level = 0;
        return result;
    }
};