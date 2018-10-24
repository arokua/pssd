#include <vector>
#include <string>

using namespace std;

class CorporationSalary{

    public:

    int countEmployees( string staff){

        int employed = 0;

        for (int i = 0; i < int(staff.length()); i++){

            if (staff[i] == 'Y'){

                employed++;

            }

        }

        return employed;

    }



    long totalSalary(vector<string> relations){

        vector<int> employed;

        long re = 0;

        employed.reserve(relations.size());

        for (int i = 0; i < relations.size(); i++){
        	int employees = countEmployees(relations[i]);
            if (employees > 0 ){
                re += employees;
            }else if (employees == 1){
                re += 1;
            }else {
            	re += 0;
            }
        }

	return re;
    }
};