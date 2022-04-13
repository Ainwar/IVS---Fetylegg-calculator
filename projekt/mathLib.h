#ifndef _MATHLIB_H_
#define _MATHLIB_H_

#include <string>

class MathFtion
{
    public:
        int ans = 0;
        std::string inputFtion(std::string* text);
    //private:

        //solving algorithm function
        std::string sorter(std::string text);
        std::string solver(std::string text); //TODO fill solver and sorter function

        //test functions
        std::string validTest(std::string text);
        bool brackeysTest(std::string text);
        bool brackeysSubTest(std::string text);
        bool signsTest(std::string text);
        bool nthRootTest(std::string text);
        //TODO signs test function
        //TODO nthRootTest function

        //Support functions
        std::string cleaner(std::string text);
        int findChar(std::string test, char lookFor, int option);
        int backFindChar(std::string text, char lookFor, int lastPos);

        //functions
        double plus(double a, double b); // ✓
        double multiplication(double a, double b); // ✓
        double dividing(double a, double b); // ✓
        double square(double a); // ✓
        double power(double a, int b); // ✓
        double nthRoot(double a, int b);
        double factorial(double a); // ✓
        double negation(double a); // ✓
        //TODO optional change to pointer parametres
};        

#endif