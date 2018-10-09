/*
 * fraction15ahl1.cpp
 *
 *  Created on: Oct 9, 2018
 *      Author: Alastair
 */

#include "fraction_15ahl1.h"
#include <algorithm>
#include <cstdlib>

using namespace std;

string FractionException::what() {
	return "Zero Denominator is Not Allowed.";
}

Fraction::Fraction() {
	n = 0;
	d = 1;
}

Fraction::Fraction(int a){
	n = a;
	d = 1;
}

Fraction::Fraction(int a, int b){
	n = a;
	d = b;
	if(d == 0)
		throw FractionException();

	//Handling Negatives
	if(n < 0 && d < 0){
		n = -n;
		d = -d;
	}
	else if (n > 0 && d < 0){
		n = -n;
		d = -d;
	}

	//Handling GCD
	int g = __gcd(abs(n), abs(d));
	if(g > 1){
		n /= g;
		d /= g;
	}
}

int Fraction::numerator() const{
	return n;
}

int Fraction::denominator() const{
	return d;
}

Fraction Fraction::reduce(Fraction f){
	int g;
	Fraction out(f.numerator(), f.denominator());
	while(out.numerator() > out.denominator() && out.denominator() % out.numerator() == 0){
		g = __gcd(out.numerator(), out.denominator());
		out.n /= g;
		out.d /= g;
	}
	return out;
}

Fraction operator+(const Fraction& a, const Fraction& b){
	int lcm = (a.denominator() * b.denominator()) / __gcd(a.denominator(), b.denominator());

	int n1, n2;
	n1 = a.numerator() * (lcm/a.denominator());
	n2 = b.numerator() * (lcm/b.denominator());

	return Fraction((n1 + n2), lcm);
}

Fraction operator-(const Fraction& a, const Fraction& b){
	int lcm = (a.denominator() * b.denominator()) / __gcd(a.denominator(), b.denominator());

	int n1, n2;
	n1 = a.numerator() * (lcm/a.denominator());
	n2 = b.numerator() * (lcm/b.denominator());

	return Fraction((n1 - n2), lcm);
}

Fraction operator*(const Fraction& a, const Fraction& b){
	int n = a.numerator() * b.numerator();
	int d = a.denominator() * b.denominator();

	Fraction out(n, d);
	return out.reduce(out);
}

Fraction operator/(const Fraction& a, const Fraction& b){
	Fraction out(a.numerator() * b.denominator(), a.denominator() * b.numerator());
	return out.reduce(out);
}

Fraction operator-(const Fraction& a){
	return Fraction(-a.numerator(), a.denominator());
}

ostream& operator<<(ostream& out, const Fraction& f){
	out << f.numerator() << "/" << f.denominator();
	return out;
}





