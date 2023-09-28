#include "Fraction.h"

int Fraction::GetNum() {
	return num%den;
}
void Fraction::SetNum(int value) {
	num = value;
}
int Fraction::GetDen() {
	return den;
}
void Fraction::SetDen(int value) {
	den = value;
}
int Fraction::GetInteg() {
	return num / den;
}
void Fraction::SetInteg(int value) {
	value = value - num / den;
	num = value * den + num;
}
void Fraction::Print() {
	if (num % den == 0) {
		cout << num / den << endl;
	}
	else if (num < 0) {
		cout << num / den << "." << -num % den << "/" << den << endl;
	}
	else {
		cout << num / den << "." << num % den << "/" << den << endl;
	}
}
Fraction::Fraction(int a, int b, int c) {
	try {
		if (c < 0) {
			throw runtime_error("Negative denominator");
		}
		if (b < 0) {
			throw runtime_error("Negative numerator");
		}
		if (a < 0) {
			throw runtime_error("Negative integer");
		}
		if (c == 0) {
			throw runtime_error("Division by zero");
		}
		num = a * c + b;
		den = c;
	}
	catch (const runtime_error& e) {
		cout << e.what();
		exit(0);
	}
}
Fraction::Fraction() {

}
Fraction::~Fraction() {

}
Fraction& Fraction::operator =(const Fraction& a) {
	this->den = a.den;
	this->num = a.num;
	return *this;
}
Fraction& Fraction::operator =(const int a) {
	this->num = this->den * a;
	return *this;
}
double Fraction::Convert() {
	return this->num * 1. / this->den;
}
int NOD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return abs(NOD(b, a % b));
}
Fraction Fraction::PlusMinus(Fraction a, const Fraction b, bool plus_minus_flag) {
	Fraction result (a);
	int SumNum;
	if (plus_minus_flag) {
		SumNum = (a.num * b.den) + (a.den * b.num);
	}
	else {
		SumNum = (a.num * b.den) - (a.den * b.num);
	}
	int CommonDenom = a.den * b.den;
	if (CommonDenom == 0) {
		return result;
	}
	else {
		int CommonDivisor = NOD(CommonDenom, SumNum);
		result.den = CommonDenom / CommonDivisor;
		result.num = SumNum / CommonDivisor;
		return result;
	}
}
Fraction& Fraction::PlusMinusRavno(Fraction& a, const Fraction b, bool plus_minus_flag) {
	int SumNum;
	if (plus_minus_flag) {
		SumNum = (a.num * b.den) + (a.den * b.num);
	}
	else {
		SumNum = (a.num * b.den) - (a.den * b.num);
	}
	int CommonDenom = a.den * b.den;
	int CommonDivisor = NOD(CommonDenom, SumNum);
	a.den = CommonDenom / CommonDivisor;
	a.num = SumNum / CommonDivisor;
	return a;
}

Fraction Fraction::operator +(const Fraction& a) {
	return 	PlusMinus(*this, a, 1);
}
Fraction& Fraction::operator +=(const Fraction& a) {
	return PlusMinusRavno(*this, a, 1);
}
Fraction Fraction::operator +(const int a) {
	Fraction result(*this);
	result.num = this->num + a * this->den;
	return result;
}
Fraction& Fraction::operator +=(const int a) {
	this->num += a * this->den;
	return *this;
}
Fraction Fraction::operator -(const Fraction& a) {
	return PlusMinus(*this, a, 0);
}
Fraction& Fraction::operator -=(const Fraction& a) {
	return PlusMinusRavno(*this, a, 0);
}
Fraction Fraction::operator -(const int a) {
	Fraction result(*this);
	result.num = this->num - a * this->den;
	return result;
}
Fraction& Fraction::operator -=(const int a) {
	this->num -= a * this->den;
	return *this;
}
Fraction Fraction::operator *(const int a) {
	Fraction result(*this);
	result.num = this->num * a;
	return result;
}
Fraction Fraction::operator /(const int a) {
	Fraction result(*this);
	if (a < 0) {
		result.num = -result.num;
		result.den = -this->den * a;
	}
	else {
		result.den = this->den * a;
	}
	return result;
}
Fraction Fraction::operator *(const Fraction& a) {
	Fraction result(*this);
	result.num *= a.num;
	result.den *= a.den;
	return result;
}
Fraction Fraction::operator /(const Fraction& a) {
	Fraction result(*this);
	if ((a.num < 0 && result.num < 0) || (a.num < 0)) { // если две отрицательные дроби или одна
		result.den = -result.den;
		result.num = -result.num;
	}
	result.num = result.num * a.den;
	result.den = result.den * a.num;
	return result;
}
Fraction& Fraction::operator *=(const int a) {
	this->num *= a;
	return *this;
}
Fraction& Fraction::operator /=(const int a) {
	if (a < 0) {
		this->num = -this->num;
		this->den = -this->den * a;
	}
	else {
		this->den = this->den * a;
	}
	return *this;
}
Fraction& Fraction::operator /=(const Fraction& a) {
	if ((a.num < 0 && this->num < 0) || (a.num < 0)) { // если две отрицательные дроби или одна
		this->den = -this->den;
		this->num = -this->num;
	}
	this->num = this->num * a.den;
	this->den = this->den * a.num;
	return *this;
}
Fraction& Fraction::operator *=(const Fraction& a) {
	this->num *= a.num;
	this->den *= a.den;
	return *this;
}
Fraction operator +(int num, const Fraction& a) {
	Fraction result(a);
	result.num = a.num + num * a.den;
	return result;
}
Fraction operator -(int num, const Fraction& a) {
	Fraction result(a);
	result.num = num * a.den - result.num;
	return result;
}
Fraction operator *(int num, const Fraction& a) {
	Fraction result(a);
	result.num = a.num * num;
	return result;
}
Fraction operator /(int num, const Fraction& a) {
	Fraction result(a);
	if (a.num < 0) {
		result.num = -a.den * num;
		result.den = -a.num;
	}
	else {
		result.num = a.den * num;
		result.den = a.num;
	}
	return result;
}
Fraction Fraction::operator ++(int) {
	Fraction result(*this);
	result.num = result.num + result.den;
	return result;
}
Fraction& Fraction::operator ++() {
	this->num = this->num + this->den;
	return *this;
}
Fraction Fraction::operator --(int) {
	Fraction result(*this);
	result.num = result.num - result.den;
	return result;
}
Fraction& Fraction::operator --() {
	this->num = this->num - this->den;
	return *this;
}
bool Fraction::operator >(const Fraction& a) {
	double n = this->num * 1. / this->den;
	double m = a.num * 1. / a.den;
	return n > m;
}
bool Fraction::operator <(const Fraction& a) {
	double n = this->num * 1. / this->den;
	double m = a.num * 1. / a.den;
	return n < m;
}
bool Fraction::operator >=(const Fraction& a) {
	double n = this->num * 1. / this->den;
	double m = a.num * 1. / a.den;
	return n >= m;
}
bool Fraction::operator <=(const Fraction& a) {
	double n = this->num * 1. / this->den;
	double m = a.num * 1. / a.den;
	return n <= m;
}
bool Fraction::operator >(const double a) {
	double n = this->num * 1. / this->den;
	return n > a;
}
bool Fraction::operator <(const double a) {
	double n = this->num * 1. / this->den;
	return n < a;
}
bool Fraction::operator >=(const double a) {
	double n = this->num * 1. / this->den;
	return n >= a;
}
bool Fraction::operator <=(const double a) {
	double n = this->num * 1. / this->den;
	return n <= a;
}
bool operator >(double num, const Fraction& a) {
	double n = a.num * 1. / a.den;
	return num > n;
}
bool operator <(double num, const Fraction& a) {
	double n = a.num * 1. / a.den;
	return num < n;
}
bool operator >=(double num, const Fraction& a) {
	double n = a.num * 1. / a.den;
	return num >= n;
}
bool operator <=(double num, const Fraction& a) {
	double n = a.num * 1. / a.den;
	return num <= n;
}