#ifndef _MATHLIB_H_
#define _MATHLIB_H_

class MathFtion
{
    public:
        std::string inputFtion(std::string* text);

        //solving algorithm function
        std::string sorter(std::string text);
        std::string solver(std::string text); //TODO fill solver and sorter function
        double mathCaller(std::string text); //DONE

        //test functions
        std::string validTest(std::string text);
        bool brackeysTest(std::string text);
        bool brackeysSubTest(std::string text);
        bool signsTest(std::string text);
        bool nthRootTest(std::string text);
        //TODO signs test function
        //TODO nthRootTest function

        //Support functions
        std::string cleaner(std::string text); //DONE
        int findChar(std::string test, char lookFor, int option = 1); //DONE
        int backFindChar(std::string text, char lookFor, int lastPos); //DONE
        int numberFinder(std::string text, int signPosition, int option = 0); //DONE
        char sign(std::string text); //DONE

        //functions
        double plusF(double a, double b); //TESTED
        double multiplication(double a, double b); //TESTED
        double dividing(double a, double b); //TESTED
        double power(double a, int b = 2); 
        double nthRoot(double a, int b = 2);
        double factorial(double a); //TESTED
        double negation(double a); //TESTED
};        

#endif