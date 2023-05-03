#include "fraction.hpp"
#include <iostream>
#include <stdexcept>
#include <numeric>
using namespace std;

namespace ariel {

    Fraction::Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        this->numerator = numerator;
        this->denominator = denominator;
        this->value = (float) numerator / denominator;
        reduce();
    }

    Fraction::Fraction(float value) {
        int denominator = 1;
        int numerator = (int) (value * denominator);
        float epsilon = 0.00001;
        while (abs((float) numerator / denominator - value) > epsilon) {
            denominator++;
            numerator = (int) (value * denominator);
        }
        this->numerator = numerator;
        this->denominator = denominator;
        this->value = value;
        reduce();
    }

    int Fraction::getNumerator() const {
        return this->numerator;
    }

    int Fraction::getDenominator() const {
        return this->denominator;
    }

    Fraction& Fraction::operator++() {
        this->numerator += this->denominator;
        this->value = (float) this->numerator / this->denominator;
        return *this;
    }

    Fraction Fraction::operator++(int) {
        Fraction old_value = *this;
        this->numerator += this->denominator;
        this->value = (float) this->numerator / this->denominator;
        return old_value;

    }

    Fraction& Fraction::operator--() {
        this->numerator -= this->denominator;
        this->value = (float) this->numerator / this->denominator;
        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction old_value = *this;
        this->numerator -= this->denominator;
        this->value = (float) this->numerator / this->denominator;
        return old_value;
    }

    Fraction operator+(const Fraction& fraction_a, const Fraction& fraction_b) {
        int new_numerator = fraction_a.getNumerator() * fraction_b.getDenominator() +
                            fraction_b.getNumerator() * fraction_a.getDenominator();
        int new_denominator = fraction_a.getDenominator() * fraction_b.getDenominator();
        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator+(const Fraction& fraction_a, const float& fraction_b) {
        return fraction_a + Fraction(fraction_b);
    }

    Fraction operator+(const float& fraction_a, const Fraction& fraction_b) {
        return Fraction(fraction_a) + fraction_b;
    }

    Fraction operator-(const Fraction& fraction_a, const Fraction& fraction_b) {
        int new_numerator = fraction_a.getNumerator() * fraction_b.getDenominator() -
                            fraction_b.getNumerator() * fraction_a.getDenominator();
        int new_denominator = fraction_a.getDenominator() * fraction_b.getDenominator();
        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator-(const float& fraction_a, const Fraction& fraction_b) {
        return Fraction(fraction_a) - fraction_b;
    }

    Fraction operator-(const Fraction& fraction_a, const float& fraction_b) {
        return fraction_a - Fraction(fraction_b);
    }

    Fraction operator*(const Fraction& fraction_a, const float& fraction_b) {
        return Fraction(fraction_a.getNumerator() * fraction_b, fraction_a.getDenominator());
    }

    Fraction operator*(const float& fraction_a, const Fraction& fraction_b) {
        return fraction_b * fraction_a;
    }

    Fraction operator*(const Fraction& fraction_a, const Fraction& fraction_b) {
        return Fraction(fraction_a.getNumerator() * fraction_b.getNumerator(),
                        fraction_a.getDenominator() * fraction_b.getDenominator());
    }

    Fraction operator/(const float& fraction_a, const Fraction& fraction_b) {
        return Fraction(fraction_a) / fraction_b;
    }

    Fraction operator/(const Fraction& fraction_a, const float& fraction_b) {
        return fraction_a / Fraction(fraction_b);
    }

    Fraction operator/(const Fraction& fraction_a, const Fraction& fraction_b) {
        if (fraction_b == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return fraction_a * Fraction(fraction_b.getDenominator(), fraction_b.getNumerator());
    }

    // Output stream operator
    ostream& operator<<(ostream& os, const Fraction& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }

    // Input stream operator
    istream& operator>>(istream& is, Fraction& fraction) {
        char c;
        is >> fraction.numerator >> c >> fraction.denominator;
        fraction.reduce();
        return is;
    }

    // Equality operator with another fraction

    bool operator==(const Fraction &fraction_a, const Fraction &fraction_b) {
        return fraction_a.numerator == fraction_b.numerator && fraction_a.denominator == fraction_b.denominator;
    }

    bool operator==(const float &fraction_a, const Fraction &fraction_b) {
        float float_a = fraction_a;
        return float_a == static_cast<float>(fraction_b.numerator) / fraction_b.denominator;
    }

    bool operator==(const Fraction &fraction_a, const float &fraction_b) {
        float float_b = fraction_b;
        return static_cast<float>(fraction_a.numerator) / fraction_a.denominator == float_b;
    }

    bool operator!=(const Fraction &fraction_a, const Fraction &fraction_b) {
        return !(fraction_a == fraction_b);
    }

    bool operator!=(const float &fraction_a, const Fraction &fraction_b) {
        return !(fraction_a == fraction_b);
    }

    bool operator!=(const Fraction &fraction_a, const float &fraction_b) {
        return !(fraction_a == fraction_b);
    }

    bool operator>(const Fraction &fraction_a, const Fraction &fraction_b) {
        return static_cast<float>(fraction_a.numerator) / fraction_a.denominator > static_cast<float>(fraction_b.numerator) / fraction_b.denominator;
    }

    bool operator>(const float &fraction_a, const Fraction &fraction_b) {
        float float_a = fraction_a;
        return float_a > static_cast<float>(fraction_b.numerator) / fraction_b.denominator;
    }

    bool operator>(const Fraction &fraction_a, const float &fraction_b) {
        float float_b = fraction_b;
        return static_cast<float>(fraction_a.numerator) / fraction_a.denominator > float_b;
    }

    bool operator<(const Fraction &fraction_a, const Fraction &fraction_b) {
        return static_cast<float>(fraction_a.numerator) / fraction_a.denominator < static_cast<float>(fraction_b.numerator) / fraction_b.denominator;
    }

    bool operator<(const float &fraction_a, const Fraction &fraction_b) {
        float float_a = fraction_a;
        return float_a < static_cast<float>(fraction_b.numerator) / fraction_b.denominator;
    }

    bool operator<(const Fraction &fraction_a, const float &fraction_b) {
        float float_b = fraction_b;
        return static_cast<float>(fraction_a.numerator) / fraction_a.denominator < float_b;
    }

    bool operator>=(const Fraction &fraction_a, const Fraction &fraction_b) {
        return fraction_a > fraction_b || fraction_a == fraction_b;
    }

    bool operator>=(const float &fraction_a, const Fraction &fraction_b) {
        return fraction_a > fraction_b || fraction_a == fraction_b;
    }

    bool operator>=(const Fraction &fraction_a, const float &fraction_b) {
        return fraction_a > fraction_b || fraction_a == fraction_b;
    }

    bool operator<=(const Fraction &fraction_a, const Fraction &fraction_b) {
        return fraction_a < fraction_b || fraction_a == fraction_b;
    }

    bool operator<=(const float &fraction_a, const Fraction &fraction_b) {
        return fraction_a < fraction_b || fraction_a == fraction_b;
    }

    bool operator<=(const Fraction &fraction_a, const float &fraction_b) {
        return fraction_a < fraction_b || fraction_a == fraction_b;
    }
    void Fraction::reduce() {
        int gcd = __gcd(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;

        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }
}