OPTS= -Wall

all:  keygen encrypt decrypt

tests: numberTheory_TEST  ReallyLongInt_TEST 

encrypt: encrypt.cpp numberTheory.tpp
	g++ ${OPTS} -o encrypt encrypt.cpp ReallyLongInt.cpp

decrypt: decrypt.cpp  numberTheory.tpp
	g++ ${OPTS} -o decrypt decrypt.cpp ReallyLongInt.cpp

numberTheory_TEST: numberTheory_TEST.cpp numberTheory.hpp ReallyLongInt.hpp catch.hpp
	g++ ${OPTS} --coverage -o numberTheory_TEST numberTheory_TEST.cpp ReallyLongInt.cpp

keygen:keygen.cpp numberTheory.tpp
	g++ ${OPTS} -o keygen keygen.cpp ReallyLongInt.cpp

ReallyLongInt.o: ReallyLongInt.cpp ReallyLongInt.hpp
	g++ ${OPTS} -c ReallyLongInt.cpp

ReallyLongInt_TEST: ReallyLongInt_TEST.cpp ReallyLongInt.cpp ReallyLongInt.hpp catch.hpp
	g++ ${OPTS} --coverage -o ReallyLongInt_TEST ReallyLongInt_TEST.cpp ReallyLongInt.cpp

