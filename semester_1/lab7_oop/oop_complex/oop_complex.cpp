#include "oop_complex.h"

double Complex::Abs() const {
    return std::sqrt(re * re + im * im);
}

Complex& Complex::operator+=(const Complex& other) {
    *this = *this + other;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    *this = *this - other;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    *this = *this * other;
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    *this = *this / other;
    return *this;
}

Complex& Complex::operator+=(double val) {
    *this = *this + val;
    return *this;
}

Complex& Complex::operator-=(double val) {
    *this = *this - val;
    return *this;
}

Complex& Complex::operator*=(double val) {
    *this = *this * val;
    return *this;
}

Complex& Complex::operator/=(double val) {
    *this = *this / val;
    return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.re * rhs.re - lhs.im * rhs.im, 
                   lhs.re * rhs.im + lhs.im * rhs.re);
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
    double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
    return Complex((lhs.re * rhs.re + lhs.im * rhs.im) / denominator,
                   (lhs.im * rhs.re - lhs.re * rhs.im) / denominator);
}

Complex operator+(const Complex& lhs, double val) {
    return Complex(lhs.re + val, lhs.im);
}

Complex operator-(const Complex& lhs, double val) {
    return Complex(lhs.re - val, lhs.im);
}

Complex operator*(const Complex& lhs, double val) {
    return Complex(lhs.re * val, lhs.im * val);
}

Complex operator/(const Complex& lhs, double val) {
    return Complex(lhs.re / val, lhs.im / val);
}

std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << c.re;
    if (c.im >= 0) {
        out << " + " << c.im << "i";
    } else {
        out << " - " << -c.im << "i";
    }
    return out;
}

std::istream& operator>>(std::istream& in, Complex& c) {
    in >> c.re >> c.im;
    return in;
}