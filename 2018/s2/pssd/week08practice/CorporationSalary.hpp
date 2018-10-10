#include <vector>

#include <string>


using namespace std;



/*class Dict{
    string name;
    
    public:
    Dict(int n){
        if (n == 0){
            vector<string> name;
        }
    }
    void addElement(string element){
        
    }
};



class makeClass{
   public:
   void makeDict(string name, int type){
       // 0: string, 1 : int, 2: double
       Dict name;
   }
};*/



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

            if (countEmployees(relations[i]) > 0 ){

                re += countEmployees(relations[i]);

            }else {

                re += 1;

            }

        }

        

	return re;

    }

};