/*
 * fraction15ahl1.h
 *
 *  Created on: Oct 9, 2018
 *      Author: Alastair
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
	friend Fraction& operator++();	//Pre
	friend Fraction operator++(int unused); //Post


private:
	int n;
	int d;
};

Fraction operator+(const Fraction& a, const Fraction& b);
Fraction operator-(const Fraction& a, const Fraction& b);
Fraction operator*(const Fraction& a, const Fraction& b);
Fraction operator/(const Fraction& a, const Fraction& b);
Fraction operator-(const Fraction& a);

ostream& operator<<(ostream& out, const Fraction& f);



#endif
