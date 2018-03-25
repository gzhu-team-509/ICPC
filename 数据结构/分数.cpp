#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	return b==0 ? a : gcd(b, a%b);
}

struct Fraction
{
	int num, den;
	Fraction(int num = 0, int den = 1) {
		if (den < 0) {
			num = -num, den = -den;
		}
		assert(den != 0);
		int g = gcd(abs(num), den);
		num /= g, den /= g;
		this->num = num, this->den = den;
	}
	
	Fraction operator +(const Fraction &f) const {
		return Fraction(num*f.den+f.num*den, den*f.den);
	}
	
	Fraction operator -(const Fraction &f) const {
		return Fraction(num*f.den-f.num*den, den*f.den);
	}
	
	Fraction operator *(const Fraction &f) const {
		return Fraction(num*f.num, den*f.den);
	}
	
	Fraction operator /(const Fraction &f) const {
		return Fraction(num*f.den, den*f.num);	
	} 
	
	bool operator <(const Fraction &f) const {
		return (num*f.den < f.num*den);
	}
	
	bool operator ==(const Fraction &f) const {
		return (den == f.den && num == f.num);
	}
	
};

int main()
{
	Fraction a;
	cout << a.num << ' ' << a.den << endl;
}
