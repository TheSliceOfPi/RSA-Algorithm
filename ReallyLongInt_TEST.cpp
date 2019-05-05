#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ReallyLongInt.hpp"

TEST_CASE("Testing ReallyLongInt functions")
{
  SECTION("Testing Default Constructor")
    {
      ReallyLongInt p=ReallyLongInt();
      string k= p.toString();
      REQUIRE(k=="0");
    }
  SECTION("Testing string Constructor")
    {
      
      const string p="-000";
      ReallyLongInt q=ReallyLongInt(p);
      string k=q.toString();
      REQUIRE(k=="0");
      
      const string p1="-00089";
      ReallyLongInt q1=ReallyLongInt(p1);
      string k1=q1.toString();
      REQUIRE(k1=="-89");
      
      const string p2="00089";
      ReallyLongInt q2=ReallyLongInt(p2);
      string k2=q2.toString();
      REQUIRE(k2=="89");
      
      const string p3="0008900";
      ReallyLongInt q3=ReallyLongInt(p3);
      string k3=q3.toString();
      REQUIRE(k3=="8900");
      
    }
  SECTION("Testing num Constructor")
    {
      ReallyLongInt p=ReallyLongInt(75);
      string k=p.toString();
      REQUIRE(k=="75");
      
      ReallyLongInt p1=ReallyLongInt(-7500000);
      string k1=p1.toString();
      REQUIRE(k1=="-7500000");
      
      ReallyLongInt p3=ReallyLongInt(-75);
      string k3=p3.toString();
      REQUIRE(k3=="-75");
      
      ReallyLongInt p4=ReallyLongInt(-7500);
      string k4=p4.toString();
      REQUIRE(k4=="-7500");
      
      ReallyLongInt p5=ReallyLongInt(051);
      string k5=p5.toString();
      REQUIRE(k5=="41");
    }
  SECTION ("Testing copy Constructor")
    {
      ReallyLongInt p=ReallyLongInt(75);
      string pS=p.toString();
      ReallyLongInt pCopy= ReallyLongInt(p);
      string pSCopy=pCopy.toString();
      REQUIRE(pS==pSCopy);
      
      ReallyLongInt p1=ReallyLongInt(-8900);
      string pS1=p1.toString();
      ReallyLongInt pCopy1= ReallyLongInt(p1);
      string pSCopy1=pCopy1.toString();
      REQUIRE(pS1==pSCopy1);
    }
  /*SECTION("Testing Private Constructor") //Commented out because it is in Private mode now.
    {
      unsigned size=5;
      unsigned* intArray= new unsigned[size];
      for (unsigned i=0;i<size;i++)
	{
	  intArray[i]=i;
	}
      bool neg=true;
      ReallyLongInt p= ReallyLongInt(intArray,size,neg);
      string k=p.toString();
      REQUIRE(k=="-1234");
      
      size=7;
      unsigned* intArray1= new unsigned[size];
      for (unsigned i=0;i<size;i++)
	{
	  intArray1[i]=i;
	}
      neg=false;
      ReallyLongInt p1= ReallyLongInt(intArray1,size,neg);
      string k1=p1.toString();
      REQUIRE(k1=="123456");
      
      size=1;
      unsigned* intArray2= new unsigned[size];
      for (unsigned i=0;i<size;i++)
	{
	  intArray2[i]=i;
	}
      neg=true;
      ReallyLongInt p2= ReallyLongInt(intArray2,size,neg);
      string k2=p2.toString();
      REQUIRE(k2=="0");
      
		
		size=20;
      unsigned* intArray3= new unsigned[size];
      for (unsigned i=0;i<size;i++)
	{
	  intArray3[i]=i;
	}
      neg=true;
      ReallyLongInt p3= ReallyLongInt(intArray3,size,neg);
      string k3=p3.toString();
      REQUIRE(k3=="-12345678910111213141516171819");
      
      size=20;
      unsigned* intArray4= new unsigned[size];
      for (unsigned i=0;i<size;i++)
	{
	  intArray4[i]=i;
	}
      neg=false;
      ReallyLongInt p4= ReallyLongInt(intArray4,size,neg);
      string k4=p4.toString();
      REQUIRE(k4=="12345678910111213141516171819");
      
      
	}*/
	 SECTION ("Testing equal method")
    {
      ReallyLongInt p=ReallyLongInt(75); //long long constructor
      ReallyLongInt p1=ReallyLongInt(-75);
      bool equal1=p.equal(p1);
		REQUIRE(equal1==false);
		
	ReallyLongInt p45=ReallyLongInt(750); //long long constructor
      ReallyLongInt p19=ReallyLongInt(7500);
      bool equal4519=p45.equal(p19);
		REQUIRE(equal4519==false);
		
	
	const string s2="7509"; //string constructor
	const string s3="7500";
	ReallyLongInt p2=ReallyLongInt(s2);
    ReallyLongInt p3=ReallyLongInt(s3);
    bool equal23=p2.equal(p3);
	REQUIRE(equal23==false);
	
	const string s4="7509"; //Copy Constructor
	ReallyLongInt p4=ReallyLongInt(s4);
    ReallyLongInt p5=ReallyLongInt(p4);
    bool equal45=p4.equal(p5);
	REQUIRE(equal45==true);
	
	 
	ReallyLongInt p6=ReallyLongInt(); //default constructor
    bool equal6=p6.equal(p6);
	REQUIRE(equal6==true);
      
    }
    
    SECTION ("Testing Greater method")
    {
      ReallyLongInt p=ReallyLongInt(75); //long long constructor
      ReallyLongInt p1=ReallyLongInt(-750);
      bool greater1=p.greater(p1);
		REQUIRE(greater1==true);
		
		ReallyLongInt p8=ReallyLongInt(-75); //long long constructor
      ReallyLongInt p9=ReallyLongInt(-79);
      bool greater89=p8.greater(p9);
		REQUIRE(greater89==true);
	
	const string s2="75090"; //string constructor
	const string s3="7500";
	ReallyLongInt p2=ReallyLongInt(s2);
    ReallyLongInt p3=ReallyLongInt(s3);
    bool greater23=p2.greater(p3);
	REQUIRE(greater23==true);
	
	const string s4="7509"; //Copy Constructor
	ReallyLongInt p4=ReallyLongInt(s4);
    ReallyLongInt p5=ReallyLongInt(p4);
    bool greater45=p4.greater(p5);
	REQUIRE(greater45==false);
	
	 
	ReallyLongInt p6=ReallyLongInt(); //default constructor
    bool greater6=p6.greater(p6);
	REQUIRE(greater6==false);
	
	ReallyLongInt p78=ReallyLongInt(-750); //long long constructor
      ReallyLongInt p79=ReallyLongInt(-75);
      bool greater7879=p78.greater(p79);
		REQUIRE(greater7879==false);
		
		ReallyLongInt p786=ReallyLongInt(-75); //long long constructor
      ReallyLongInt p796=ReallyLongInt(75);
      bool greater78796=p786.greater(p796);
		REQUIRE(greater78796==false);
		
		ReallyLongInt x=-51;
		ReallyLongInt y=-51;
		bool greaterXY=x.greater(y);
		bool greaterYX=y.greater(x);
		REQUIRE(greaterXY==false);
		REQUIRE(greaterYX==false);
    }
    SECTION ("Testing add method")
    {
      ReallyLongInt p=ReallyLongInt(75); //long long constructor
      ReallyLongInt p1=ReallyLongInt(-75);
      ReallyLongInt add1=p.add(p1);
      string sadd1=add1.toString();
		REQUIRE(sadd1=="0");
		
	ReallyLongInt p0=ReallyLongInt(-75); //long long constructor
      ReallyLongInt p10=ReallyLongInt(75);
      ReallyLongInt add10=p0.add(p10);
      string sadd10=add10.toString();
		REQUIRE(sadd10=="0");
		
	ReallyLongInt p8=ReallyLongInt(-79); //long long constructor
      ReallyLongInt p9=ReallyLongInt(-75);
      ReallyLongInt add89=p8.add(p9);
      string sadd89=add89.toString();
		REQUIRE(sadd89=="-154");
	
	const string s2="7509"; //string constructor
	const string s3="75009";
	ReallyLongInt p2=ReallyLongInt(s2);
    ReallyLongInt p3=ReallyLongInt(s3);
    ReallyLongInt add23=p2.add(p3);
      string sadd23=add23.toString();
		REQUIRE(sadd23=="82518");
	
	const string s4="7509"; //Copy Constructor
	ReallyLongInt p4=ReallyLongInt(s4);
    ReallyLongInt p5=ReallyLongInt(p4);
    ReallyLongInt add45=p4.add(p5);
      string sadd45=add45.toString();
		REQUIRE(sadd45=="15018");
	 
	ReallyLongInt p6=ReallyLongInt(); //default constructor
    ReallyLongInt add6=p6.add(p6);
      string sadd6=add6.toString();
		REQUIRE(sadd6=="0");
      
    }
    SECTION ("Testing subtract method")
    {
      ReallyLongInt p=ReallyLongInt(75); //long long constructor
      ReallyLongInt p1=ReallyLongInt(-75);
      ReallyLongInt sub1=p.sub(p1);
      string ssub1=sub1.toString();
		REQUIRE(ssub1=="150");
		
		ReallyLongInt p0=ReallyLongInt(-75); //long long constructor
      ReallyLongInt p10=ReallyLongInt(75);
      ReallyLongInt sub10=p0.sub(p10);
      string ssub10=sub10.toString();
		REQUIRE(ssub10=="-150");
		
	ReallyLongInt p8=ReallyLongInt(-79); //long long constructor
      ReallyLongInt p9=ReallyLongInt(-75);
      ReallyLongInt sub89=p8.sub(p9);
      string ssub89=sub89.toString();
		REQUIRE(ssub89=="-4");
		
		ReallyLongInt p89=ReallyLongInt(-79); //long long constructor
      ReallyLongInt p99=ReallyLongInt(5);
      ReallyLongInt sub8999=p89.sub(p99);
      string ssub8999=sub8999.toString();
		REQUIRE(ssub8999=="-84");
	
	const string s2="750"; //string constructor
	const string s3="7500";
	ReallyLongInt p2=ReallyLongInt(s2);
    ReallyLongInt p3=ReallyLongInt(s3);
    ReallyLongInt sub23=p2.sub(p3);
    string ssub23=sub23.toString();
		REQUIRE(ssub23=="-6750");
	
	const string s4="7509"; //Copy Constructor
	ReallyLongInt p4=ReallyLongInt(s4);
    ReallyLongInt p5=ReallyLongInt(p4);
    ReallyLongInt sub45=p4.sub(p5);
      string ssub45=sub45.toString();
		REQUIRE(ssub45=="0");
	 
	ReallyLongInt p6=ReallyLongInt(); //default constructor
    ReallyLongInt sub6=p6.sub(p6);
      string ssub6=sub6.toString();
		REQUIRE(ssub6=="0");
      
    }
     SECTION ("Testing output stream operator")
    {
		ReallyLongInt p=ReallyLongInt(75);
		string q=p.toString();
		string k=p.toString();
		ostream& write=operator<<(cout," worked");
		ostream& rewrite=operator<<(write," again");
		cout<<"\n";
		ostream& writeRLN=operator<<(cout,q);
		cout<<"\n";
		ReallyLongInt p1=ReallyLongInt(789);
		cout<<p1 <<" "<<p;
		      
    }
    SECTION ("Testing assignment operator")
    {
		ReallyLongInt x(10);
		string q=x.toString();
		REQUIRE(q=="10");
		
		
		ReallyLongInt y;
		y=x;
		string q1=y.toString();
		REQUIRE(q1=="10");
		
		y=-58;
		q1=y.toString();
		REQUIRE(q1=="-58");
		
		ReallyLongInt z("10");
		string q2=z.toString();
		REQUIRE(q2=="10");
		
		
		y=string("123456789");
		q1=y.toString();
		REQUIRE(q1=="123456789");
		x=x;
		string q5=x.toString();
		REQUIRE(q5=="10");
		      
    }
    SECTION ("Testing == operator")
    {
		ReallyLongInt x(10);
		ReallyLongInt y;
		y=x;
		bool eq= (x==y);
		REQUIRE(eq==true);
		y=-58;
		bool eq1= (x==y);
		REQUIRE(eq1==false);
		ReallyLongInt z("10");
		bool eq2= (x==z);
		REQUIRE(eq2==true);
		y=string("123456789");
		bool eq3= (x==y);
		REQUIRE(eq3==false);
		bool eq4= (z==y);
		REQUIRE(eq4==false);
		      
    }
    SECTION ("Testing != operator")
    {
		ReallyLongInt x(10);
		ReallyLongInt y;
		y=x;
		bool eq= (x!=y);
		REQUIRE(eq==false);
		y=-58;
		bool eq1= (x!=y);
		REQUIRE(eq1==true);
		ReallyLongInt z("10");
		bool eq2= (x!=z);
		REQUIRE(eq2==false);
		y=string("123456789");
		bool eq3= (x!=y);
		REQUIRE(eq3==true);
		bool eq4= (z!=y);
		REQUIRE(eq4==true);
		      
    }
      SECTION ("Testing > operator")
    {
		ReallyLongInt x(10);
		ReallyLongInt y;
		y=x;
		bool gr= (x>y);
		REQUIRE(gr==false);
		bool gri= (y>x);
		REQUIRE(gri==false);
		y=-58;
		bool eq1= (x>y);
		REQUIRE(eq1==true);
		bool eq1i= (y>x);
		REQUIRE(eq1i==false);
		
		ReallyLongInt z("10");
		bool eq2= (x>z);
		REQUIRE(eq2==false);
		bool eq2i= (z>x);
		REQUIRE(eq2i==false);
		
		y=string("123456789");
		bool eq3= (x>y);
		REQUIRE(eq3==false);
		bool eq4= (z>y);
		REQUIRE(eq4==false);
		
		bool eq3i= (y>x);
		REQUIRE(eq3i==true);
		bool eq4i= (y>z);
		REQUIRE(eq4i==true);
		bool eq5= (y>y);
		REQUIRE(eq5==false);
		bool eq6= (z>z);
		REQUIRE(eq6==false);
		bool eq7= (x>x);
		REQUIRE(eq7==false);
		      
    }
    SECTION ("Testing < operator")
    {
		ReallyLongInt x(10);
		ReallyLongInt y;
		y=x;
		bool gr= (x<y);
		REQUIRE(gr==false);
		bool gri= (y<x);
		REQUIRE(gri==false);
		y=-58;
		bool eq1= (x<y);
		REQUIRE(eq1==false);
		bool eq1i= (y<x);
		REQUIRE(eq1i==true);
		
		ReallyLongInt z("10");
		bool eq2= (x<z);
		REQUIRE(eq2==false);
		bool eq2i= (z<x);
		REQUIRE(eq2i==false);
		
		y=string("123456789");
		bool eq3= (x<y);
		REQUIRE(eq3==true);
		bool eq4= (z<y);
		REQUIRE(eq4==true);
		
		bool eq3i= (y<x);
		REQUIRE(eq3i==false);
		bool eq4i= (y<z);
		REQUIRE(eq4i==false);
		bool eq5= (y<y);
		REQUIRE(eq5==false);
		bool eq6= (z<z);
		REQUIRE(eq6==false);
		bool eq7= (x<x);
		REQUIRE(eq7==false);
		      
    }
    SECTION ("Testing >= operator")
    {
		ReallyLongInt x(10);
		ReallyLongInt y;
		y=x;
		bool gr= (x>=y);
		REQUIRE(gr==true);
		bool gri= (y>=x);
		REQUIRE(gri==true);
		y=-58;
		bool eq1= (x>=y);
		REQUIRE(eq1==true);
		bool eq1i= (y>=x);
		REQUIRE(eq1i==false);
		
		ReallyLongInt z("10");
		bool eq2= (x>=z);
		REQUIRE(eq2==true);
		bool eq2i= (z>=x);
		REQUIRE(eq2i==true);
		
		y=string("123456789");
		bool eq3= (x>=y);
		REQUIRE(eq3==false);
		bool eq4= (z>=y);
		REQUIRE(eq4==false);
		
		bool eq3i= (y>=x);
		REQUIRE(eq3i==true);
		bool eq4i= (y>=z);
		REQUIRE(eq4i==true);
		
		bool eq5= (y>=y);
		REQUIRE(eq5==true);
		bool eq6= (z>=z);
		REQUIRE(eq6==true);
		bool eq7= (x>=x);
		REQUIRE(eq7==true);
		      
    }
     SECTION ("Testing <= operator")
    {
		ReallyLongInt x(10);
		ReallyLongInt y;
		y=x;
		bool gr= (x<=y);
		REQUIRE(gr==true);
		bool gri= (y<=x);
		REQUIRE(gri==true);
		y=-58;
		bool eq1= (x<=y);
		REQUIRE(eq1==false);
		bool eq1i= (y<=x);
		REQUIRE(eq1i==true);
		
		ReallyLongInt z("10");
		bool eq2= (x<=z);
		REQUIRE(eq2==true);
		bool eq2i= (z<=x);
		REQUIRE(eq2i==true);
		
		y=string("123456789");
		bool eq3= (x<=y);
		REQUIRE(eq3==true);
		bool eq4= (z<=y);
		REQUIRE(eq4==true);
		
		bool eq3i= (y<=x);
		REQUIRE(eq3i==false);
		bool eq4i= (y<=z);
		REQUIRE(eq4i==false);
		bool eq5= (y<=y);
		REQUIRE(eq5==true);
		bool eq6= (z<=z);
		REQUIRE(eq6==true);
		bool eq7= (x<=x);
		REQUIRE(eq7==true);
		      
    }
    SECTION("Testing Negation operator")
    {
		ReallyLongInt x(10);
		ReallyLongInt nx=-x;
		string q=nx.toString();
		REQUIRE(q=="-10");
		
		ReallyLongInt y;
		y=-58;
		string q5=y.toString();
		REQUIRE(q5=="-58");
		ReallyLongInt ny;
		ny=-y;
		string q78=ny.toString();
		REQUIRE(q78=="58");
		y=string("123456789");
		y=-y;
		string q1=y.toString();
		REQUIRE(q1=="-123456789");
		x=-x;
		string q6=x.toString();
		REQUIRE(q6=="-10");
		}
		
		 SECTION("Testing Add operator")
    {
		ReallyLongInt x(10);
		ReallyLongInt px=x+x;
		string q=px.toString();
		REQUIRE(q=="20");
		
		ReallyLongInt y;
		y=-58;
		ReallyLongInt py;
		py=x+y;
		string q78=py.toString();
		REQUIRE(q78=="-48");
		y=string("123456789");
		y=y+x;
		string q1=y.toString();
		REQUIRE(q1=="123456799");
		x=-x+x;
		string q6=x.toString();
		REQUIRE(q6=="0");
		}
		SECTION("Testing SUbtract operator")
    {
		ReallyLongInt x(10000);
		ReallyLongInt px=x-x;
		string q=px.toString();
		REQUIRE(q=="0");
		
		ReallyLongInt y;
		y=-58;
		ReallyLongInt py;
		py=x-y;
		string q78=py.toString();
		REQUIRE(q78=="10058");
		
		py=y-x;
		q78=py.toString();
		REQUIRE(q78=="-10058");
		
		y=string("123456789");
		y=y-x;
		string q1=y.toString();
		REQUIRE(q1=="123446789");
		x=-x-x;
		string q6=x.toString();
		REQUIRE(q6=="-20000");
		
		x=10090;
		y=1099;
		y=x-y;
		q6=y.toString();
		REQUIRE(q6=="8991");
		
		x=9876543;
		y=1987654;
		y=x-y;
		q6=y.toString();
		REQUIRE(q6=="7888889");
		
		}
		SECTION("Testing add equal operator")
    {
		ReallyLongInt x(10);
		x+=x;
		string q=x.toString();
		REQUIRE(q=="20");
		
		ReallyLongInt y;
		y=-58;
		y+=x;
		q=y.toString();
		REQUIRE(q=="-38");
		}
		SECTION("Testing subt equal operator")
    {
		ReallyLongInt x(10);
		x-=x;
		string q=x.toString();
		REQUIRE(q=="0");
		
		ReallyLongInt y;
		y=-58;
		y-=x;
		q=y.toString();
		REQUIRE(q=="-58");
		}
		SECTION("Testing increment operator")
    {
		ReallyLongInt x(10);
		++x;
		string q=x.toString();
		REQUIRE(q=="11");
		}
		SECTION("Testing decrement operator")
    {
		ReallyLongInt x(10);
		--x;
		string q=x.toString();
		REQUIRE(q=="9");
		}
		SECTION("Testing increment post operator")
    {
		ReallyLongInt x(10);
		ReallyLongInt px=x++;
		string q=x.toString();
		REQUIRE(q=="11");
		string pq=px.toString();
		REQUIRE(pq=="10");
		
		}
		SECTION("Testing decrement post operator")
    {
		ReallyLongInt x(11);
		ReallyLongInt px=x--;
		string q=x.toString();
		REQUIRE(q=="10");
		string pq=px.toString();
		REQUIRE(pq=="11");
		
		}
	SECTION("Testing absMult method")
    {
		ReallyLongInt x(5600);
		ReallyLongInt y(-34);
		ReallyLongInt q=x.mult(y);
		string sq=q.toString();
		REQUIRE(sq=="-190400");
		
		y=0;
		ReallyLongInt q1=x.mult(y);
		sq=q1.toString();
		REQUIRE(sq=="0");
		
		x=-79;
		y=5;
		ReallyLongInt q2=x.mult(y);
		sq=q2.toString();
		REQUIRE(sq=="-395");
		
		x=-700;
		y=-1;
		ReallyLongInt q3=x.mult(y);
		sq=q3.toString();
		REQUIRE(sq=="700");
		
		x=709;
		y=1;
		ReallyLongInt q4=x.mult(y);
		sq=q4.toString();
		REQUIRE(sq=="709");
		
		x=-39;
		y=39;
		q4=x.mult(y);
		sq=q4.toString();
		REQUIRE(sq=="-1521");
		
		
		
		}
		SECTION("Testing multiply function")
    {
		ReallyLongInt x(5600);
		ReallyLongInt y(-34);
		ReallyLongInt q=x*y;
		string sq=q.toString();
		REQUIRE(sq=="-190400");
		
		y=0;
		ReallyLongInt q1=x*y;
		sq=q1.toString();
		REQUIRE(sq=="0");
		
		x=-7900000;
		y=5;
		ReallyLongInt q2=x*y;
		sq=q2.toString();
		REQUIRE(sq=="-39500000");
		
		x=-700;
		y=-1;
		ReallyLongInt q3=x*y;
		sq=q3.toString();
		REQUIRE(sq=="700");
		
		x=709;
		y=1;
		ReallyLongInt q4=x*y;
		sq=q4.toString();
		REQUIRE(sq=="709");
		
		}
		SECTION("Testing multiply equal method")
    {
		ReallyLongInt x(100);
		x*=x;
		string q=x.toString();
		REQUIRE(q=="10000");
		
		ReallyLongInt y;
		y=-5800;
		y*=x;
		q=y.toString();
		REQUIRE(q=="-58000000");
		}
		
		SECTION("Testing dividing method")
    {
		ReallyLongInt x(10);
		ReallyLongInt r;
		ReallyLongInt q;
		x.div(x,q,r);
		
		string s=q.toString();
		REQUIRE(s=="1");
		
		s=r.toString();
		REQUIRE(s=="0");
		
		ReallyLongInt z(500);
		ReallyLongInt r1;
		ReallyLongInt q1;
		x=x-5;
		z.div(x,q1,r1);
		
		string s1=q1.toString();
		REQUIRE(s1=="100");
		
		s1=r1.toString();
		REQUIRE(s1=="0");
		
		ReallyLongInt h(-500);
		ReallyLongInt i(12);
		ReallyLongInt rhi;
		ReallyLongInt qhi;
		h.div(i,qhi,rhi);
		string shi=qhi.toString();
		REQUIRE(shi=="-41");
		shi=rhi.toString();
		REQUIRE(shi=="-8");
		
		i=-12;
		h.div(i,qhi,rhi);
		shi=qhi.toString();
		REQUIRE(shi=="41");
		shi=rhi.toString();
		REQUIRE(shi=="-8");
		
		h=500;
		h.div(i,qhi,rhi);
		shi=qhi.toString();
		REQUIRE(shi=="-41");
		shi=rhi.toString();
		REQUIRE(shi=="8");
		
		h=10;
		i=-5;
		h.div(i,qhi,rhi);
		shi=qhi.toString();
		REQUIRE(shi=="-2");
		shi=rhi.toString();
		REQUIRE(shi=="0");
		
		
		}
		SECTION("Testing divide operaotr")
    {
		ReallyLongInt x(10);
		ReallyLongInt div= x/x;
		string s=div.toString();
		REQUIRE(s=="1");
		
		ReallyLongInt z(500);
		x=x-5;
		div=z/x;
		s=div.toString();
		REQUIRE(s=="100");
		
		ReallyLongInt h(-500);
		ReallyLongInt i(12);
		div=h/i;
		
		s=div.toString();
		REQUIRE(s=="-41");
		
		i=-12;
		div=h/i;
		
		s=div.toString();
		REQUIRE(s=="41");
		
		h=500;
		div=h/i;
		
		s=div.toString();
		REQUIRE(s=="-41");
		
		
		}
		SECTION("Testing modulus operaotr")
    {
		ReallyLongInt x(10);
		ReallyLongInt div= x%x;
		string s=div.toString();
		REQUIRE(s=="0");
		
		ReallyLongInt z(500);
		x=x-5;
		div=z%x;
		s=div.toString();
		REQUIRE(s=="0");
		
		ReallyLongInt h(-500);
		ReallyLongInt i(12);
		div=h%i;
		
		s=div.toString();
		REQUIRE(s=="-8");
		
		i=-12;
		div=h%i;
		
		s=div.toString();
		REQUIRE(s=="-8");
		
		h=500;
		div=h%i;
		
		s=div.toString();
		REQUIRE(s=="8");
		
		 h=10090;
		i=1099;
		div=h%i;
		 s=div.toString();
		REQUIRE(s=="199");
		i=h-(i*(h/x));
		s=i.toString();
		REQUIRE(s=="-2207692"); 
		
		
		}
		SECTION("Testing divide assign operaotr")
    {
		ReallyLongInt x(10);
		ReallyLongInt div= x/=x;
		string s=x.toString();
		REQUIRE(s=="1");
		
		ReallyLongInt z(500);
		x=-4;
		z/=x;
		s=z.toString();
		REQUIRE(s=="-125");
		
		ReallyLongInt h(-500);
		ReallyLongInt i(12);
		h/=i;
		
		s=h.toString();
		REQUIRE(s=="-41");
	
		
		}
		SECTION("Testing modulus assign operaotr")
    {
		ReallyLongInt x(10);
		ReallyLongInt div= x%=x;
		string s=x.toString();
		REQUIRE(s=="0");
		
		ReallyLongInt z(500);
		x=-4;
		z%=x;
		s=z.toString();
		REQUIRE(s=="0");
		
		ReallyLongInt h(-500);
		ReallyLongInt i(12);
		h%=i;
		
		s=h.toString();
		REQUIRE(s=="-8");
		
		
		}
		SECTION("Testing toLongLong operaotr")
    {
		ReallyLongInt x(89789);
		long long l=x.toLongLong();
		REQUIRE(l==89789);
		
		x=8;
		l=x.toLongLong();
		REQUIRE(l==8);
		
		x=0;
		l=x.toLongLong();
		REQUIRE(l==0);
		
		x=-89;
		l=x.toLongLong();
		REQUIRE(l==-89);
		
		x=8999999;
		l=x.toLongLong();
		REQUIRE(l==8999999);
		
		x=string("9223372036854775808");
		l=x.toLongLong();
		REQUIRE(l==0);
		
		x=string("9223372036854775810");
		l=x.toLongLong();
		REQUIRE(l==2);
		
		x=string("92233720368547758");
		l=x.toLongLong();
		REQUIRE(l==92233720368547758);
		
		}
		
		
    
  
	
}
