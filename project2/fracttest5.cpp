#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
void getrationals();
class rational
{
	public:
		int denom,num;
		rational (int,int);
		void reduce(int,int);
		void operation(rational,rational,char); 
		friend ostream& operator<<(ostream& out, rational r);
		rational operator +(const rational & fract2);  
		rational operator -(const rational & fract2);
		rational operator /(const rational & fract2);
		rational operator *(const rational & fract2);




};

int convert(char[],int,int);

ostream& operator <<(ostream& out, rational r)
{
	out<<r.num<<"/"<<r.denom<<endl;
	return out;
}

rational::rational(int n,int d)
{
	num=num;
	cout<<n;
	denom=d;
	cout<<denom;

}

int convert(char char1[],int i,int j)
{
	char a[j-i];
	int number;
	for(int k=0;k<(j-i);k++)
		a[k]=char1[i+k];
	number=atoi(a);
	cout<<number;
	return number;
}

void rational::reduce(int n,int d)
{
	for(int i=n;i != 0;)
	{
		if(n%i==0 && d==0)
		{
			num=(n)/i;
			denom=(d)/i;
		}
		if(n<0)
			i++;
		else
			i--;
	}

        

}

void rational::operation(rational fract1,rational fract2,char operate)
{
	 if(operate=='+')
                cout<<(fract1+fract2);
        else if(operate=='-')
                cout<<(fract1-fract2);
        else if(operate=='/')
                cout<<(fract1/fract2);
        else if(operate=='*')
                cout<<(fract1*fract2);


}
rational rational::operator+(const rational& fract2)
{
	int n,d;
        n=(num*fract2.denom+fract2.num*denom);
        d=denom*fract2.denom;
	rational sum(n,d);
        sum.reduce(sum.num,sum.denom);
        return sum;

}
rational rational::operator-(const rational &fract2)
{
        int n,d;
	n=(num*fract2.denom-fract2.num*denom);
        d=denom*fract2.denom;
	rational difference(n,d);
        difference.reduce(difference.num,difference.denom);
        return difference;

}

rational rational::operator/(const rational &fract2)
{
        int n,d;
	n=num*fract2.denom;
        d=denom*fract2.num;
	rational division(n,d);
        division.reduce(division.num,division.denom);
        return division;


}

rational rational::operator*(const rational &fract2)
{
	int n,d;
	n=num*fract2.num;
	d=denom*fract2.denom;
	rational product(n,d);
	product.reduce(product.num,product.denom);
	return product;
}

 

int main()
{

	int n1,d1,n2,d2,start=0,end=0;
        string fract;
	cin>>fract;
        char char1[fract.length()+1],operate;

        for(int i=0;i<fract.length();i++)
                char1[i]=fract.at(i);
        for(int i=0;char1[i] != '/';i++,end++)
                n1=convert(char1,--start,end);
	cout<<n1;
        start=end+2;
        for(int i=0;char1[i] != ' ';i++,end++)
                d1=convert(char1,start,end);
        operate=end+1;
        start=(end=end+3);
        for(int i=0;char1[i] != '/';i++,end++)
                n2=convert(char1,start,end);
        start=end+1;
        for(int i=0;char1[i] != '\0';i++,end++)
                d2=convert(char1,start,end);

        rational fract1(n1,d1),fract2(n2,d2);
	fract1.reduce(n1,d1);
	fract2.reduce(n2,d2);
	fract1.operation(fract1,fract2, operate);

	return 0;
}	
