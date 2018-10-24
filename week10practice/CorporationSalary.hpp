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
            if (countEmployees(relations[i]) > 1 ){
                re += countEmployees(relations[i]);
            }else {
                re += 1;
            }
        }

	return re;
    }
};