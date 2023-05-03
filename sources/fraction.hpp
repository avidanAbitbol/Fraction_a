#ifndef FRACTION_H
#define FRACTION_H
#pragma once
#include <iostream>
using namespace std;

namespace ariel {

    class Fraction {
    private:
        int numerator;
        int denominator;
        float value;
    public:
        Fraction(int numerator, int denominator);

        Fraction(float value);

        int getNumerator() const;

        int getDenominator() const;

        Fraction &operator++();

        Fraction operator++(int);

        Fraction &operator--();

        Fraction operator--(int);

        friend Fraction operator+(const Fraction &fraction_a, const Fraction &fraction_b);

        friend Fraction operator+(const Fraction &fraction_a, const float &fraction_b);

        friend Fraction operator+(const float &fraction_a, const Fraction &fraction_b);

        friend Fraction operator-(const Fraction &fraction_a, const Fraction &fraction_b);

        friend Fraction operator-(const float &fraction_a, const Fraction &fraction_b);

        friend Fraction operator-(const Fraction &fraction_a, const float &fraction_b);

        friend Fraction operator*(const Fraction &fraction_a, const float &fraction_b);

        friend Fraction operator*(const float &fraction_a, const Fraction &fraction_b);

        friend Fraction operator*(const Fraction &fraction_a, const Fraction &fraction_b);

        friend Fraction operator/(const float &fraction_a, const Fraction &fraction_b);

        friend Fraction operator/(const Fraction &fraction_a, const float &fraction_b);

        friend Fraction operator/(const Fraction &fraction_a, const Fraction &fraction_b);

        friend ostream &operator<<(ostream &osstrea, const Fraction &fraction);

        friend istream &operator>>(istream &istrea, Fraction &fraction);

        friend bool operator==(const Fraction &fraction_a, const Fraction &fraction_b);

        friend bool operator==(const float &fraction_a, const Fraction &fraction_b);

        friend bool operator==(const Fraction &fraction_a, const float &fraction_b);

        friend bool operator!=(const Fraction &fraction_a, const Fraction &fraction_b);

        friend bool operator!=(const float &fraction_a, const Fraction &fraction_b);

        friend bool operator!=(const Fraction &fraction_a, const float &fraction_b);

        friend bool operator>(const Fraction &fraction_a, const Fraction &fraction_b);

        friend bool operator>(const float &fraction_a, const Fraction &fraction_b);

        friend bool operator>(const Fraction &fraction_a, const float &fraction_b);

        friend bool operator<(const Fraction &fraction_a, const float &fraction_b);

        friend bool operator<(const float &fraction_a, const Fraction &fraction_b);

        friend bool operator<(const Fraction &fraction_a, const Fraction &fraction_b);

        friend bool operator>=(const float &fraction_a, const Fraction &fraction_b);

        friend bool operator>=(const Fraction &fraction_a, const float &fraction_b);

        friend bool operator>=(const Fraction &fraction_a, const Fraction &fraction_b);

        friend bool operator<=(const float &fraction_a, const Fraction &fraction_b);

        friend bool operator<=(const Fraction &fraction_a, const Fraction &fraction_b);

        friend bool operator<=(const Fraction &fraction_a, const float &fraction_b);

        void reduce();








    };
};
#endif // FRACTION_H
