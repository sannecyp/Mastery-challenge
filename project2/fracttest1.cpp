#include <iostream>
#include <string>
#include <cstring>

void getrationals();
class rational
{
	public:
		int denom,num;
		void rational (int,int);
		int convert(char[],int,int);
		void reduce(rational,rational);	
		friend std::ostream& operator <<(std::ostream& output_stream, const rational& r);
		const rational operator +(const rational &r1,const point& r2);  
		const rational operator -(const rational &r1,const point& r2);
		const rational operator /(const rational &r1,const point& r2);
		const rational operator *(const rational &r1,const point& r2);



};


std::ostream& operator <<(std::ostream& output_stream, const rational& r)
{
	std::cout<<r.num<<"/"<<r.denom<<std::endl;
	return output_stream;
}

void rational::rational(int n,int d)
{
	num=n;
	denom=d;

}

int rational::convert(char char1[],i,j)
{
	char a[j-i];
	int number;
	for(int k=0;k<(j-i);k++)
		a[k]=char1[i+k];
	number=atoi(a);
	return number;
}

void rational::reduce(rational fract1,rational fract2)

}

int main()
{

	int n1,d1,n2,d2,start=0,end=0;
        string fract;
        char char1[fract.lenght()+1],operate;

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
	fract1.reduce(fract1,fract2);	
