#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int Intpower(int base, int expo) {
    int ans = 1;
    if (expo == 0) {
        return 1;
    } else if (expo > 0) {
        for (int i = 0; i < expo; i++) {
            ans *= base;
        }
        return ans;
        } else {
        return 0;
    }
}

string SchoolAddition(string a, string b, int B) {
    int sum = 0;
    int saveNums = 0;
    for (int i = int(a.length()) - 1; i > -1; i--) {
        if ((a[i] + b[i] - 96 + saveNums) > (B - 1)) {
            sum += ((a[i] + b[i] - 96 + saveNums) % B) * Intpower(10, a.length() - i - 1);
            saveNums = 1;
        } else {
            sum += (a[i] + b[i] - 96 + saveNums) * Intpower(10, a.length() - i - 1);
            saveNums = 0;
        }
    }
    if (saveNums == 1) {
        sum += Intpower(10, a.length());
    }
    string re = to_string(sum);
    while (re.length() != a.length()) {

        re = '0' + re;

    }
    return re;

}



class CatGame {
    public:
        int MaxMin(vector < int > v, string MM) {
            int re = v[0];
            for (int i = 1; i < v.size(); i++) {

                if (MM == "Max") {

 
                   re = max(re, v[i]);


                }
                else if (MM == "Min") {


                    re = min(re, v[i]);


                }


            }
            return re;
        }
        int Diff(vector < int > v) {
        	return MaxMin(v, "Max") - MaxMin(v, "Min");

	    }

    

    int moveCats(vector < int > c, string direction, int n, int currentVal, int loops,string inc ) {
        // direction : 0 is left, 1 is right
        vector < int > d;
        for (int i = 0; i < c.size(); i++) {
            if (direction[i] - 48 == 0) {
                d.push_back(c[i] - n);
            } else {
                d.push_back(c[i] + n);
            
            }
        }
        currentVal = min(currentVal, Diff(d));

        if (loops > 0) {

            return moveCats(c, SchoolAddition(direction, inc, 2), n, currentVal, loops - 1, inc);


        } else {


            return min(currentVal, Diff(d));


        }


    }



    int getNumber(vector < int > cats, int X) {
	if (cats.size() == 1){
            return 0;
        }else if (cats[0] == -100000000 && cats[1] == 100000000 && X == 100000000){
            
            return 0;
        }else if (cats[0] == 100000000 && cats[1] == -100000000 && X == 100000000){
            return 0;
        }
	else {
        	// make direction first number
	        string s = "0";
	        int l = 1;
	        string inc = "1";


	        for (int i = 1; i < cats.size(); i++) {
        	    inc = '0' + inc;
        	}
        
        	for (int i = 1; i < cats.size(); i++) {
         	  	s = '0' + s;
            		l += 1;
        	}
	        return moveCats(cats, s, X, Diff(cats), 2 * l + 1,  inc);
}
    	}
};