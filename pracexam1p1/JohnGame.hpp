#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class JohnGame{
	public:
	int guessNumber(vector<int> guesses, vector<int> answers) {
		int currentAnsp;
		int currentAnsm;
		int previousAnsp = 0;
		int previousAnsm = 0;

		int ret;

		if (guesses.size() == 1){
			if (guesses[0] + answers[0] < 1000000000 && guesses[0] - answers[0] > 1) {
			 	return -1;
			}else if (guesses[0] + answers[0] < 1000000000 && guesses[0] - answers[0] < 1){
				return guesses[0] + answers[0];
			}else if (guesses[0] + answers[0] > 1000000000 && guesses[0] - answers[0] > 1){
				return guesses[0] - answers[0];
			}
		}
		for (int i = 0; i <int(guesses.size()); i++){
			 if (guesses[i] + answers[i] < 1000000000) {
			 	currentAnsp = guesses[i] + answers[i];
			 	if (i > 1 && guesses[i - 1] + answers[i - 1] < 1000000000) 
			 		previousAnsp = guesses[i - 1] + answers[i - 1];
			 	}
			
			if (guesses[i] - answers[i] > 1) {
			 	currentAnsp = guesses[i] - answers[i];
			 	if (i > 1 &&( guesses[i - 1] - answers[i - 1] > 1)) {
			 		previousAnsp = guesses[i - 1] - answers[i - 1];
			 	}
			}
			if (currentAnsp == previousAnsm ){
				return currentAnsp;
				break;
			}else if ( currentAnsm == previousAnsp){
				return currentAnsm;
				break;
			}

		}



	}
};
