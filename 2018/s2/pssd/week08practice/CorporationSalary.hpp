#include <map>
#include <vector>
#include <string>

class CorporationSalary{
    private:
    map <int, vector<int> > relationships;
    vector<int> salaries;// Individual salaries
    public:
    long salary_calc( int employee){
        //Calculate the salary of the employee
        int total_subr = relationships[employee].size();
        if (total_subr > 1){
            salaries[employee] = 0;
            for (int i = 0; i < total_subr; i++){
                salaries[employee] += salary_calc(relationships[employee][i]);
            }
        }
        return salaries[employee];
    }
    long totalSalary(vector<string> relations){
        int totalworkers = relations.size();
        for (int i = 0; i < totalworkers; i++){
            salaries.push_back(1);
        }
        //Start adding employees to the map
        for (int e = 0; e < totalworkers; e++){
            relationships[e].reserve(0);
            for (int c = 0; c < int(relations[e].length()); c++){
                if (relations[e][c] == 'Y') relationships[e].push_back(c);
            }
        }
        //Calculate all the salaries
        long result = 0;
        for (int k = 0; k < totalworkers; k++){
            result = result + salary_calc(k);
        }
        return result;
    }
};