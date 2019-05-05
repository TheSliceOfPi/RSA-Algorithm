#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include "ReallyLongInt.hpp"
using namespace std;

ReallyLongInt::ReallyLongInt() //default Constructor
{
  isNeg=false;
  numDigits=1;
  unsigned* intArray=new unsigned[1];
  unsigned** temp=&intArray;
  intArray[0]=0;
  digits=*temp;
  
}
void ReallyLongInt::removeLeadingZeros(unsigned* x, unsigned& xSize) const
{
  unsigned check=0;
  while(x[check]==0 && xSize>1)
    {
      xSize=xSize-1; 
      check=check+1; 
    }
  for(unsigned i=0; i<xSize;i++)
    {
      x[i]=x[check];
      check=check+1;
    }
}
ReallyLongInt::ReallyLongInt(const string& numStr) //string Constructor
{
  numDigits=numStr.size();
  
  unsigned* intArray= new unsigned[numDigits];
  unsigned** temp=&intArray;
  unsigned i=0;
  isNeg=false;
  if(numStr[0]==45)
    {
      numDigits=numDigits-1;
      isNeg=true;
      i=1;
    }
  for (unsigned j=0; j<numDigits;j++)
    {
      unsigned num=int(numStr[i])-48;// Numbers on ASCII start at 48;
      intArray[j]=num;
      i++;
    }
  removeLeadingZeros(intArray,numDigits); //Remove leading Zeroes	
  if(intArray[0]==0)
    {
      isNeg=false;
    }
  digits=*temp;
}
ReallyLongInt::~ReallyLongInt()
{
  delete[] digits;
}

string ReallyLongInt::toString() const
{
  string num=""; //Empty string
  if(isNeg==true)
    {
      num=num+"-";
    }
  for(unsigned i=0;i<numDigits;i++)
    {
      num=num+to_string(digits[i]);
    }
  return num;
}

ReallyLongInt::ReallyLongInt(long long num) //num Constructor
{
  isNeg=false;
  numDigits=1;
  if (num<0)
    {
      isNeg=true;
      num=num*(-1);
      
    }
  if(num!=0)
    {
      numDigits=log10(num)+1;
      
    }
  unsigned* intArray=new unsigned[numDigits];
  unsigned** temp=&intArray;
  for(unsigned i=1;i<=numDigits;i++)
    {
      unsigned numSeg=num%10;
      num=num/10;
      intArray[numDigits-i]=numSeg;
    }
  
  digits=*temp;
}

ReallyLongInt::ReallyLongInt(const ReallyLongInt& other)  //Copy Constructor
{
  isNeg=other.isNeg;
  numDigits=other.numDigits;
  unsigned* intArray=new unsigned[numDigits];
  unsigned** temp=&intArray;
  for (unsigned i=0;i<numDigits;i++)
    {
      intArray[i]=other.digits[i];
    }
  digits=*temp;
  
  
}
ReallyLongInt::ReallyLongInt(unsigned* digitsArr, unsigned arrSize, bool isNeg) //private Constructor
{
  removeLeadingZeros(digitsArr,arrSize);
  digits=digitsArr;
  numDigits=arrSize;
  this->isNeg=isNeg;
  if(digits[0]==0)
    {
      this->isNeg=false;
    }
}
bool ReallyLongInt::equal(const ReallyLongInt& other) const
{
  if(isNeg!=other.isNeg)
    {
      return false;
    }
  if(numDigits != other.numDigits)
    {
      return false;
    }
  
  for(unsigned i=0; i<numDigits;i++)
    {
      if(digits[i] != other.digits[i]) //Not Equal
	{
	  return false;
	}
    }
  return true;
}
bool ReallyLongInt::absGreater(const ReallyLongInt& other) const
{
  if(numDigits > other.numDigits)
    {
      return true;
    }
  if(other.numDigits > numDigits)
    {
      return false;
    }
  for(unsigned i=0; i<other.numDigits;i++)
    {
      if(digits[i] > other.digits[i]) //this is Greater
	{
	  return true;
	}
      if (other.digits[i] > digits[i]) //other is Greater
	{
	  return false;
	}
    }
  return false;
}
bool ReallyLongInt::greater(const ReallyLongInt& other) const
{
	if(equal(other)==true)
	{
		return false;
	}
  if(isNeg==false && other.isNeg==true)
    {
      return true;
    }
  if(isNeg==true && other.isNeg==true)
    {
      if(absGreater(other)==true)
	{
	  return false;
	}
      return true;
    }
  if(isNeg==false && other.isNeg==false)
    {
      if(absGreater(other)==true)
	{
	  return true;
	}
      return false;
    }
  return false;
		
}
ReallyLongInt ReallyLongInt:: absAdd(const ReallyLongInt& other) const
{
  string first=toString();
  string nFirst="-"+first;
  string second=other.toString();
  string nSecond="-"+second;
  if(absGreater(other)==false && equal(other)==false && first!=nSecond && nFirst!=second)
    {
      ReallyLongInt flip=other.absAdd(*this);
      return flip;
    }
  unsigned num=0;
  unsigned carryOver=0;
  unsigned* intArray= new unsigned[numDigits+1];
  for(unsigned i=1;i<=numDigits;i++)
    {
      if(other.numDigits<i)
	{
	  num=digits[numDigits-i]+carryOver;
	  carryOver=num/10;
	  intArray[numDigits+1-i]=num%10;
	
	}
      if(other.numDigits>=i)
	{
	  num=digits[numDigits-i]+other.digits[other.numDigits-i]+carryOver;
	  carryOver=num/10;
	  intArray[numDigits+1-i]=num%10;
			
	}
      
    }
  intArray[0]=carryOver;
  ReallyLongInt add= ReallyLongInt(intArray,numDigits+1,false);
  return add;
}

ReallyLongInt ReallyLongInt::add(const ReallyLongInt& other) const 
{
	if(isNeg==true && other.isNeg==false)
	{
		ReallyLongInt flipToSub=other.absSub(*this);
		return flipToSub;
		}
	if( isNeg==false && other.isNeg==true)
	{
		ReallyLongInt flipToSub2=absSub(other);
		return flipToSub2;
	}
	if(isNeg==true && other.isNeg==true)
	{
		ReallyLongInt added=absAdd(other);
		added.flipSign();
		return added;
		
	}
  ReallyLongInt added=absAdd(other);
  return added;
}
	
ReallyLongInt ReallyLongInt::absSub(const ReallyLongInt& other) const //Private sub
{
  if(equal(other))
    {
      ReallyLongInt cancel=ReallyLongInt();
      return cancel;
    }
    
  if(absGreater(other)==false)
    {
      string first=toString();
      string nFirst="-"+first;
      string second=other.toString();
      string nSecond="-"+second;
      if(first==nSecond || nFirst==second)
	{
	  ReallyLongInt cancel=ReallyLongInt();
	  return cancel;
	}
      ReallyLongInt flip=other.absSub(*this);
      string flipS=flip.toString();
      string nFlipS="-"+flipS;
      ReallyLongInt flipNeg=ReallyLongInt(nFlipS);
      return flipNeg;
    }
  unsigned added=10;
  unsigned remove=0;
  unsigned* intArray= new unsigned[numDigits];
  for(unsigned i=1;i<=numDigits;i++)
    {
      if(other.numDigits<i)
	{
	  intArray[numDigits-i]=(digits[numDigits-i]-remove)-0;
	  remove=0;
	
	}
      if(other.numDigits>=i)
	{
	  if(digits[numDigits-i] <other.digits[other.numDigits-i]+remove)
	    {
	      intArray[numDigits-i]=(added+digits[numDigits-i]-remove)-other.digits[other.numDigits-i];
	      remove=1;
	      
			
	    }
	  if(digits[numDigits-i]>=other.digits[other.numDigits-i]+remove)
	    {
			if((digits[numDigits-i]<remove && other.digits[other.numDigits-i]==0))
			{
				intArray[numDigits-i]=(added+digits[numDigits-i]-remove)-other.digits[other.numDigits-i];
	      remove=1;
				}
			  else
			  {
	      intArray[numDigits-i]=(digits[numDigits-i]-remove)-other.digits[other.numDigits-i];
	      remove=0;
	  }
	    }
			
	}
      
    }
  ReallyLongInt subt= ReallyLongInt(intArray,numDigits,false);
  return subt;
}
ReallyLongInt ReallyLongInt::sub(const ReallyLongInt& other) const
{
	if( isNeg==false && other.isNeg==true)
	{
		ReallyLongInt flipToAdd2=absAdd(other);
		return flipToAdd2;
	}
	if(isNeg==true && other.isNeg==true)
	{
		ReallyLongInt flipToAdd=other.absSub(*this);
		return flipToAdd;	
	}
	if(isNeg==true && other.isNeg==false)
	{
		ReallyLongInt flipToAdd2=absAdd(other);
		flipToAdd2.flipSign();
		return flipToAdd2;
		}
  ReallyLongInt subt=absSub(other);
  return subt;
	
}

ostream& operator<<(ostream& out, const ReallyLongInt& x)
{
  ostream& addToStream=out<<x.toString();
  return addToStream;
}
void ReallyLongInt::swap(ReallyLongInt other)
{
  ReallyLongInt tempOther=ReallyLongInt(other);
	
  bool tempisNeg=isNeg;
  const unsigned* tempDigits=digits;
  unsigned tempnumDigits=numDigits;
   
  digits=tempOther.digits;
  isNeg=tempOther.isNeg;
  numDigits=tempOther.numDigits;
	
  tempOther.digits=tempDigits;
  tempOther.isNeg=tempisNeg;
  tempOther.numDigits=tempnumDigits;

	
	
}
ReallyLongInt& ReallyLongInt::operator=(const ReallyLongInt& other)
{
  swap(other);
	
  return *this;
}

bool operator==(const ReallyLongInt& x, const ReallyLongInt& y)
{
  bool eq=x.equal(y);
  return eq;
}
bool operator!=(const ReallyLongInt& x, const ReallyLongInt& y)
{
  bool noEq=!(x.equal(y));
  return noEq;
}
bool operator>(const ReallyLongInt& x, const ReallyLongInt& y)
{
  bool great=x.greater(y);
  return great;
}
bool operator<(const ReallyLongInt& x, const ReallyLongInt& y)
{
  bool nGreat=y.greater(x);
  return nGreat;
}
bool operator>=(const ReallyLongInt& x, const ReallyLongInt& y)
{
  bool greatEq=(x.greater(y) || x.equal(y));
  return greatEq;
}
bool operator<=(const ReallyLongInt& x, const ReallyLongInt& y)
{
  bool nGreatEq=(y.greater(x) || x.equal(y));
  return nGreatEq;
}
void ReallyLongInt::flipSign()
{
  bool checked=false;
  if(digits[0]==0)
    {
      isNeg=false;
      checked=true;
    }
  if(isNeg==true && checked==false)
    {
      isNeg=false;
      checked=true;
    }
  if(isNeg==false && checked==false)
    {
      isNeg=true;
    }
}
ReallyLongInt ReallyLongInt:: operator-() const
{ 
  ReallyLongInt flipped=ReallyLongInt(*this);
  flipped.flipSign();
  return flipped;
}
ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y)
{
  ReallyLongInt added=x.add(y);
  return added;
}
ReallyLongInt operator-(const ReallyLongInt& x, const ReallyLongInt& y)
{
  ReallyLongInt subt=x.sub(y);
  return subt;
}
ReallyLongInt& ReallyLongInt::operator+=(const ReallyLongInt& other)
{
  ReallyLongInt add=*this+other;
  *this=add;
  return *this;
	
}
ReallyLongInt& ReallyLongInt:: operator-=(const ReallyLongInt& other)
{
  ReallyLongInt sub=*this-other;
  *this=sub;
  return *this;
}
ReallyLongInt& ReallyLongInt:: operator++()
{
  ReallyLongInt one=ReallyLongInt(1);
  ReallyLongInt addOne=*this+one;
  *this=addOne;
  return *this;
}
ReallyLongInt& ReallyLongInt::operator--()
{
  ReallyLongInt one=ReallyLongInt(1);
  ReallyLongInt subOne=*this-one;
  *this=subOne;
  return *this;
}
ReallyLongInt ReallyLongInt:: operator++(int dummy)
{
  ReallyLongInt copy=ReallyLongInt(*this);
  ReallyLongInt one=ReallyLongInt(1);
  ReallyLongInt addOne=*this+one;
  *this=addOne;
  return copy;
}
ReallyLongInt ReallyLongInt::operator--(int dummy)
{
  ReallyLongInt copy=ReallyLongInt(*this);
  ReallyLongInt one=ReallyLongInt(1);
  ReallyLongInt subOne=*this-one;
  *this=subOne;
  return copy;
}
ReallyLongInt ReallyLongInt::absMult(const ReallyLongInt& other) const
{
	string first=toString();
  string nFirst="-"+first;
  string second=other.toString();
  string nSecond="-"+second;
  if(digits[0]==0 ||other.digits[0]==0)
    { 
      ReallyLongInt zeroed= ReallyLongInt();
      return zeroed;
    }
  if(absGreater(other)==false && equal(other)==false && first!=nSecond && nFirst!=second)
    {
      ReallyLongInt flip= other.absMult(*this);
      return flip;
    }
  unsigned size=numDigits+other.numDigits;
  unsigned* intArray=new unsigned[size];
  for(unsigned p=0;p<size;p++)
    {
      intArray[p]=0;
    }
  unsigned num=0;
  for (unsigned i=0; i<other.numDigits;i++)
    {
      for (unsigned j=0; j<numDigits;j++)
	{
	  num=(digits[numDigits-1-j]*other.digits[other.numDigits-1-i])+intArray[size-1-j-i];
	  intArray[size-1-j-i]=num%10;
	  intArray[size-2-j-i]=(num/10)+intArray[size-2-i-j];
	}
    }
  ReallyLongInt absMultiply=ReallyLongInt(intArray,size,false);
  return absMultiply;
}
	
ReallyLongInt ReallyLongInt:: mult(const ReallyLongInt& other) const
{
  if(isNeg==true && other.isNeg==false)
    {
      ReallyLongInt multiply=absMult(other);
      multiply.flipSign();
      return multiply;
		
    }
  if(isNeg==false && other.isNeg==true)
    {
      ReallyLongInt multiply=absMult(other);
      multiply.flipSign();
      return multiply;
		
    }
  ReallyLongInt multiply=absMult(other);
  return multiply;
}
ReallyLongInt operator*(const ReallyLongInt& x, const ReallyLongInt& y)
{
  ReallyLongInt multiplied=x.mult(y);
  return multiplied;
}
ReallyLongInt& ReallyLongInt::operator*=(const ReallyLongInt& other)
{
  ReallyLongInt multiply=*this*other;
  *this=multiply;
  return *this;
}
void ReallyLongInt::absDiv(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const
{
	ReallyLongInt r;
  r=0;
  unsigned d;
  unsigned* intArray=new unsigned[numDigits];
  for(unsigned i=0; i<numDigits;i++)
    {
	
      r=10*r;
      r=r+digits[i];
      d=0;
      while(r.absGreater(other)==true || r.equal(other)==true ||("-"+ r.toString())==other.toString())
	{
		
	  r=r.absSub(other);
	  d=d+1;
	}
      intArray[i]=d;
      remainder=r;
    }
  ReallyLongInt quot=ReallyLongInt(intArray,numDigits,false);
  quotient=quot;
  remainder=r;
}
void ReallyLongInt::div(const ReallyLongInt& denominator, ReallyLongInt& quotient, ReallyLongInt& remainder) const
{
  absDiv(denominator,quotient,remainder);
  if(isNeg==false && denominator.isNeg==true)
    {
      quotient=-quotient;
    }
  if(isNeg==true && denominator.isNeg==false)
    {
      quotient=-quotient;
      remainder=-remainder;
    }
  if(isNeg==true && denominator.isNeg==true)
    {
      remainder=-remainder;
    }
	
}
ReallyLongInt operator/(const ReallyLongInt& x, const ReallyLongInt& y)
{
  ReallyLongInt quotient;
  ReallyLongInt remainder;
  x.div(y,quotient,remainder);
  return quotient;
}
ReallyLongInt operator%(const ReallyLongInt& x, const ReallyLongInt& y)
{
  ReallyLongInt quotient;
  ReallyLongInt remainder;
  x.div(y,quotient,remainder);
  return remainder;
}

ReallyLongInt& ReallyLongInt::operator/=(const ReallyLongInt& other)
{
	ReallyLongInt div;
	div= *this/other;
  *this=div;
  return *this;
	   
}
ReallyLongInt& ReallyLongInt::operator%=(const ReallyLongInt& other)
{
  ReallyLongInt mod;
  mod= *this%other;
  *this=mod;
  return *this;
}
long long ReallyLongInt::toLongLong() const
{
	ReallyLongInt constant=ReallyLongInt(LLONG_MAX);
	++constant;
	constant=(*this%constant);
	long long num=0;
	long long power=1;
	for(unsigned i=0; i<constant.numDigits;i++)
	{
		num=num+(constant.digits[constant.numDigits-1-i]*power);
		power=power*10;
		
	}
	if(isNeg==true)
	{
		num=-num;
	}
	
	return num;
	
	}

