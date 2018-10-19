#include <algorithm>

using namespace std;

class RockStar{
	int s = 0;
public:
	int getNumSongs(int ff, int fs, int sf, int ss){
		if (ff == 0 && fs == 0){
			if (ss == 0 && sf > 0){
				int a = s;
				s = 0;
				return a + 1;
			}else if (ss > 0 ){
				int a = s;
				s = 0;
				if (sf > 0){
					
					return a + ss + 1;
				}else {
					return a + ss;
				}
			}
		}

		else if (ff > 0 && fs == 0 ){
			int a = s;
			s = 0;
			return a + ff;
		}else if (fs > 0 ){
			if (sf == 0 && ss == 0 ){
				int a = s;
				s = 0;
				return a + 1;
			}
			s++;
			return getNumSongs(ff,fs-1,sf,ss);
		}
	}
};