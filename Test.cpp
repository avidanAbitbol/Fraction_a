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

const int MIN_TESTS = 20;

TEST_CASE("check 0"){
    CHECK_THROWS(Fraction (1,0));
    CHECK_NOTHROW(Fraction (1,2));
}

TEST_CASE("getters"){
    Fraction a(1,2);
    CHECK_EQ(a.getNumerator(),1);
    CHECK_EQ(a.getDenominator(),2);
}

TEST_CASE("opreators+"){
    Fraction a(1,2);
    Fraction b(1,3);
    CHECK_EQ(a+b,Fraction(5,6));
}
TEST_CASE("opreators-") {
    Fraction a(1, 2);
    Fraction b(1, 3);
    CHECK_EQ(a - b, Fraction(1, 6));
}
TEST_CASE("opreators*"){
    Fraction a(1,2);
    Fraction b(1,3);
    CHECK_EQ(a*b,Fraction(1,6));
    CHECK_EQ(a/b,Fraction(3,2));
}
TEST_CASE("opreators/"){
    Fraction a(1,2);
    Fraction b(1,3);
    CHECK_EQ(a/b,Fraction(3,2));
}
TEST_CASE("opreators++"){
    Fraction a(1,2);
    CHECK_EQ(a++,Fraction(1,2));
    CHECK_EQ(a,Fraction(3,2));
}
TEST_CASE("opreators--"){
    Fraction a(1,2);
    CHECK_EQ(--a,Fraction(-1,2));
    CHECK_EQ(a,Fraction(-1,2));
}
TEST_CASE("opreators=="){
    Fraction a(1,2);
    Fraction b(1,3);
    Fraction c( 3.1234);
    CHECK_EQ(a==b,false);
    CHECK_EQ(a==Fraction(1,2),true);
    CHECK_EQ(b==Fraction(1,3) ,true);
    CHECK_EQ(b==Fraction(1,2),false);
    CHECK_EQ(a==Fraction(1,3) ,false);
    CHECK_EQ(c==Fraction(3.67891) , false);
    CHECK_EQ(c==Fraction(3.1234) ,true);

}

TEST_CASE("opreators<"){
    Fraction a(1,2);
    Fraction b(1,3);
    CHECK_EQ(a<b,false);
    CHECK_EQ(a<Fraction(1,2),false);
    CHECK_EQ(b<Fraction(1,3) ,false);
    CHECK_EQ(b<Fraction(1,2),true);
    CHECK_EQ(a<Fraction(1,3) ,false);
}

TEST_CASE("opreators>"){
    Fraction a(1,2);
    Fraction b(1,3);
    CHECK_EQ(a>b,true);
    CHECK_EQ(a>Fraction(1,2),false);
    CHECK_EQ(b>Fraction(1,3) ,false);
    CHECK_EQ(b>Fraction(1,2),false);
    CHECK_EQ(b>Fraction(1,4),true);
    CHECK_EQ(a>Fraction(1,3) ,true);
}

TEST_CASE("opreators<="){
    Fraction a(1,2);
    Fraction b(1,3);
    CHECK_EQ(a<=b,false);
    CHECK_EQ(a<=Fraction(1,2),true);
    CHECK_EQ(b<=Fraction(1,3) ,true);
    CHECK_EQ(b<=Fraction(1,2),true);
    CHECK_EQ(a<=Fraction(1,3) ,false);
}

TEST_CASE("opreators>="){
    Fraction a(1,2);
    Fraction b(1,3);
    CHECK_EQ(a>=b,true);
    CHECK_EQ(a>=Fraction(1,2),true);
    CHECK_EQ(b>=Fraction(1,3) ,true);
    CHECK_EQ(b>=Fraction(1,2),false);
    CHECK_EQ(a>=Fraction(1,3) ,true);
}

TEST_CASE("opreators!="){
    Fraction a(1,2);
    Fraction b(1,3);
    CHECK_EQ(a!=b,true);
    CHECK_EQ(a!=Fraction(1,2),false);
    CHECK_EQ(b!=Fraction(1,3) ,false);
    CHECK_EQ(b!=Fraction(1,2),true);
    CHECK_EQ(a!=Fraction(1,3) ,true);
}

TEST_CASE("operator/ divide with 0"){
    Fraction a(1,2);
    CHECK_THROWS(a/0);
    CHECK_THROWS(a/0.0);
    CHECK_THROWS(a/0.0f);
}

TEST_CASE("oprators with negative values +-*/") {
    Fraction a(-1, 2);
    Fraction b(1, -3);
    CHECK_EQ(a - b, Fraction(-1, 6));
    CHECK_EQ(a + b, Fraction(-5, 6));
    CHECK_EQ(a * b, Fraction(1, 6));
    CHECK_EQ(a / b, Fraction(3, 2));
}
    TEST_CASE("oprators with negative values ==><") {
    Fraction a(-1, 2);
    Fraction b(1, -3);
    CHECK_EQ(a == b, false);
    CHECK_EQ(a == Fraction(-1, 2), true);
    CHECK_EQ(b == Fraction(1, -3), true);
    CHECK_EQ(b == Fraction(-1, 2), false);
    CHECK_EQ(a == Fraction(1, -3), false);
    CHECK_EQ(a < b, true);
    CHECK_EQ(a < Fraction(-1, 2), false);
    CHECK_EQ(b < Fraction(1, -3), false);
    CHECK_EQ(b < Fraction(-1, 2), false);
    CHECK_EQ(a < Fraction(1, -3), true);
    CHECK_EQ(a > b, false);
    CHECK_EQ(a > Fraction(-1, 2), false);
    CHECK_EQ(b > Fraction(1, -3), false);
    CHECK_EQ(b > Fraction(-1, 2), true);
    CHECK_EQ(b > Fraction(1, -4), false);
    CHECK_EQ(a > Fraction(1, -3), false);
}
    TEST_CASE("oprators with negative values <=") {
    Fraction a(-1, 2);
    Fraction b(1, -3);
    CHECK_EQ(a <= b, true);
    CHECK_EQ(a <= Fraction(-1, 2), true);
    CHECK_EQ(b <= Fraction(1, -3), true);
    CHECK_EQ(b <= Fraction(-1, 2), false);
    CHECK_EQ(a <= Fraction(1, -3), true);
}
TEST_CASE("oprators with negative values =>") {
    Fraction a(-1, 2);
    Fraction b(1, -3);
    CHECK_EQ(a >= b, false);
    CHECK_EQ(a >= Fraction(-1, 2), true);
    CHECK_EQ(b >= Fraction(1, -3), true);
    CHECK_EQ(b >= Fraction(-1, 2), true);
    CHECK_EQ(a >= Fraction(1, -3), false);
}
TEST_CASE("oprators with negative values !=") {
    Fraction a(-1, 2);
    Fraction b(1, -3);
    CHECK_EQ(a != b, true);
    CHECK_EQ(a != Fraction(-1, 2), false);
    CHECK_EQ(b != Fraction(1, -3), false);
    CHECK_EQ(b != Fraction(-1, 2), true);
    CHECK_EQ(a != Fraction(1, -3), true);
}
TEST_CASE("demo test"){
    Fraction a(5,3), b(14,21);
    CHECK_EQ(a+b,Fraction(7,3));
    CHECK_EQ(a-b,Fraction(1,1));
    CHECK_EQ(a*b,Fraction(70,63));
    CHECK_EQ(a/b,Fraction(5,2));
    CHECK_EQ(2.3*b,Fraction(4,3));
    CHECK_EQ(a+2.421,Fraction(10399,2544));
    Fraction c = a+b-1;
    CHECK_EQ(c++,Fraction(4,3));
    CHECK_EQ(--c,Fraction(4,3));
    CHECK_EQ(c >= b , true);

}

