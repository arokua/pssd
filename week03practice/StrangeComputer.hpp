#include <iostream>
#include <string>

using namespace std;

class StrangeComputer {
    public:
      int setMemory(string mem){
        int ret = 0;
        char c = '0';
    
        for (int i=0; i<mem.size(); i++)
          if (mem[i] != c)
    	{
    	  ret++;
    	  c = mem[i];
    	}
    
        return ret;
      }
};