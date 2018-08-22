#include <iostream>
#include <string>

using namespace std;


class SimpleCompressor{
    public:
        string uncompress(string data){
            int mul = 1;
            string ret = "";
            int index = 0;
            int counter = 0;
            
            for (int i = 0; i < data.length(); i++){
                if (data[i] == '['){
                    if (counter == 0){
                        ret = substr(0, i +1);
                        counter += 1;
                    }
                    mul *= data[i+1] -48;
                    if (data[i+2] == '['){
                        mul *= data[i+3];
                    }
                    // ret += mul*substr(from ith positoin something here, not sure it gonna work
                }
            }
            
            return ret;
        }
};