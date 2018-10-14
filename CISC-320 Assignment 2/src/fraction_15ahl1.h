/*
Alastair Lewis
20016877
CMPE/CISC-320
Assignment 2
Operator Overloading
 */

#ifndef FRACTION_15AHL1_H_
#define FRACTION_15AHL1_H_
#include <iostream>

using namespace std;

class FractionException {
public:
	string what();
};

class Fraction {
public:
	//Constructors
	Fraction();
	Fraction(int a);
	Fraction(int a, int b);

	//Accessors
	int numerator() const;
	int denominator() const;
	//Function to reduce fractions
	Fraction reduce(Fraction f);

	//Member Function Overloading
	Fraction& operator++();		//Pre
	Fraction operator++(int); 	//Post
	Fraction& operator+=(Fraction& f);

private:
	//Numerator and Denominator
	int n;
	int d;

	//Friend Functions
	friend int compareTo(const Fraction& a, const Fraction& b);
	friend bool operator==(const Fraction a, const Fraction b);
	friend bool operator!=(const Fraction a, const Fraction b);
	friend bool operator>(const Fraction a, const Fraction b);
	friend bool operator<(const Fraction a, const Fraction b);
	friend bool operator>=(const Fraction a, const Fraction b);
	friend bool operator<=(const Fraction a, const Fraction b);
	friend istream& operator>>(istream& in, Fraction& f);
};

//Non Member Function Overloading
Fraction operator+(const Fraction& a, const Fraction& b);
Fraction operator-(const Fraction& a, const Fraction& b);
Fraction operator*(const Fraction& a, const Fraction& b);
Fraction operator/(const Fraction& a, const Fraction& b);
Fraction operator-(const Fraction& a);
ostream& operator<<(ostream& out, const Fraction& f);

//Custom function for finding char index in a string
int findChar(string s, char t);
#endif
