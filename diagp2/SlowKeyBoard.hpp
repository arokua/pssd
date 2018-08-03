#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class SlowKeyBoard {
	public:
		int enterTime(string tim){
			int needs = 0;
			int mins = 0;
			int secs = 0;
			
			mins = tim[0]* 10 + tim[1];
			secs = tim[3] * 10 + tim[4];

			while (true){
				secs += 1;
				needs += 1;
				if (secs > 59){
					secs = secs % 60;
					mins += 1;
					if (mins > 59){
						mins = mins % 60;
					}

					if (secs == mins){
						return 4;
						break;
					}
				}
			}
		}

};