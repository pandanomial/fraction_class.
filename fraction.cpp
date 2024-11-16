/*
 
///////////////////////////////////////////////////////////////////////////////
 
file name: fraction.cpp
///////////////////////////////////////////////////////////////////////////////
 
Fraction class. It handles Fractions that are
positive, negative, improper (larger numerator than denominator), or whole numbers
(denominator of 1). Use operator overload to print a Fraction to a stream with
an overloaded insertion (<<) operator, also an overloaded extraction (>>) operator.
and all six of the relational operators (<, <=, >, >=, ==, !=), four basic arithmetic
operations (+, -, *, /), shorthand arithmetic assignment operators (+=, -=, *=, /=)
and increment and decrement (++, --) operators are required overload operators. 


Class Invariant: a Fraction object has 2 private int data members and 1 private
				 functiom. And denominator can not be 0 ever.

private: int numerator;
//numerator of a fraction, can be any integer


private: int denominator;
//denominator of a fraction, never be 0


private: void simplify();
//this function does not take any parameters. POST:simplfies the fraction, makes
//both numerator and denominator as small as possible without changing the
//fraction's own value. This function can be called by public member functions
//or friend functions, but can not be be seen or called by client program

*/

#include <iostream>
#include <cassert>
#include "fraction.h"
using namespace std;


namespace cs_fraction
{
	//parameterized constructor (a constructor that takes parameters), takes two
	//parameters. PRE:There were no values assigned to private members numerator and 
	//denominator. This parameterized constructor checks to make sure that the second
	//parameter is not a 0 by using the statement "assert(denominatorParameter != 0);" 
	//POST: sets both private members with values(parameters' values), and simplify
	//the fraction by calling private function simplify(). Default values are set to 
	//avoid too many constructors
	Fraction::Fraction(int newNumerator, int newDenominator)
	{
		assert(newDenominator != 0);

		numerator = newNumerator;
		denominator = newDenominator;
		simplify(); //call private function
	}

	
	
	
	


	//overloaded insertion(<< ) operator. It prints out Feacrion in required format.
	//checks to make sure that the denominator is not a 0 by using the statement
	//"assert(denominatorParameter != 0);" Fraction is printed in reduced form 
	//(not 3 / 6 but 1 / 2). Whole numbers print without a denominator 
	//(e.g. not 3 / 1 but just 3).Improper Fractions are printed as a mixed number
	//with a + sign between the two parts(2 + 1 / 2). Negative Fractions are
	//printed with a leading minus sign. POST: Prints a Fraction to a stream.
	ostream& operator<<(ostream& out, const Fraction& r)
	{
		assert(r.denominator != 0);//handle input denominator is 0 problem

		if (r.numerator == 0)
		{
			out << "0";
		}
		else if (r.denominator == 1)
		{
			out << r.numerator;
		}
		else if ((r.numerator < 0) && (r.numerator * ( -1 ) < r.denominator))
		{
			out << r.numerator << "/" << r.denominator;
		}
		else if ((r.numerator < 0) && (r.numerator * ( -1 ) > r.denominator))
		{
			out << r.numerator / r.denominator << "+"
				<< (r.numerator % r.denominator) * ( -1 ) << "/" << r.denominator;
		}
		else if ((r.numerator > 0) && (r.numerator > r.denominator))
		{
			out << r.numerator / r.denominator << "+"
				<< r.numerator % r.denominator << "/" << r.denominator;
		}
		else if ((r.numerator > 0) && (r.numerator < r.denominator))
		{
			out << r.numerator << "/" << r.denominator;
		}
		else
		{
			out << "what's wrong?";
		}

		return out;
	}



	



	//overloaded extraction (>>) operator. reads a Fraction from a stream.
	//checks to make sure that the input denominator is not a 0 by using
	//"assert(denominatorParameter != 0);" The peek() function does not consume
	//the character from the input stream, it detects what the next character is. 
	//The '+' in mixed numbers is a separator (to separate the integer part from
	//the Fraction part of the number). Fraction "negative two and one-sixth"
	//would be written as - 2 + 1 / 6, even though - 2 plus 1 / 6 is not so. POST:
	//Reads a Fraction from a stream using an overloaded extraction (>>) operator.
	//sets both private members numerator denominatorwith with values, and simplify
	//the fraction by calling private function simplify().
	istream& operator>>(istream& in, Fraction& right)
	{
		assert(right.denominator != 0);//handle input denominator is 0 problem

		int firstNum;
		int secondNum;

		//no need for int, it is taken care of already
		//while (isspace(in.peek()))
		//{
		//	in.ignore();
		//}
		 
		in >> firstNum;

		if (firstNum == 0 )
		{
			right.denominator = 1;
			right.numerator = firstNum;
		}
		else if (in.peek() == '/') 
		{
			in.ignore(); //very important to ignore / sign
			in >> right.denominator;
			
			right.numerator = firstNum;
			right.simplify();
		}
		else if (in.peek() == '+') 
		{
			in.ignore(); //very important to ignore + sign
			in >> secondNum;
			
			in.ignore(); //very important to ignore / sign 
			in >> right.denominator;

			if (firstNum < 0)
			{
				right.numerator = firstNum * right.denominator - secondNum;
			}
			else
			{
				right.numerator = firstNum * right.denominator + secondNum;
			}

			right.simplify();
		}
		else 
		{
			right.numerator = firstNum;
			right.denominator = 1;
		}

		return in;
	}

	



	

	//basic arithmetic operation (+) operator overload. all math logic apply. 
	//This function adds Fractions to other Fractions as well as Fractions to 
	//integers. Either Fractions or integers can appear on either side of the +
	//operator. It simplifies the fraction after addition.POST:returns Fraction
	//object after addition and simplification
	Fraction operator+(const Fraction& l, const Fraction& r)
	{
		Fraction sum;

		sum.numerator = l.numerator * r.denominator + l.denominator * r.numerator;
		sum.denominator = l.denominator * r.denominator;
		sum.simplify(); //call private function

		return sum;
	}







	//basic arithmetic operation (-) operator overload. all math logic apply. 
	//This function subtracts Fractions with other Fractions also Fractions with 
	//integers. Either Fractions or integers can appear on either side of the -
	//operator. It simplifies the fraction after subtraction.  POST: returns
	//Fraction object after subtraction and simplification
	Fraction operator-(const Fraction& l, const Fraction& r)
	{
		Fraction diff;

		diff.numerator = l.numerator * r.denominator - l.denominator * r.numerator;
		diff.denominator = l.denominator * r.denominator;
		diff.simplify(); //call private function

		return diff;
	}







	//basic arithmetic operation (*) operator overload. all math logic apply. 
	//Not handling overflow. This function multiplies Fractions with other Fractions
	//as well as Fractions with integers. Either Fractions or integers can appear
	//on either side of the * operator. It simplifies the fraction after multiplication.  
	//POST: returns Fraction object after multiplication and simplification
	Fraction operator*(const Fraction& left, const Fraction& right)
	{
		Fraction product;

		product.numerator = left.numerator * right.numerator;
		product.denominator = left.denominator * right.denominator;
		product.simplify(); //call private function

		return product;
	}







	//basic arithmetic operation (/) operator overload. all math logic apply. 
	//Not handling overflow. This function divides Fractions by other Fractions
	//as well as Fractions with integers. Either Fractions or integers can appear
	//on either side of the / operator. It simplifies the fraction after dividion.  
	//POST: returns Fraction object after dividion and simplification
	Fraction operator/(const Fraction& left, const Fraction& right)
	{
		Fraction quotient;

		quotient.numerator = left.numerator * right.denominator;
		quotient.denominator = left.denominator * right.numerator;
		quotient.simplify(); //call private function

		return quotient;
	}







	//The shorthand arithmetic assignment operator(+=). Fractions can appear on
	//the lefthand side, and Fractions or integers on the right hand side. 
	//This function adds Fractions to other Fractions as well as Fractions to 
	//integers. Either Fractions or integers can appear on either side of the +=
	//operator. It simplifies the fraction after addition.  POST: returns Fraction
	//object after addition and simplification
	Fraction Fraction::operator+=(const Fraction& rt)
	{
		//*this = *this + right;
		//or
		numerator = numerator * rt.denominator + denominator * rt.numerator;
		denominator = denominator * rt.denominator;
		simplify(); //call private function
		return *this;
	}








	//The shorthand arithmetic assignment operator(-=). Fractions can appear on
	//the lefthand side, and Fractions or integers on the right hand side. 
	//This function subtracts Fractions with other Fractions also Fractions with 
	//integers. Either Fractions or integers can appear on either side of the -=
	//operator. It simplifies the fraction after subtraction.  POST: returns
	//Fraction object after subtraction and simplification
	Fraction Fraction::operator-=(const Fraction& rt)
	{
		//*this = *this - rt;
		//or
		numerator = numerator * rt.denominator - denominator * rt.numerator;
		denominator = denominator * rt.denominator;
		simplify(); //call private function
		return *this;
	}








	//The shorthand arithmetic assignment operator(*=) Fractions can appear on
	//the lefthand side, and Fractions or integers on the righthand side.
	//Not handling overflow. This function multiplies Fractions with other Fractions
	//as well as Fractions with integers. Either Fractions or integers can appear
	//on either side of the *= operator. It simplifies the fraction after multiplication.  
	//POST: returns Fraction object after multiplication and simplification
	Fraction Fraction::operator*=(const Fraction& right)
	{
		//*this = *this * right;
		//or
		numerator = numerator * right.numerator;
		denominator = denominator * right.denominator;
		simplify(); //call private function

		return *this;
	}







	//The shorthand arithmetic assignment operator(/=) Fractions can appear on
	//the lefthand side, and Fractions or integers on the righthand side.
	//Not handling overflow. This function divides Fractions by other Fractions
	//as well as Fractions with integers. Either Fractions or integers can appear
	//on either side of the /= operator. It simplifies the fraction after division.  
	//POST: returns Fraction object after division and simplification
	Fraction Fraction::operator/=(const Fraction& right)
	{
		//*this = *this / right;
		//or
		numerator = numerator * right.denominator;
		denominator = denominator * right.numerator;
		simplify(); //call private function

		return *this;
	}


 




	//The increment(++) operator, this is prefix form for Fraction. To increment
	//a Fraction means to add one(1). POST:returns Fraction object after it adds 1
	Fraction Fraction::operator++()//pre
	{
		numerator = numerator + denominator;
		simplify();

		return *this;
	}







	
	//The increment (++) operator, this is postfix form for Fraction. To increment
	//a Fraction means to add one(1). POST:returns Fraction object then it adds 1
	Fraction Fraction::operator++(int)//post
	{
		Fraction temp(numerator, denominator);
		numerator = numerator + denominator;
		simplify();

		return temp;
	}








	//The decrement(--) This is prefix form for Fractions. To decrement a Fraction
	//means to subtract one(1). POST: returns Fraction object after it subtracts 1
	Fraction Fraction::operator--()//pre
	{
		numerator = numerator - denominator;
		simplify();

		return *this;
	}







	//The decrement(--) This is postfix form for Fractions. To decrement a Fraction
	//means to subtract one(1). POST:returns Fraction object then it subtracts 1
	Fraction Fraction::operator--(int)//post
	{
		Fraction temp(numerator, denominator);
		numerator = numerator - denominator;
		simplify();

		return temp;
	}







	//relational operator (>) . It's operator overload. All math logic apply. 
	//compare Fractions to other Fractions as well as Fractions to integers. Either
	//Fractions or integers can appear on either side of the binary comparison
	//operator. POST: returns true if left side Fraction object l (or an integer)
	//  is greater than right side Fraction object r (or an integer)
	bool operator>(const Fraction& l, const Fraction& r)
	{
		return l.numerator * r.denominator > l.denominator * r.numerator;
	}







	//relational operator (>=) . It's operator overload. All math logic apply. 
	//compare Fractions to other Fractions as well as Fractions to integers. Either
	//Fractions or integers can appear on either side of the binary comparison
	//operator. POST: returns true if left side Fraction object l (or an integer)
	//is greater than or equal to right side Fraction object r (or an integer)
	bool operator>=(const Fraction& l, const Fraction& r)
	{
		return l.numerator * r.denominator >= l.denominator * r.numerator;
	}







	//relational operator (<) . It's operator overload. All math logic apply. 
	//compare Fractions to other Fractions as well as Fractions to integers. Either
	//Fractions or integers can appear on either side of the binary comparison
	//operator. POST: returns true if left side Fraction object l (or an integer)
	//is smaller than right side Fraction object r (or an integer).
	bool operator<(const Fraction& l, const Fraction& r)
	{
		return l.numerator * r.denominator < l.denominator* r.numerator;
	}







	//relational operator (<=) . It's operator overload. All math logic apply. 
	//compare Fractions to other Fractions as well as Fractions to integers. Either
	//Fractions or integers can appear on either side of the binary comparison
	//operator. POST: returns true if left side Fraction object l (or an integer)
	//is smaller than or equal to right side Fraction object r (or an integer).
	bool operator<=(const Fraction& l, const Fraction& r)
	{
		return l.numerator * r.denominator <= l.denominator * r.numerator;
	}




	


	//relational operator (==) . It's operator overload. All math logic apply. 
	//compare Fractions to other Fractions as well as Fractions to integers. Either
	//Fractions or integers can appear on either side of the binary comparison
	//operator. POST: returns true if left side Fraction object l (or an integer)
	//is equal to right side Fraction object r (or an integer)
	bool operator==(const Fraction& l, const Fraction& r)
	{
		return l.numerator * r.denominator == l.denominator * r.numerator;
	}







	//relational operator (!=). It's operator overload. All math logic apply. 
	//compare Fractions to other Fractions as well as Fractions to integers. Either
	//Fractions or integers can appear on either side of the binary comparison
	//operator. POST: returns true if left side Fraction object l (or an integer)
	//is NOT equal to right side Fraction object r (or an integer)
	bool operator!=(const Fraction& l, const Fraction& r)
	{
		return l.numerator * r.denominator != l.denominator * r.numerator;
	}







	//this private function doesn't take parameters. the loop finds the greatest common
	//denominator. it simplfies the fraction to set both of them as small as possible
	//without changing the fraction's own value. POST: simplfies the fraction, sets both
	//numerator and denominator as small as possible without changing the fraction's
	//own value. This function can be called by the public member functions or friend 
	//functions, but can not be be seen or called by the client program.
	void Fraction::simplify()
	{
		assert(denominator != 0);//handle denominator is 0 problem

		int maxCommonDenom = 1;//smallest common denominator is 1

		if (denominator < 0)
		{
			numerator = numerator * (-1);
			denominator = denominator * (-1);
		}

		if (numerator == 0)
		{
			denominator = 1;
		}


		for (int i = 1; i <= denominator; i++)
		{
			if (numerator % i == 0 && denominator % i == 0)
			{
				maxCommonDenom = i; //finds the greatest common denominator
			}
		}

		numerator = numerator / maxCommonDenom;
		denominator = denominator / maxCommonDenom;
	}

}
