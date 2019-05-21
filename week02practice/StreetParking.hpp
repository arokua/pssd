#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#ifndef STREETPARKING_H
#define STREETPARKING_H

class StreetParking {
public:
	StreetParking();
	int freeParks(std::string);
};
#endif
StreetParking::StreetParking() {}
int StreetParking::freeParks(std::string street){
	//Final value
	int slots = 0;
	//Count empty slot from the last position
	int space = 0;
	char begun, end= '|';
	int counter = 0;
	int myIndex;
	vector<int> currentFreePositions;
	vector<string> frontNBack;
	///Categorize input
	for (int i =0; i < int (street.length()); i++){
		if (street[i] == '-'){
			space++;
			if (i == int(street.length()) - 1) {
				currentFreePositions.push_back(space);
				if (counter % 2 == 1) frontNBack.push_back(to_string(end));	
				else frontNBack.push_back(to_string(begun));	
			}
		}
		else {
			counter++;
			if (counter == 1) {
				begun = street[i];
				if (space > 0) {
					currentFreePositions.push_back(i);
					frontNBack.push_back(to_string(street[i]));
					space = 0;
				}
			}else{
				if (counter == 2) end = street[i];
				else begun = end; end = street[i];
				if (space > 0) {
					currentFreePositions.push_back(space);
					frontNBack.push_back(to_string(begun) + to_string(end));
					space = 0;
				}
			}				
		}			
	}
	if (frontNBack.size() == 0) return 0;
	//Process input and calc answer
	for (int c = 0; c < int(frontNBack.size()); c++){
		//Begin or end with 'B'
		if (frontNBack[c] == "66" or frontNBack[c] == "6666") slots += max(0, currentFreePositions[c] - 2);
		else if (frontNBack[c] == "6668") slots += currentFreePositions[c];
		else if (frontNBack[c] == "6683") slots += currentFreePositions[c] - 1;
		else if (frontNBack[c] == "8366") slots += max(0, currentFreePositions[c] - 3);
		else if (frontNBack[c] == "6866") slots += max(0, currentFreePositions[c] - 2);
		//Begin or end with 'S'
		else if (frontNBack[c] == "8368" or frontNBack[c] == "6883" or frontNBack[c] == "83") slots += max(0, currentFreePositions[c] - 1);
		else if (frontNBack[c] == "8383") slots += max(0, currentFreePositions[c] - 2);
		//DD and D left
		else slots += currentFreePositions[c];
	}
	return slots;
}