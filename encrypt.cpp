
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
  string e;
  string n;
  fin >> e;
  fin >> n;
  ReallyLongInt eR=ReallyLongInt(e);
  ReallyLongInt nR=ReallyLongInt(n);
  ifstream fin2(inputFile);
  ofstream fout(outputFile);
  char c;
  while(fin2.get(c))
    {
	ReallyLongInt cR=c;
      ReallyLongInt num=modPower(cR,eR,nR);
      fout<< num<<"\n";
    }
}
