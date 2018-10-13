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
	Fraction();
	Fraction(int a);
	Fraction(int a, int b);
	int numerator() const;
	int denominator() const;
	Fraction reduce(Fraction f);
	Fraction& operator++();	//Pre
	Fraction operator++(int); //Post
	Fraction& operator+=(Fraction& f);

private:
	int n;
	int d;

	//friend functions
	friend int compareTo(const Fraction& a, const Fraction& b);
	friend bool operator==(const Fraction a, const Fraction b);
	friend bool operator!=(const Fraction a, const Fraction b);
	friend bool operator>(const Fraction a, const Fraction b);
	friend bool operator<(const Fraction a, const Fraction b);
	friend bool operator>=(const Fraction a, const Fraction b);
	friend bool operator<=(const Fraction a, const Fraction b);
	friend istream& operator>>(istream& in, Fraction& f);

};

Fraction operator+(const Fraction& a, const Fraction& b);
Fraction operator-(const Fraction& a, const Fraction& b);
Fraction operator*(const Fraction& a, const Fraction& b);
Fraction operator/(const Fraction& a, const Fraction& b);
Fraction operator-(const Fraction& a);

ostream& operator<<(ostream& out, const Fraction& f);
int findChar(string s, char t);
#endif
