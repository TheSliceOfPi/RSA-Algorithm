#include <iostream>
template <class X>

bool isPrime(const X& num)
{
  X zero;
  zero=0;
  X one;
  one = 1;
  if(num==zero|| num==one)
    {
      return false;
    }
  X divisor= 2;
  while(divisor<=(num/2))
    {    
      if(num%divisor==0)
	{
	  return false;
	}
      divisor=divisor+1;
    }
  return true;

}


template <class X>

X modPower(const X& base, const X& exponent,const X& modulus)
{
  X calculation=base%modulus;
  if (exponent==0)
    {
		X zeroed=1;
      return zeroed;
    }	
  
  if (exponent==1)
    {
		calculation=calculation%modulus;
      return calculation;
    }	
  else
    {
      
      X exponential=exponent/2;
      X partialCalc=modPower(base,exponential,modulus);
      calculation=(partialCalc%modulus)*(partialCalc%modulus) %modulus;
      if (exponent%2 ==0)
	{
	calculation=calculation%modulus;
	return calculation;
	}
	else 
	  {
	    calculation=calculation*(base%modulus);
	    calculation=calculation%modulus;
	    return calculation;
	  }
	
    }


}
template <class X>
X extendedEuclid(const X& a, const X& b, X* x, X* y)
{
	X temp;
	X gcd;
  if(b==0)
    {
      *x=1;
      *y=0;
      return a;
    }
  else
    {
      gcd=extendedEuclid(b,a%b,x,y);
      temp=*x;
      *x=*y;
      *y=temp-((*y )*(a/b));
      return gcd;
    }	
}
