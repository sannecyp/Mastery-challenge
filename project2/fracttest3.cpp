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
		int convert(char[],int,int);
		void reduce(int,int);
		void operation(rational,rational,char); 
		friend std::ostream& operator <<(std::ostream& output_stream, const rational& r);
		const rational operator +(const rational & fract2);  
		const rational operator -(const rational & fract2);
		const rational operator /(const rational & fract2);
		const rational operator *(const rational & fract2);




};


std::ostream& operator <<(std::ostream& output_stream, const rational& r)
{
	std::cout<<r.num<<"/"<<r.denom<<std::endl;
	return output_stream;
}

rational::rational(int n,int d)
{
	num=n;
	denom=d;

}

int rational::convert(char char1[],int i,int j)
{
	char a[j-i];
	int number;
	for(int k=0;k<(j-i);k++)
		a[k]=char1[i+k];
	number=atoi(a);
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
const rational::operator+(const rational& fract2)
{
	rational sum;
        sum.num=(fract1.num*fract2.denom+fract2.num*fract1.denom);
        sum.denom=fract1.denom*fract2.denom;
        sum.reduce(sum.num,sum.denom)
        return sum;

}
const rational::operator-(const rational &fract2)
{
	rational difference;
        difference.num=(fract1.num*fract2.denom-fract2.num*fract1.denom);
        difference.denom=fract1.denom*fract2.denom;
        difference.reduce(difference.num,difference.denom);
        return difference;

}

const rational::operator/(const rational &fract2)
{
	rational division;
        division.num=fract1.num*fract2.denom;
        division.denom=fract1.denom*fract2.num;
        division.reduce(division.num,division.denom);
        return division;


}

const rational::operator*(const rational &fract2)
{
	rational product;
	product.num=fract1.num*fract2.num;
	product.denom=fract1.denom*fract2.denom;
	product.reduce(product.num,product.denom);
	return product;
}

 

int main()
{

	int n1,d1,n2,d2,start=0,end=0;
        string fract;
        char char1[fract.len()+1],operate;

        cin>>fract;
        for(int i=0;i<=fract.lenght();i++)
                char1[i]=fract.at(i);
        for(int i=0;char1[i] != '/';i++,end++)
                n1=convert(char1,start,end);
        start=end+1;
        for(int i=0;char1[i] != ' ';i++,end++)
                d1=convert(char1,start,end);
        operate=end+1;
        start=(end=end+3);
        for(int i=0;char1[i] != '/';i++,end++)
                n2=convert(char1,start,end);
        start=n+1;
        for(int i=0;char1[i] != '\0';i++,end++)
                d2=convert(char1,start,end);

        rational fract1(n1,d1),fract2(n2,d2);
	fract1.reduce(n1,d1);
	fract2.reduce(n2,d2);
	fract1.operation(fract1,fract2, operate);

	return 0;
}	
