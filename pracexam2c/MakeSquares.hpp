#include <algorithm>

using namespace std;

class MakeSquares{
public:
	int maxCount(int N){
		if (N == 4){
			return 1;
		}
		if (N % 2 == 1){
			return maxCount(N - 1);
		}else {
			return (1 + maxCount(N - 2)) * 1;
		}
	}
};;