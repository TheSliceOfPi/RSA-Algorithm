
#include <iostream>
#include <fstream>
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"
using namespace std;

int main(int argc, char** argv)
{
	string keyFile=argv[1];
	string inputFile=argv[2];
	string outputFile=argv[3];
  ifstream fin(keyFile);
  string d;
  string n;
  fin >> d;
  fin >> n;
  ReallyLongInt dR=ReallyLongInt(d);
  ReallyLongInt nR=ReallyLongInt(n);
  ifstream fin2(inputFile);
  ofstream fout(outputFile);
  string num;
  fin2>>num;
  ReallyLongInt numR=ReallyLongInt(num);
  while(!fin2.eof())
    {
      ReallyLongInt newNum=modPower(numR,dR,nR);
      long long newNumLL=newNum.toLongLong();
      char reWrite=newNumLL;
      fout<< reWrite;
      fin2>>num;
      numR=num;
    }
}
