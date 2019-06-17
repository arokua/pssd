# all the executables
EXECS= TTP 
MYALL:=${wildcard shared-*.cpp}
TTP_FILE:=TTP.cpp ${wildcard TTP-*.cpp}

# C++ 11 as defualt since old version might not have
CXXFLAGS=--std=gnu++11 -I. -Iincludes 

all: ${EXECS}

test: ${TESTS}

TTP: ${TTP_FILE} ${MYALL} 
	g++ ${CXXFLAGS} -o $@ $^ > fnl_soln.ttp
clean:
	-rm -rf ${EXECS} *.o

%.o: %.cpp %.h
	g++ ${CXXFLAGS} -c $<