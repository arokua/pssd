#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class LightSwitches{
public:
	long countPossibleConfigurations(vector<string> switches){
		size_t connected = 0; //How many bulbs connected to current switch
		int total_switch = switches.size();
		if (total_switch == 0) return 0;
		else if (total_switch == 1){
			connected = count(switches[0].begin(), switches[0].end(), 'Y');
			if (connected) return 2;// 2 states all connected on or off only since only 1 switch
			else return 0;
		}
		int total_bulb = switches[0].length();
		vector<int> connectivity;
		connectivity.reserve(total_bulb);
		fill(connectivity.begin(), connectivity.end(),0);
		int distinct_connection = 0;
		for (int i = 0; i < total_switch; i++){
			for (int bulb = 0; bulb < total_switch; bulb++){
				if (switches[i][bulb] == 'Y'){
					connectivity[bulb] = 1;
				}
			}
		}
		for (int bulb = 0; bulb < total_bulb; bulb++){
			if (connectivity[bulb]) distinct_connection++;
		}
		return pow(2.0, 1.0*distinct_connection);
	}
};