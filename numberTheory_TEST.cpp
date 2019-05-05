#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"


TEST_CASE("Testing numberTheory functions")
{
  SECTION("Testing modPower")
    {
		ReallyLongInt rliBase(2);
		ReallyLongInt rliExpo(2);
		ReallyLongInt rliModul(3);
		ReallyLongInt rli=modPower(rliBase,rliExpo,rliModul);
		string rliS=rli.toString();
		REQUIRE(rliS=="1");
		
		long long base=2;
		long long expo=2;
		long long modul=3;
		long long gdp=modPower(base,expo,modul);
		REQUIRE(gdp==1);
		
		
		rliBase=2;
		rliExpo=3;
		rliModul=3;
		rli=modPower(rliBase,rliExpo,rliModul);
		rliS=rli.toString();
		REQUIRE(rliS=="2");
		
		rliBase=2;
		rliExpo=0;
		rliModul=3;
		rli=modPower(rliBase,rliExpo,rliModul);
		rliS=rli.toString();
		REQUIRE(rliS=="1");
		
		base=2;
		 expo=3;
		modul=3;
		 gdp=modPower(base,expo,modul);
		REQUIRE(gdp==2);
		
		rliBase=12;
		rliExpo=12;
		rliModul=123;
		rli=modPower(rliBase,rliExpo,rliModul);
		rliS=rli.toString();
		REQUIRE(rliS=="66");
		
		base=12;
		 expo=12;
		modul=123;
		 gdp=modPower(base,expo,modul);
		 REQUIRE(gdp==66);
		
		 rliBase=10;
		 rliExpo=19;
		 rliModul=1019;
		 rli=modPower(rliBase,rliExpo,rliModul);
		 
		 rliS=rli.toString();
		 REQUIRE(rliS=="776");
		
		 base=10;
		 expo=19;
		 modul=1019;
		 gdp=modPower(base,expo,modul);
		 REQUIRE(gdp==776);
		 
		 rliBase=12345;
		 rliExpo=1234567;
		 rliModul=123;
		 rli=modPower(rliBase,rliExpo,rliModul);
		 
		 rliS=rli.toString();
		 REQUIRE(rliS=="66");
		
		 base=12345;
		 expo=1234567;
		 modul=123;
		 gdp=modPower(base,expo,modul);
		 REQUIRE(gdp==66);
		
		rliBase=12345;
		 rliExpo=1234567;
		 rliModul=123456789;
		 rli=modPower(rliBase,rliExpo,rliModul);
		 
		 rliS=rli.toString();
		 REQUIRE(rliS=="100842075");
		
		 base=12345;
		 expo=1234567;
		 modul=123456789;
		 gdp=modPower(base,expo,modul);
		 REQUIRE(gdp==100842075);
		 
		 
		 rliBase=12345;
		 rliExpo=123456789;
		 rliModul=12345;
		 rli=modPower(rliBase,rliExpo,rliModul);
		 
		 rliS=rli.toString();
		 REQUIRE(rliS=="0");
		
		 base=12345;
		 expo=123456789;
		 modul=12345;
		 gdp=modPower(base,expo,modul);
		 REQUIRE(gdp==0);
		 
		 rliBase=12345;
		 rliExpo=123456789;
		 rliModul=1234567891011;
		 rli=modPower(rliBase,rliExpo,rliModul);
		 
		 rliS=rli.toString();
		 REQUIRE(rliS=="519170861217");
		 
		 rliBase=2649150;
		 rliExpo=3259469;
		 rliModul=16305469;
		 rli=modPower(rliBase,rliExpo,rliModul);
		 
		 rliS=rli.toString();
		 REQUIRE(rliS=="104");
    }
  SECTION("Testing isPrime")
    {
      ReallyLongInt x;
      long long y;
      x=2;
      y=2;
      bool xB=isPrime(x);
      bool yB=isPrime(y);
      REQUIRE(xB==true);
      REQUIRE(yB==true);
      
      x=3;
      y=3;
      xB=isPrime(x);
      yB=isPrime(y);
      REQUIRE(xB==true);
      REQUIRE(yB==true);
      
      x=4513 ;
      y=12;
      xB=isPrime(x);
      yB=isPrime(y);
      REQUIRE(xB==true);
      REQUIRE(yB==false);
      
      x=0;
      y=1;
      xB=isPrime(x);
      yB=isPrime(y);
      REQUIRE(xB==false);
      REQUIRE(yB==false);
      
      
      
    }
  SECTION("Testing extendedEuclid")
    {
    long long x;
    long long y;
    long long q=60;
    long long w=24;
    long long gcd=extendedEuclid(q,w,&x,&y);
    REQUIRE(gcd==12);
    REQUIRE(x==1);
    REQUIRE(y==-2);
    
    ReallyLongInt rx;
    ReallyLongInt ry;
    ReallyLongInt rq=60;
    ReallyLongInt rw=24;
    ReallyLongInt rgcd=extendedEuclid(rq,rw,&rx,&ry);
    REQUIRE(rgcd==12);
    REQUIRE(rx==1);
    REQUIRE(ry==-2);
    
    
    q=6;
    w=24;
    gcd=extendedEuclid(q,w,&x,&y);
    REQUIRE(gcd==6);
    REQUIRE(x==1);
    REQUIRE(y==0);
    
	rq=6;
    rw=24;
    rgcd=extendedEuclid(rq,rw,&rx,&ry);
    REQUIRE(rgcd==6);
    REQUIRE(rx==1);
    REQUIRE(ry==0);
    
    q=0;
    w=24;
    gcd=extendedEuclid(q,w,&x,&y);
    REQUIRE(gcd==24);
    REQUIRE(x==0);
    REQUIRE(y==1);
    
	rq=0;
    rw=24;
    rgcd=extendedEuclid(rq,rw,&rx,&ry);
    REQUIRE(rgcd==24);
    REQUIRE(rx==0);
    REQUIRE(ry==1);
    
	q=12;
    w=89;
    gcd=extendedEuclid(q,w,&x,&y);
    REQUIRE(gcd==1);
    REQUIRE(x==-37);
    REQUIRE(y==5);
    
	 rq=89;
    rw=12;
     rgcd=extendedEuclid(rq,rw,&rx,&ry);
    string sgcd=rgcd.toString();
    string srx=rx.toString();
    string sry=ry.toString();
    REQUIRE(sgcd==1);
    REQUIRE(srx==5);
    REQUIRE(sry==-37); 
    
    
    rq=5915587277;
    rw=1500450271;
    rgcd=extendedEuclid(rq,rw,&rx,&ry);
    sgcd=rgcd.toString();
    srx=rx.toString();
     sry=ry.toString();
    REQUIRE(sgcd==1);
    REQUIRE(srx=="747020821");
    REQUIRE(sry=="-2945160496"); 
    ReallyLongInt added= ry;
      
      
      
    }
}
