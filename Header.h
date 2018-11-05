#pragma once
#include <string>
using namespace std;

class Rational
{
public:
	
	void Fraction(int num, int den);
	void Den(int den);
	void Num(int num);
	int Den();
	int Num();
	string ToString();
	

	Rational(int num = 0, int den= 1);
	Rational( Rational &r1);

	Rational& operator+=( Rational& r2);
	Rational& operator+=( int& r2);
    Rational& operator-=(Rational& r2);
	Rational& operator-=( int& r2);
    Rational& operator*=( Rational& r2);
	Rational& operator*=( int& r2);
    Rational& operator/=( Rational& r2);
	Rational& operator/=( int& r2);

	friend Rational& operator+ (Rational& num);
	friend Rational operator- (Rational& num);

	friend Rational operator+( Rational& a1, const Rational& a2);
	friend Rational operator+( Rational& a1, int& a2);
	friend Rational operator+(int& ca1,  Rational& a2);
    friend Rational operator-( Rational& a1,  Rational& a2);
	friend Rational operator-( Rational& a1, int& a2);
	friend Rational operator-(int& a1,  Rational& a2);
    friend Rational operator*( Rational& a1,  Rational& a2);
	friend Rational operator*(Rational& a1, int& a2);
	friend Rational operator*(int& a1, Rational& a2);
    friend Rational operator/( Rational& a1,  Rational& a2);
	friend Rational operator/( Rational& a1, int& a2);
	friend Rational operator/(int& a1,  Rational& a2);
    friend Rational operator^( Rational& a1, int& a2);

	friend bool operator==( Rational& a1, Rational& a2);
	friend bool operator==( Rational& a1, int& a2);
	friend bool operator==(int& a1,  Rational& a2);
    friend bool operator!=( Rational& a1, int& a2);
	friend bool operator!=(int& a1,  Rational& a2);
	friend bool operator!=(Rational& a1, Rational& a2);
    friend bool operator>( Rational& a1, Rational& a2);
	friend bool operator>( Rational& a1, int& a2);
	friend bool operator>(int& a1,  Rational& a2);
    friend bool operator>=(Rational& a1, int& a2);
	friend bool operator>=( Rational& a1,  Rational& a2);
	friend bool operator>=(int& a1,  Rational& a2);
    friend bool operator<( Rational& a1, int& a2);
	friend bool operator<(int& a1,  Rational& a2);
	friend bool operator<(Rational& a1, Rational& a2);
    friend bool operator<=( Rational& a1, Rational& a2);
	friend bool operator<=(int& a1, Rational& a2);
	friend bool operator<=( Rational& a1, int& a2);
	
	operator double() ;
	operator int() ;
	operator string();

	friend istream& operator>>(istream & input, Rational& r);
	friend ostream& operator<<(ostream& stream, Rational& r);

private:
	int n_num, m_den;
	void CanonicalForm();
};