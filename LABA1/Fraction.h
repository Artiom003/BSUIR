#pragma once
#include <iostream>
#include <string>

using namespace std;

class Fraction {
private:
	int num = 0;
	int den = 0;
	Fraction PlusMinus(Fraction a, const Fraction b, bool c);
	Fraction& PlusMinusRavno(Fraction& a, const Fraction b, bool c);

public:

	Fraction(int, int, int);
	Fraction();
	~Fraction();

	int GetNum(); // получение значений
	void SetNum(int value);
	int GetDen();
	void SetDen(int value);
	int GetInteg();
	void SetInteg(int value);
	void Print();

	Fraction& operator =(const Fraction& a);
	Fraction& operator =(const int a);

	double Convert();

	Fraction operator +(const Fraction& a);
	Fraction operator +(const int a);
	Fraction& operator +=(const Fraction& a);
	Fraction& operator +=(const int a);

	Fraction operator -(const Fraction& a);
	Fraction operator -(const int a);
	Fraction& operator -=(const Fraction& a);
	Fraction& operator -=(const int a);

	Fraction operator *(const Fraction& a);
	Fraction operator *(const int a);
	Fraction& operator *=(const Fraction& a);
	Fraction& operator *=(const int a);

	Fraction operator /(const Fraction& a);
	Fraction operator /(const int a);
	Fraction& operator /=(const Fraction& a);
	Fraction& operator /=(const int a);

	friend Fraction operator +(int num, const Fraction& a);
	friend Fraction operator -(int num, const Fraction& a);
	friend Fraction operator *(int num, const Fraction& a);
	friend Fraction operator /(int num, const Fraction& a);

	Fraction operator ++(int); //a++
	Fraction& operator ++();   //++a можно использовать в отдельной строчке
	Fraction operator --(int); //a--
	Fraction& operator --();   //--a можно использовать в отдельной строчке

	bool operator >(const Fraction& a);
	bool operator >(const double a);
	bool operator >=(const Fraction& a);
	bool operator >=(const double a);

	bool operator <(const Fraction& a);
	bool operator <(const double a);
	bool operator <=(const Fraction& a);
	bool operator <=(const double a);

	friend bool operator >(double num, const Fraction& a);
	friend bool operator <(double num, const Fraction& a);
	friend bool operator >=(double num, const Fraction& a);
	friend bool operator <=(double num, const Fraction& a);
};
