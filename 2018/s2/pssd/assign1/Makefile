EXECS= TTP 
MYALL:=${wildcard shared-*.ttp}
TTP_FILE:=TTP.cpp ${wildcard TTP-*.cpp}

# C++ 11 as default since old version might not have
CXXFLAGS=--std=gnu++11 -I. -Iincludes 

all: ${EXECS} 
	./TTP  > fnl_soln.ttp;
TTP: ${TTP_FILE} ${MYALL} 
	g++ ${CXXFLAGS} -o $@ $^ 

	-@read -p "" input ;\
	echo $$input;\
	./TTP $$input >fnl_soln.ttp;
clean:
	-rm -rf ${EXECS} *.o

%.o: %.cpp %.h
	g++ ${CXXFLAGS} -c $<