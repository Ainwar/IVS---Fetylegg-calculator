#ifndef _MATHLIB_H_
#define _MATHLIB_H_

class MathFtion
{
    public:
        int ans = 0;
        string inputFtion(string* text);
    private:

        //solving algorithm function
        string sorter(string text);
        string solver(string text); //TODO fill solver and sorter function

        //test functions
        string validTest(string text);
        bool brackeysTest(string text);
        bool signsTest(string text);
        //TODO signs test function

        //Support functions
        string cleaner(string text);
        int findChar(string test, char lookFor, int option);
        int backFindChar(string text, char lookFor, int lastPos);

        //functions
        double plus(double a, double b);
        double multiplication(double a, double b);
        double dividing(double a, double b);
        double square(double a, int b = 2);
        double nthRoot(double a, int b);
        double factorial(double a);
        double negation(double a);
        //TODO optionl change to pointer parametres
};        

#endif