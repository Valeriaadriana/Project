#include "Rational.hpp"
#include <cmath>
#include <iostream>

using namespace std;


int Rational::GetDen()
{
	return m_den;
}

int Rational::GetNum()
{
	return n_num;
}
void Rational::CanonicalForm()
{
	int p = n_num < m_den? n_num : m_den;
	int gcd = 1;

	for (int i = 2; i <= p; i++)
	{
		if (n_num % i == 0 && m_den % i == 0) 
		{
			gcd = i;
		}
	}

	n_num /= gcd;
	m_den /= gcd;
}
void Rational::Fraction(int num, int den)
{
	m_den = den;
	n _num = num;

	CanonicalForm();
}

void Rational::Num(int num)
{
	n_num = num;

	CanonicalForm();
}

void Rational::Den(int den)
{
	m_den = den;

	CanonicalForm();
}


Rational::Rational(int num=0, int den=1)
{
	if (m_den == 0)
	{
		cout<< "Denominator is 0";
	}
	else
	{
		m_den = denom;
		n_num = num;

		CanonicalForm();
	}
}

string Rational::ToString()
{
	string string;
	string = to_string(n_num);
	if (m_den!= 0) {
		string += "/" + to_string(m_den);
	}

	return string;
}




Rational::Rational( Rational & r1)
{
	m_den = r1.m_den;
	n_num= r1.n_num;
}

Rational& Rational::operator+=(Rational & r2)
{
	n_num = n_num * r2.m_den+ m_den * r2.n_num;
	m_den *= r2.m_den;

	CanonicalForm();

	return *this;
}

Rational & Rational::operator+=( int & r2)
{
	n_num = n_num + m_den * r2;

	CanonicalForm();

	return *this;
}

Rational & Rational::operator-=( Rational & r2
{
	n_num = n_num * r2.m_den - m_den * r2.n_num;
	m_den *= r2.m_den;

	CanonicalForm();

	return *this;
}

Rational & Rational::operator-=( int & r2)
{
	n_num = n_num - m_den * r2;

	CanonicalForm();

	return *this;
}

Rational & Rational::operator*=( Rational & r2)
{
	m_den *= r2.m_den;
	n_num *= r2.n_num;

	CanonicalForm();

	return *this;
}

Rational & Rational::operator*=(const int & r2)
{
	n_num *= r2;

	CanonicalForm();

	return *this;
}

Rational & Rational::operator/=( Rational & r2)
{
	m_den *= r2.n_num;
	n_num *= r2.m_den;

	CanonicalForm();

	return *this;
}

Rational & Rational::operator/=( int & r2)
{
	m_den *= r2;

	CanonicalForm();

	return *this;
}

Rational & operator+(Rational & num)
{
	return num;
}

Rational operator-(Rational & num)
{
	Rational newRat = Rational(-num.n_num, num.m_den);

	return newRat;
}

Rational operator+( Rational & a1,  Rational & a2)
{
	int num, den;
	num = a1.n_num * a2.m_den + a1._den * a2._num;

	den = a1.m_den* a2.m_den;

	Rational newRat = Rational(num, den);

	return newRat;
}

Rational operator+( Rational & a1, int & a2)
{
	int num, denum;
	num = a1.n_num + a2.m_den * a2;

	den = a1.m_den;

	Rational newRat = Rational(num, den);

	return newRat;
}

Rational operator+(int & a1,  Rational & a2)
{
	return operator+(a2, a1);
}


Rational operator-( Rational & a1, Rational & a2)
{
	int num, den;
	num = a1.n_num * a2.m_den- a1.m_den * a2.n_num;

	den= a1.m_den * a2.m_den;

	Rational newRat = Rational(num, den);

	return newRat;
}

Rational operator-( Rational & a1, int & a2)
{
	int num, den;
	num = a1.n_num - a1.m_den * a2;

	den = a1.m_den;

	Rational newRat= Rational(num, den);

	return newRat;
}

Rational operator-(int & a1,  Rational & a2)
{
	int num, den;
	num = a2.m_den * a1 - a2.n_num;

	den = a2.m_den;

	Rational newRat = Rational(num, den);

	return newRat;
}

Rational operator*( Rational & a1,  Rational & a2)
{
	int num, den;
	num = a1.n_num * a2.n_num;

	den = a1.m_den * a2.m_den;

	Rational newRat = Rational(num, den);

	return newRat;
}

Rational operator*( Rational & a1, int & a2)
{
	int num, den;
	num = a1.n_num * a2;

	den= a1.m_den;

	Rational newRat = Rational(num, den);

	return newRat;
}

Rational operator*(int & a1,  Rational & a2)
{
	return operator*(a2, a1);
}

Rational operator/( Rational & a1, Rational & a2)
{
	int num, den;
	num = a1.n_num * a2.m_den;

	den = a1.m_den * a2.n_num;

	Rational newRat= Rational(num, den);

	return newRat;
}

Rational operator/( Rational & a1, int & a2)
{
	int num, den;
	num = a1.n_num;

	den = a1.m_den * a2;

	Rational newRat= Rational(num, den);

	return newRat;
}

Rational operator/(int & a1, Rational & a2)
{
	int num, den;
	num = a1 * a2.m_den;

	den= a2.n_num;

	Rational newRat= Rational(num, den);

	return newRat;
}

Rational operator^( Rational & a1, int & a2)
{
	int num, den;
	num = pow(a1.n_num, a2);// base raised to the power of exponent.

	den= pow(a1.m_den, a2);

	Rational newRat = Rational(num, den);

	return newRat;
}

bool operator==(Rational & a1,  Rational & a2)
{
	return a1.m_den == a2.m_den &&a1.n_num== a2.n_num;
}

bool operator==( Rational & a1, int & a2)
{
	return a1.n_num == a2 && a1.m_den == 1;
}

bool operator==(int & a1, Rational & a2)
{
	return operator==(a2, a1);
}
bool operator!=(Rational & a1, int & a2)
{
	return operator==(a1, a2) == false;
}

bool operator!=( Rational & a1,  Rational & a2)
{
	return operator==(a1, a2) == false;
}


bool operator!=(int & a1,  Rational & a2)
{
	return operator==(a1, a2) == false;
}
bool operator>(int & a1, Rational & a2)
{
	return a1 * a2.m_den > a2.n_num;
}

bool operator>( Rational & a1, Rational & a2)
{
	return a1.n_num * a2.m_den> a2.n_num* a1.m_den;
}

bool operator>( Rational & a1, int & a2)
{
	return a1.n_num > a2 * a1.m_den;
}


bool operator>=( Rational & a1,  Rational & a2)
{
	return operator>(a1, a2) || operator==(a1, a2);
}

bool operator>=( Rational & a1, int & a2)
{
	return operator>(a1, a2) || operator==(a1, a2);
}

bool operator>=(int & a1, Rational & a2)
{
	return operator>(a1, a2) || operator==(a1, a2);
}
bool operator>=(Rational & a1, int & a2)
{
	return operator>(a1, a2) || operator==(a1, a2);
}

bool operator<( Rational & a1,  Rational & a2)
{
	return operator>=(a1, a2) == false;
}
bool operator<(int & a1, Rational & a2)
{
	return operator>=(a1, a2) == false;
}
bool operator<( Rational & a1, int & a2)
{
	return operator>=(a1, a2) == false;
}



bool operator<=( Rational & a1, Rational & a2)
{
	return operator>(a1, a2) == false;
}

bool operator<=( Rational & a1, int & a2)
{
	return operator>(a1, a2) == false;
}

bool operator<=(int & a1,  Rational & a2)
{
	return operator>(a1, a2) == false;
}

Rational::operator double() 
{
	return (double)n_num / m_den;
}

Rational::operator int() 
{
	return (int)floor(n_num / m_den);//round
}

Rational::operator string()
{
	return ToString();
}

istream & operator>>(istream & input, Rational & r)
{
	string in;

	input >> in;

	int pos = in.find("/");

	if (pos == -1)
	{
		r.m_den = 1;
		r.n_num = atoi(in.c_string());
	}
	else {
		string n = in.substr(0, pos), d = in.substr(pos + 1, in.size());
		r.n_num = atoi(n.c_string());//convert string into integer
		r.m_den= atoi(d.c_string());
	}

	return input;
}

ostream & operator<<(ostream & stream, Rational & r)
{
	cout << r.ToString();

	return stream;
}