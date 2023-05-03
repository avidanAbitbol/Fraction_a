//
// Created by avida on 5/2/2023.
//

//
// Created by avida on 5/2/2023.
//

#include "doctest.h"
#include "sources/Fraction.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <random>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>

using namespace std;
using namespace ariel;

TEST_CASE("ZERO_DENOMINATOR") {
    CHECK_THROWS(Fraction(1, 0));
}

TEST_CASE("PLUS") {
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction c = a + b;
    CHECK(c == Fraction(5, 6));
    float f = 0.5;
    Fraction d = a + f;
    CHECK(d == Fraction(1, 1));
    CHECK((1.0 + a) == Fraction(3, 2));
}

TEST_CASE("MINUS") {
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction c = a - b;
    CHECK(c == Fraction(1, 6));
    float f = 0.25;
    Fraction d = a - f;
    CHECK(d == Fraction(1, 4));
    CHECK((1.0 - a) == Fraction(1, 2));
}

TEST_CASE("MULTIPLY") {
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction c = a * b;
    CHECK(c == Fraction(1, 6));
}

TEST_CASE("DIVIDE") {
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction c = a / b;
    CHECK(c == Fraction(3, 2));
}

TEST_CASE("EQUAL") {
    Fraction a(1, 2);
    Fraction b(5, 10);
    Fraction C(1, 3);
    CHECK(a == b);
    CHECK_FALSE(a == C);
}

TEST_CASE("NOT_EQUAL") {
    Fraction a(1, 2);
    Fraction b(1, 3);
    CHECK(a != b);
}

TEST_CASE("GREATER") {
    Fraction a(1, 2);
    Fraction b(1, 3);
    CHECK(a > b);
    CHECK_FALSE(b > a);
}

TEST_CASE("LESS") {
    Fraction a(1, 2);
    Fraction b(1, 3);
    CHECK(b < a);
}

TEST_CASE("GREATER_EQUAL") {
    Fraction a(1, 2);
    Fraction b(1, 3);
    CHECK(a >= b);
    CHECK_FALSE(b >= a);
    float f = 1.1;
    CHECK_FALSE(a >= f);
    CHECK(f >= a);
}

TEST_CASE("LESS_EQUAL") {
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction c(2, 1);
    float f = 1.1;
    CHECK(a <= f);
    CHECK_FALSE(a <= b);
    CHECK(f <= c);
}

TEST_CASE("++") {
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction C = a++;
    CHECK(C == Fraction(1, 2));
    CHECK(a == Fraction(3, 2));
    C = ++a;
    CHECK(C == Fraction(5, 2));
    CHECK(a == Fraction(5, 2));
}

TEST_CASE("--") {
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction C = a--;
    CHECK(C == Fraction(1, 2));
    CHECK(a == Fraction(-1, 2));
    C = --a;
    CHECK(C == Fraction(-3, 2));
    CHECK(a == Fraction(-3, 2));


}

TEST_CASE("<<")
{
    std::ostringstream output;
    Fraction a(1, 2);
    output << a;
    CHECK(output.str() == "1/2");

}

TEST_CASE(">>")
{
    std::istringstream input("1/2");
    Fraction a(1, 2);
    input >> a;
    CHECK(a == Fraction(1, 2));
}

TEST_CASE("Float")
{
    Fraction a(0.5);
    CHECK(a == Fraction(1, 2));
    CHECK(a.getDenominator()==2);
    CHECK(a.getNumerator()==1);
    Fraction b(0.10002);
    CHECK(b == Fraction(1, 10));
    CHECK(b.getDenominator()==10);
    CHECK(b.getNumerator()==1);

}

TEST_CASE("Reduce"){
    Fraction a(2,4);
    CHECK(a.getNumerator()==1);
    CHECK(a.getDenominator()==2);
    Fraction b(0.00000001);
    CHECK(b.getNumerator()==0);
    CHECK(a.getDenominator()==1);
}

TEST_CASE("Negative"){
    Fraction a(-1,2);
    CHECK(a.getNumerator()==-1);
    CHECK(a.getDenominator()==2);
    Fraction b(1,-2);
    CHECK(b.getNumerator()==-1);
    CHECK(b.getDenominator()==2);
    Fraction c(-1,-2);
    CHECK(c.getNumerator()==1);
    CHECK(c.getDenominator()==2);
}