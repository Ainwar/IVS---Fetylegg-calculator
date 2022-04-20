#ifndef _MATHLIB_H_
#define _MATHLIB_H_

class MathFtion
{
    public:
        string inputFtion(string* text);
    private:

        //solving algorithm function
        string sorter(string text);
        string solver(string text); //TODO fill solver and sorter function
        double mathCaller(string text); //DONE

        //test functions
        string validTest(string text);
        bool brackeysTest(string text);
        bool brackeysSubTest(string text);
        bool signsTest(string text);
        bool nthRootTest(string text);
        //TODO signs test function
        //TODO nthRootTest function

        //Support functions
        string cleaner(string text); //DONE
        int findChar(string test, char lookFor, int option = 1); //DONE
        int backFindChar(string text, char lookFor, int lastPos); //DONE
        int numberFinder(string text, int signPosition, int option = 0); //DONE
        char sign(string text); //DONE

        //functions
        double plusF(double a, double b);
        double multiplication(double a, double b);
        double dividing(double a, double b);
        double power(double a, int b = 2);
        double nthRoot(double a, int b) = 2;
        double factorial(double a);
        double negation(double a);
};        

#endif