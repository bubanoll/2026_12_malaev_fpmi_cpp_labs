#pragma once
#include <cmath>
#include <iostream>
class Complex {
    private:
    double re;
    double im;

    public:
    Complex(double r = 0, double i = 0) : re(r), im(i) {}

    double Real() const { return re; }
    double Imag() const { return im; }

    void Real(double r) { re = r; }
    void Imag(double i) { im = i; }

    double Abs() const;

    Complex operator+() const { return *this; }
    Complex operator-() const { return Complex(-re, -im); }

    bool operator==(const Complex& other) const { return re == other.re && im == other.im; }
    bool operator!=(const Complex& other) const { return !(*this == other); }

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    Complex& operator+=(double val);
    Complex& operator-=(double val);
    Complex& operator*=(double val);
    Complex& operator/=(double val);

    friend Complex operator+(const Complex&, const Complex&);
    friend Complex operator-(const Complex&, const Complex&);
    friend Complex operator*(const Complex&, const Complex&);
    friend Complex operator/(const Complex&, const Complex&);

    friend Complex operator+(const Complex&, double);
    friend Complex operator-(const Complex&, double);
    friend Complex operator*(const Complex&, double);
    friend Complex operator/(const Complex&, double);

    friend std::ostream& operator<<(std::ostream&, const Complex&);
    friend std::istream& operator>>(std::istream&, Complex&);
};