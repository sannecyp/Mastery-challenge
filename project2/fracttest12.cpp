/*********************************************************************
 ****** filename:fractions 
 ****** Author:Prathik Sannecy
 ****** Date:2/4
 ****** Description:Performs operations with fractions using a class
 ****** Input:The two fractions and the operations
 ****** Output:The operation on the two fractions
 ************************************************************************/



#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
class rational
{
	private:
		int denom;
		int num;
	public:
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

//This function ouputs the resulting fraction
ostream& operator <<(ostream& out, rational r)
{
	out<<r.num<<"/"<<r.denom<<endl;
	return out;
}

//Initializes the fraction's numerator and denominator bassed on the values passed 
rational::rational(int n,int d)
{
	num=n;
	denom=d;

}

/*This function takes the input string and returns a number (either a denominator or the numerator of one of the two fractions)  each time it is called.It takes the starting and ending parts of the fraction (i and j) and then makes a new string from the starting and ending points. Finally, it converts the string to an integer and returns it*/   
int convert(char char1[],int i,int j)
{
	char a[j-i+2];
	int number;
	for(int k=0;k<(j-i+1);k++)
		a[k]=char1[i+k];
	a[j-i+1]='\0';
	number=atoi(a);
	return number;
}

/*This function reduces the fraction object that calls it. First it decides whetehr the fraction is positive or negative. Then it makes both the numerator and denominator positive so it can put them in a for loop to see whether they have any factors in common (using the modulus operator). FInally, based on if the fraction is positive or not, it may or may not change the sign of the numerator*/
void rational::reduce(int n,int d)
{
	bool neg=true;
	if(d<0 && n<0) 
	{
		num=(-1*n);
		denom=(-1*d);
		neg=false;
	}	
	else if (d>0 && n<0)
		num=((-1)*n);
	else if(d<0 && n>0)
		denom=((-1)*d);
	else
		neg=false;
	for(int i=num;i != 0; i--)
	{
		if(num%i==0 && denom%i==0)
		{
			num=(num)/i;
			denom=(denom)/i;
		}
	}
	if(neg)
		num=((-1)*num);	
}

/*This function decides what function to use*/
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

/*Using the formula for adding a fraction, this overloaded + function returns the sum of the two fractions(another fraction)*/ 
rational rational::operator+(const rational& fract2)
{
	int n,d;
        n=(num*fract2.denom+fract2.num*denom);
        d=denom*fract2.denom;
	rational sum(n,d);
        sum.reduce(sum.num,sum.denom);
        return sum;

}

/*Same as the overloaded + function, except for subtracting*/
rational rational::operator-(const rational &fract2)
{
        int n,d;
	n=(num*fract2.denom-fract2.num*denom);
        d=denom*fract2.denom;
	rational difference(n,d);
        difference.reduce(difference.num,difference.denom);
        return difference;

}

/*Same as the overloaded + function, except for dividing*/
rational rational::operator/(const rational &fract2)
{
        int n,d;
	n=num*fract2.denom;
        d=denom*fract2.num;
	rational division(n,d);
        division.reduce(division.num,division.denom);
        return division;


}

/*Same as the overloaded + function, except for multiplying*/
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
	/*First main takes a string input and turns it into a character array*/ 
	getline(cin,fract);
        char char1[fract.length()],operate;
	
        for(int i=0;i<fract.length();i++)
                char1[i]=fract.at(i);
 
        /*Based on the formatting of the input (specified),it goes through the character array and identifies where each  each fraction is using identifyers such as / or a space or the null character, storing the starting point and the ending point of the denominators and numerators of the fractions*/   
   	for(int i=0;char1[i] != '/';i++,end++);

	/*Using the starting popint and ending point of each number of each fraction, it gives the convert function the char array and these values so that the convert function can create a new integre*/ 
        n1=convert(char1,start,--end);
        start=(end=end+2);
        for(int i=start;char1[i] != ' ';i++,end++);
        d1=convert(char1,start,--end);
        operate=char1[end+2];
        start=(end=(end+4));
        for(int i=start;char1[i] != '/';i++,end++);
        n2=convert(char1,start,--end);
        start=end+2;
        for(int i=start;char1[i] != '\0';i++,end++);
        d2=convert(char1,start,++end);

	/*Finally, it creates the fraction objects and proceeds with the program, going to the function to identify what the operator is*/
        rational fract1(n1,d1),fract2(n2,d2);
	fract1.reduce(n1,d1);
	fract2.reduce(n2,d2);
	fract1.operation(fract1,fract2, operate);

	return 0;
}	
