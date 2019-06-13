#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Graph.h"
//Assuming input is always correct
using namespace std;

#ifndef BLOCKENEMY_H
#define BLOCKENEMY_H

static vector<string> ops;
class BlockEnemy {
public:
	BlockEnemy();
	int minEffort(int, vector<string>, vector<int>);
};
#endif

BlockEnemy::BlockEnemy() {

}

int BlockEnemy::minEffort(int towns, vector<string> roads, vector<int> targets){
	//Creating a Graph
	Graph Map(towns);
	int t1;
	int t2;
	int effort;
	int count = 0;
	for (int i = 0; i < int(roads.size()); i++){
		string thisRoad = roads[i];
		string temp = "";
		for (int j = 0; j < int(thisRoad.size()); j++){
			if ( thisRoad[j] != ' ') temp += thisRoad[j];
			else {
				if (count == 0) {
					t1 = stoi(temp.c_str());
				}
				else  {
					t2 = stoi(temp.c_str());
				}
				temp ="";
				count++;
			}
		}
		count = 0;
		effort = stoi(temp.c_str());
		cout <<t1 <<"\t" <<t2 <<"\t" << effort <<endl;
		Map.addEdge(t1, t2, true, effort);
	}
	cout << "The relation ship between towns by roads is:\n";
	Map.print();
	return 0;
}
