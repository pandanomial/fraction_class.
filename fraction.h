/*
 
///////////////////////////////////////////////////////////////////////////////
////file name: fraction.h												   ////
///////////////////////////////////////////////////////////////////////////////

 
Fraction class. It correctly handle Fractions
that are negative, improper (larger numerator than denominator), or whole numbers
(denominator of 1). This class Fractions prints a Fraction to a stream with an overloaded insertion (<<) operator. The Fraction is printed in reduced form (not 3/6 but 1/2). Whole
numbers is printed without a denominator (e.g. not 3/1 but just 3). Improper
Fractions is be printed as a mixed number with a + sign between the two parts
(2+1/2). Negative Fractions should be printed with a leading minus sign.

This Fraction class will read a Fraction from a stream using an overloaded 
extraction (>>) operator. It can read any of the formats described above (mixed
number, negative, whole numbers). Assume that there are no spaces or formatting
errors in the Fractions that it reads. 

All six of the relational operators (<, <=, >, >=, ==, !=) are supported. They
are able to compare Fractions to other Fractions as well as Fractions to integers.
Either Fractions or integers can appear on either side of the binary comparison
operator. 

The four basic arithmetic operations (+, -, *, /) are supported. They allow
Fractions to be combined with other Fractions, as well as with integers. Either
Fractions or integers can appear on either side of the binary operator. Note :
no special handling in the case of dividing by a Fraction that is equal to 0. If
the client attempts to do this, they will get a runtime error (same behavior they
would expect if they tried to divide by an int or double that was equal to 0).

The shorthand arithmetic assignment operators (+=, -=, *=, /=) are implemented.
Fractions can appear on the left-hand side, and Fractions or integers on the 
right-hand side. 

The increment and decrement (++, --) operators are supported in both prefix and
postfix form for Fractions. To increment or decrement a Fraction means to add
or subtract (respectively) one (1).


///////////////////below are Class declarations documention////////////////////
public:

Fraction(int newNumerator = 0, int newDenominator = 1);
//PRE:this constructor can take zero, one or two parameters. no values assigned
//POST:sets both private members with values, Default values are set  



friend std::ostream& operator<<(std::ostream& out, const Fraction& right);
//POST: Prints a Fraction to a stream with an overloaded insertion(<<) operator.



friend std::istream& operator>>(std::istream& in, Fraction& right);
//POST: Reads a Fraction from a stream using an overloaded extraction (>>)
//operator. Reads any of the formats (mixed number, negative, whole numbers).



friend Fraction operator+(const Fraction& left, const Fraction& right);
//basic arithmetic operation (+) operator overload. all math logic apply.
//POST: adds Fractions to other Fractions as well as Fractions to integers.
//Either Fractions or integers can appear on either side of the + operator.  
//returns Fraction object after addition



friend Fraction operator-(const Fraction& left, const Fraction& right);
//basic arithmetic operation (-) operator overload. all math logic apply.
//POST: subtracts Fractions with other Fractions also Fractions with integers.
//Either Fractions or integers can appear on either side of the - operator. 
//returns Fraction object after subtraction



friend Fraction operator*(const Fraction& left, const Fraction& right);
//basic arithmetic operation (*) operator overload. all math logic apply.
//POST: multiplies Fractions with other Fractions as well as Fractions with
//integers. Either Fractions or integers can appear on either side of the *
//operator. returns Fraction object after multiplication 



friend Fraction operator/(const Fraction& left, const Fraction& right);
//basic arithmetic operation (/) operator overload. all math logic apply.
//POST: divides Fractions by other Fractions as well as Fractions with integers.
//Either Fractions or integers can appear on either side of the / operator. 
//returns Fraction object after dividion 



Fraction operator+=(const Fraction& right);
//The shorthand arithmetic assignment operator(+=). Fractions can appear on
//the lefthand side, and Fractions or integers on the righthand side.
//POST: adds Fractions to other Fractions as well as Fractions to integers. 
//Either Fractions or integers can appear on either side of the += operator.
//returns Fraction object after addition



Fraction operator-=(const Fraction& right);
//The shorthand arithmetic assignment operator(-=). Fractions can appear on
//the lefthand side, and Fractions or integers on the righthand side.
//POST: subtracts Fractions with other Fractions also Fractions with integers. 
//Either Fractions or integers can appear on either side of the -= operator. 
//returns Fraction object after subtraction



Fraction operator*=(const Fraction& right);
//The shorthand arithmetic assignment operator(*=) Fractions can appear on
//the lefthand side, and Fractions or integers on the righthand side.
//POST: multiplies Fractions with other Fractions as well as Fractions with 
//integers. Either Fractions or integers can appear on either side of the *= 
//operator. returns Fraction object after multiplication 



Fraction operator/=(const Fraction& right);
//The shorthand arithmetic assignment operator(/=) Fractions can appear on
//the lefthand side, and Fractions or integers on the righthand side.
//POST: divides Fractions by other Fractions as well as Fractions with integers.
//Either Fractions or integers can appear on either side of the /= operator. 
//returns Fraction object after division 



Fraction operator++();//pre
//POST: The increment(++) operator,  prefix form for Fraction. To increment
//a Fraction means to add one(1). returns Fraction object after it adds 1



Fraction operator++(int);
//POST: The increment (++) operator, postfix form for Fraction. To increment
//a Fraction means to add one(1). returns Fraction object then it adds 1



Fraction operator--();
//POST: The decrement(--) prefix form for Fractions. To decrement a Fraction
//means to subtract one(1).  returns Fraction object after it subtracts 1



Fraction operator--(int);
//POST: The decrement(--) postfix form for Fractions. To decrement a Fraction
//means to subtract one(1). returns Fraction object then it subtracts 1



friend bool operator>(const Fraction& left, const Fraction& right);
//relational operator (>),  operator overload. All math logic apply.
//POST: compare Fractions to other Fractions as well as Fractions to integers.
//Either Fractions or integers can appear on either side of the binary comparison
//operator. returns true if left Fraction object (or an integer) is greater than
//right Fraction object (or an integer)



friend bool operator>=(const Fraction& left, const Fraction& right);
//POST: compare left Fraction object(or an integer)  with right Fraction(or an 
//integer), returns true if left Fraction object(or an integer)  is greater than
//or equal to right Fraction object (or an integer) 



friend bool operator<(const Fraction& left, const Fraction& right);
//POST: compare left Fraction object (or an integer) with right Fraction (or an
//integer), returns true if left Fraction object (or an integer) is smaller than
//right Fraction object (or an integer)



friend bool operator<=(const Fraction& left, const Fraction& right);
//POST: compare left Fraction object (or an integer) with right Fraction(or an
//integer) , returns true if left Fraction object(or an integer)  is smaller than
//or equal to right Fraction object(or an integer)



friend bool operator==(const Fraction& left, const Fraction& right);
//POST: compare left Fraction object(or an integer) with right Fraction (or an
//integer), returns true if they are equal



friend bool operator!=(const Fraction& left, const Fraction& right);
//POST: compare left Fraction object(or an integer)  with right Fraction(or an
//integer), returns true if they are NOT equal
*/


#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
//using namespace std;//for ostream, won't work without it. But don't put here

namespace cs_fraction
{
	class Fraction
	{
	public:
		Fraction(int newNumerator = 0, int newDenominator = 1);
		friend std::ostream& operator<<(std::ostream& out, const Fraction& right);
		friend std::istream& operator>>(std::istream& in, Fraction& right);
		friend Fraction operator+(const Fraction& left, const Fraction& right);
		friend Fraction operator-(const Fraction& left, const Fraction& right);
		friend Fraction operator*(const Fraction& left, const Fraction& right);
		friend Fraction operator/(const Fraction& left, const Fraction& right);
		Fraction operator+=(const Fraction& right);
		Fraction operator-=(const Fraction& right);
		Fraction operator*=(const Fraction& right);
		Fraction operator/=(const Fraction& right);
		Fraction operator++();
		Fraction operator++(int);
		Fraction operator--();
		Fraction operator--(int);
		friend bool operator>(const Fraction& left, const Fraction& right);
		friend bool operator>=(const Fraction& left, const Fraction& right);
		friend bool operator<(const Fraction& left, const Fraction& right);
		friend bool operator<=(const Fraction& left, const Fraction& right);
		friend bool operator==(const Fraction& left, const Fraction& right);
		friend bool operator!=(const Fraction& left, const Fraction& right);
		
	private:
		int numerator;
		int denominator;
		void simplify();
	};
}

#endif

