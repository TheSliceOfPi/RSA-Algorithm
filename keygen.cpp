#include <iostream>
#include <fstream>
#include <cstdlib>
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"
using namespace std;
int main(int argc, char** argv)
{
	string pN=argv[1];
	string qN=argv[2];
	ReallyLongInt p= pN;
	ReallyLongInt q= qN;
	ReallyLongInt limit=100000;
	string publicKey=argv[3];
	string privateKey=argv[4];
	if(p>limit ||q>limit )
	{
		cout<<"At least one of the arguments provided is larger than 100,000, so Primality was not verified. Keys still created."<<endl;
	}
  if ((p<=limit && isPrime(p)==false )||(q<=limit && isPrime(q)==false))
    {    
      cout<< "Sorry, at least one of the numbers you entered is not prime. Will not create keys." <<endl;
      return 1;
    }
  ofstream pubK(publicKey);
  
  ofstream privK(privateKey);
  
  ReallyLongInt n=p*q;
  ReallyLongInt t=(p-1)*(q-1);
  ReallyLongInt e=2;
  ReallyLongInt x=1;
  ReallyLongInt y=0;
    while (extendedEuclid(e,t,&x,&y)!=1 && e<t) //If ExtEUcl works
      {
			e=e+1;
			
      }
  ReallyLongInt d=x; 
  
    if (d<0)
    {
	
      d=d+t;
    }
    
  pubK<< e << " " <<n;
  
  privK<< d << " "<<n;
  
  
}
