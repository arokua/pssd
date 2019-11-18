#Make ttp file to executable
EXECS = TTP

MYALL:=${wildcard shared-*.ttp}

TTP_FILE:=TTP.cpp ${wildcard TTP-*.cpp}



CXXFLAGS=--std=gnu++11 -I. -Iincludes

all: ${EXECS}

TTP: ${TTP_FILE} ${MYALL}
	g++ ${CXXFLAGS} -o $@ $^
clean:
	-rm -rf ${EXECS} *.o

%.o: %.cpp %.h
	g++ ${CXXFLAGS} -c $<