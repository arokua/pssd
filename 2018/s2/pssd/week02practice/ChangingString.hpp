#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class ChangingString { public: int distance(string A, string B, int K) { int d = 0; for (int i =0; i < K;i++){ d+= abs(A.at(i) - B.at(i)); } return d; } };