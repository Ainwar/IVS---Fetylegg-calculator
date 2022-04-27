#ifndef _MATHLIB_H_
#define _MATHLIB_H_
#include<string>

class MathFtion
{
    public:
        std::string inputFtion(std::string text);

        //solving algorithm function
        std::string sorter(std::string text);
        std::string solver(std::string text); 
        double mathCaller(double numberOne, double numberTwo, char solvingSign);
   

        //test functions
        bool validTest(std::string text);
        bool brackeysTest(std::string text);
        bool brackeysSubTest(std::string text);
        bool signsTest(std::string text);

        //Support functions
        std::string zeroErase(std::string text);
        std::string signRepair(std::string text);
        std::string cleaner(std::string text);
        std::string rootSwitch(std::string text);
        std::string reverseParse(double answer);
        double parseFtion(std::string text);
        int findChar(std::string test, char lookFor, int option = 1, int position = 0);
        int backFindChar(std::string text, char lookFor, int lastPos);
        int numberFinder(std::string text, int signPosition, int option = 0);
        char sign(std::string text, int*position);
        

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
