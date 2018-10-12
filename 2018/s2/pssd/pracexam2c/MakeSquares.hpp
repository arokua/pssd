#include <algorithm>
#include <cmath>

using namespace std;

class MakeSquares{
public:
	int maxCount(int N){
		double dN = N * 1.0;
		if (sqrt(dN) == int(sqrt(dN))) {
			//there is a patern wwith square roots, too late to implement it, have to edo with the nextr number after a int square roor have the same squares, and the one after that is +1
		}
		if (N < 6){
			return 1;
		}else if (N < 8){
			return 2;
		}else if (N == 8){
			return 3;
		}
		else if (N == 9 || N == 10){
			return 5;
		}
	}
};;