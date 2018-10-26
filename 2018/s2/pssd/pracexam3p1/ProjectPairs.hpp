#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class ProjectPairs{
public:
	int minDiff(vector<int> practice){
		sort(practice.begin(), practice.end());
		int l = practice.size();
		
	

		if (practice[0] == practice[l]){
			// All members have same quality
			return 0;
		}

		vector<int> qualities;
		for (int i = 0; i < l/2; i++){
			qualities.push_back(practice[i] + practice[l - i - 1]);
			
		}
		sort(qualities.begin(), qualities.end());
		return qualities[qualities.size() - 1] - qualities[0];


	}
};