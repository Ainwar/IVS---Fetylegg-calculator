#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "mathLib.h"

MathFtion math;

// Tests for plus function
TEST(AdditionTest, positive) {
    EXPECT_EQ(math.plusF(3,4),7);
    EXPECT_EQ(math.plusF(4,0),4);
    EXPECT_EQ(math.plusF(3452, 584),4036);
}

TEST(AdditionTest, negative) {
    EXPECT_EQ(math.plusF(-3,4),1);
    EXPECT_EQ(math.plusF(-3,-7),-10);
    EXPECT_EQ(math.plusF(-3452, 3946),494);
}

TEST(AdditionTest, decimal) {
    EXPECT_EQ(math.plusF(0.45,3.11),3.56);
    EXPECT_EQ(math.plusF(-5.125,9.555),4.43);
    EXPECT_EQ(math.plusF(513.552,921.9948),1435.5468);
}

// Tests for multiplication fuction

TEST(MultiplicationTest, positive) {
    EXPECT_EQ(math.multiplication(3,4),12);
    EXPECT_EQ(math.multiplication(9,0),0);
    EXPECT_EQ(math.multiplication(1341,234),313794);
}

TEST(MultiplicationTest, negative) {
    EXPECT_EQ(math.multiplication(-3,4),-12);
    EXPECT_EQ(math.multiplication(-3,-6),18);
    EXPECT_EQ(math.multiplication(-234,85),-19890);
}

TEST(MultiplicationTest, decimal) {
    EXPECT_EQ(math.multiplication(4.55,0.4505),2.049775);
    EXPECT_EQ(math.multiplication(-0.35,5.125),-1.79375);
    EXPECT_EQ(math.multiplication(-234.129,-45.305),10607.214345);
}

// Tests for dividing function

TEST(DividingTest, positive) {
    EXPECT_EQ(math.dividing(6,2),3);
    EXPECT_EQ(math.dividing(20,5),4);
}

TEST(DividingTest, negative) {
    EXPECT_EQ(math.dividing(-15,3),-5);
    EXPECT_EQ(math.dividing(30,-6),-5);
    EXPECT_EQ(math.dividing(-60,-20),3);
}

TEST(DividingTest, decimal) {
    EXPECT_EQ(math.dividing(0.125,5),0.025);
    EXPECT_EQ(math.dividing(0.1,-0.5),-0.2);
}

// Tests for power function without second parameter

TEST(PowerTest_WithoutSecondParameter, positive) {
    EXPECT_EQ(math.power(4),16);
    EXPECT_EQ(math.power(0),0);
    EXPECT_EQ(math.power(125),15625);
}

TEST(SquareTest, negative) {
    EXPECT_EQ(math.power(-2),4);
    EXPECT_EQ(math.power(-8),64);
}

TEST(SquareTest, decimal) {
    EXPECT_EQ(math.power(0.125),0.015625);
    EXPECT_EQ(math.power(1.5),2.25);
    EXPECT_EQ(math.power(-5.5),30.25);
}

// Tests for power function with second parameter

TEST(PowerTest_WithSecondParameter, positive) {
    EXPECT_EQ(math.power(3,3),27);
    EXPECT_EQ(math.power(2,6),64);
    EXPECT_EQ(math.power(1,0),1);
    EXPECT_EQ(math.power(2,2),4);
}

TEST(PowerTest_WithSecondParameter, negative) {
    EXPECT_EQ(math.power(-2,3),-8);
    EXPECT_EQ(math.power(-1,4),1);
    EXPECT_EQ(math.power(-2,6),64);
    EXPECT_EQ(math.power(-42,0),1);
}

TEST(PowerTest_WithSecondParameter, decimal) {
    EXPECT_EQ(math.power(0.5,3),0.125);
    EXPECT_EQ(math.power(-0.5,3),-0.125);
    EXPECT_EQ(math.power(-0.5,4),0.0625);
}

// Tests for nthRoot function without second parameter

TEST(nthRootTest_WithoutSecondParameter, positive) {
    EXPECT_EQ(math.nthRoot(9),3);
    EXPECT_EQ(math.nthRoot(16),4);
    EXPECT_EQ(math.nthRoot(6400),80);
    EXPECT_EQ(math.nthRoot(0),0);
}

// Tests for nthRoot function with second parameter

TEST(nthRootTest_WithSecondParameter, positive) {
    EXPECT_EQ(math.nthRoot(27,3),3);
    EXPECT_EQ(math.nthRoot(8,3),2);
    EXPECT_EQ(math.nthRoot(0,4),0);
}

// Tests for factorial function

TEST(FactorialTest, positive) {
    EXPECT_EQ(math.factorial(1),1);
    EXPECT_EQ(math.factorial(0),1);
    EXPECT_EQ(math.factorial(5),120);
}

// Tests for negation function

TEST(NegationTest, integer) {
    EXPECT_EQ(math.negation(0),0);
    EXPECT_EQ(math.negation(5),-5);
    EXPECT_EQ(math.negation(-5),5);
}

TEST(NegationTest, decimal) {
    EXPECT_EQ(math.negation(0.125),-0.125);
    EXPECT_EQ(math.negation(-0.125),0.125);
}

// Tests for equations

TEST(EquationTest, Equation) {
    EXPECT_EQ(math.inputFtion("3+2*4"), "11"); // preslo
    EXPECT_EQ(math.inputFtion("5/5+6*6"), "37"); // preslo
    EXPECT_EQ(math.inputFtion("√9"), "3"); // √9
    EXPECT_EQ(math.inputFtion("3!+4*(3+3)"), "30"); // you inserted wrong equation ...
    EXPECT_EQ(math.inputFtion("24/4*2+(3+7)*2"), "23"); // preslo
    EXPECT_EQ(math.inputFtion("3-2+(-3*3)-1"), "-9"); // preslo
    EXPECT_EQ(math.inputFtion("3!!-20"), "700"); // you inserted wrong equation ...
    EXPECT_EQ(math.inputFtion("3^2+11+2^3"), "28"); //preslo
    EXPECT_EQ(math.inputFtion("2*(3√27)"), "6"); // 6√27
    EXPECT_EQ(math.inputFtion("10/0.01-1000"), "0"); // preslo
    EXPECT_EQ(math.inputFtion("(3√27)*2+2"), "8");
    EXPECT_EQ(math.inputFtion("-3.605/4.225"), "-0.8532544379");
}

// Tests for decimal equations

TEST(EquationTest, Equation_decimal) {
    EXPECT_EQ(math.inputFtion("0.1+0.3*2-0.2/2+0.4"), "1");
    EXPECT_EQ(math.inputFtion("1.5^2+3.32"),"5.57");
    EXPECT_EQ(math.inputFtion("√(6-2)*0.1"),"0.2");
}

TEST(EquationTest, Errors) {
    EXPECT_EQ(math.inputFtion("3--"), "You inserted wrong equation: 3--");
    EXPECT_EQ(math.inputFtion("3++"), "You inserted wrong equation: 3++");
    EXPECT_EQ(math.inputFtion("3*-"), "You inserted wrong equation: 3*-");
    EXPECT_EQ(math.inputFtion("3*+"), "You inserted wrong equation: 3*+");
    EXPECT_EQ(math.inputFtion("3-*"), "You inserted wrong equation: 3-*");
    EXPECT_EQ(math.inputFtion("3+-"), "You inserted wrong equation: 3+-");
}

// Tests for wrong inputs

TEST(EquationTest, Errors_2) {
    EXPECT_EQ(math.inputFtion("3+5/0"), "You inserted wrong equation: 3+5/0");
    EXPECT_EQ(math.inputFtion("-1!+2"), "You inserted wrong equation: -1!+2");
    EXPECT_EQ(math.inputFtion("0.5!+10"), "You inserted wrong equation: 0.5!+10");
    EXPECT_EQ(math.inputFtion("2^-1"), "You inserted wrong equation: 2^-1");
    EXPECT_EQ(math.inputFtion("2^0.5"), "You inserted wrong equation: 2^0.5");
    EXPECT_EQ(math.inputFtion("-2√4"), "You inserted wrong equation: -2√4");
    EXPECT_EQ(math.inputFtion("√-2"), "You inserted wrong equation: √-2");
    EXPECT_EQ(math.inputFtion("3+(-2√4)"), "You inserted wrong equation: 3+(-2√4)");
}

// Tests for wrong brackets

TEST(EquationTest, Error_Brackets) {
    EXPECT_EQ(math.inputFtion(")3+3)"), "You inserted wrong equation: )3+3)");
    EXPECT_EQ(math.inputFtion("(3*)3-3)"), "You inserted wrong equation: (3*)3-3)");
    EXPECT_EQ(math.inputFtion("))3+3"), "You inserted wrong equation: ))3+3");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
