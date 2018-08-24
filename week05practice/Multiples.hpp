#include <cmath>

using namespace std;

class Multiples{

	public:
		int number(int min, int max, int factor){
			int a = 0;
  
  			for (int i = min; i <max + 1; i++){
      			if (i % factor == 0){
          			a++;
     			}
  			}
  			return a;
  		}
};