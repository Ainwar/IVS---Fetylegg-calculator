#include<iostream>
#include<string>
#include<math.h>
#include "mathLib.h"
#include<algorithm>

#define MINUSONE -1 //Negation number/empty return value
#define FAIL "You inserted wrong equation: " //
#define SPACE 32 //ASCII value of space
#define LEFTBRACKEY 40 //ASCII value of (
#define RIGHTBRACKEY 41 //ASCII value of )
#define OPTIONZERO 0 //for functions which needs option choice
#define OPTIONONE 1 //for functions which needs option choice
#define OPTIONTWO 2 //for functions which needs option choice
#define NUMBERS "0123456789." //Numbers for parsing
#define SIGNS "!√^*/-+" //Signs for searching cycle
#define ONESTEP 1 //adding value to cycles or functions 
#define TESTMODE "test mode" //Password for testing mode
#define CHARFAIL 63 //Value for return from function that inform about missing signs 

/**
 * @brief 
 * TODO
 * @param text 
 * @return string 
 */

string MathFtion::inputFtion(string text){
    text = cleaner(text);
    if(validTest(text)){
        return text;
    }
    text = sorter(text);
    return text;
}

/**
 * @brief 
 * TODO
 * @param text 
 * @return string 
 */

string MathFtion::sorter(string text){
    int firBrack,secBrack; 
    text = cleaner(text)
    while(brackeysTest(test)){
            text.replace(firBrack, lastBrack,(sorter(text.substr(firBrack, (firBrack - secBrack))));
    }
    return solver(text);
}

/**
 * @brief 
 * @param text 
 * @return string 
 */

string MathFtion::solver(string text){
    
    string tempCount;
    char solvingSigns = '+';
    double numberOne, numberTwo
    int signPosition, numberOnePosition, numberTwoPosition;

    while(solvingSign = sign(text) != CHARFAIL){

        signPosition = findChar(text, solvingSign);
        numberOnePosition = numberFinder(text, signPosition, OPTIONONE);
        numberOne =  stod(text.substr(numberOnePosition, signPosition));

        if(solvingSign != '!'){
            numberTwoPosition = numberFinder(text, signPosition);
            numberTwo = stod(text.substr((signPosition+ONESTEP), (numberTwoPosition-signPosition)));
            tempCount = to_string(mathCaller(numberOne, numberTwo, solvingSign));
            text.replace(numberOnePosition, (numberTwoPosition - numberOnePosition + ONESTEP), tempCount);
        }
        else{
            tempCount = to_string(mathCaller(numberOne,OPTIONZERO ,solvingSign));
            text.replace(numberOnePosition, (tempCount.length()+ONESTEP), tempCount);
        }
    }
    return text;
}

/**
 * @brief choose function which is gonna be called
 * @param numberOne first number 
 * @param numberTwo second number
 * @param solvingSign sign for solving
 * @return double functions
 */

double MathFtion::mathCaller(double numberOne, double numberTwo, char solvingSign){
    switch(solvingSign){
        case '!':
            return factorial(numberOne);
            break;
        case '√': 
            return nthRoot(numberOne, (int)numberTwo)
            break;
        case '^':
            return power(numberOne, (int)numberTwo);
            break;
        case '*':
            return multiplication(numberOne, numberTwo);
            break;
        case '/':
            return dividing(numberOne, numberTwo);
            break;
        case '-':
            return plusF(numberOne, negation(numberTwo));
            break;
        case '+':
            return plusF(numberOne, numberTwo);
            break;
        default:
            return 63;
            break;
    }
}

/**
 * @brief 
 * TODO
 * @param text 
 * @return true 
 * @return false 
 */

bool MathFtion::validTest(string text){
    if(brackeysTest(text)){
        cout << FAIL << "Brackeys unmatch" << endl;
        return true;
    }
    if(signsTest(text)){
        cout << FAIL << "Signs unmatch" << endl;
        return true;
    }
    return false;
}

/**
 * @brief test if brackyes are in equation or not, if they are, it test if their count match each other
 * @param text tested text
 * @return true if brackeys aren't okey
 * @return false if brackeys match or they aren't there
 */

bool MathFtion::brackeysTest(string text){
    int left = findChar(text, LEFTBRACKEY, OPTIONTWO);
    int right = findChar(text, RIGHTBRACKEY, OPTIONTWO);
    if((left != NEGATIVEONE) || (right != NEGATIVEONE)){
        if((left == right) && brackeysSubTest(text)){
            
            return false;
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
}

/**
 * @brief test if brackeys match agains each other 
 * @param text testet equation
 * @return true 
 * @return false 
 */

bool MathFtion::brackeysSubTest(string text){
    int right = backFindChar(text, RIGHTBRACKEY, text.lenght());
    if(right == MINUSONE){
        return true;
    }
    int left = backFindChar(text, LEFTBRACKEY, right);
    if(left == MINUSONE){
        return false;
    }
    text[left] = SPACE;
    text[right] = SPACE;
    text = cleaner(text);
    return brackeysSubTest(text);
}

/**
 * @brief
 * TODO
 * @param text 
 * @return true 
 * @return false 
 */
bool MathFtion::signsTest(string text){

    return true;
    return false;
}

/**
 * @brief test if every 
 * @param test 
 * @return true 
 * @return false 
 */

bool MathFtion::nthRootTest(string test){

}

/**
 * @brief remove white all whitespaces from string
 * @param text which user of function want to clear from whitespaces
 * @return string text cleaned from whitespaces
 */

string MathFtion::cleaner(string text){
    text.erase(remove(text.begin(), text.end(), SPACE), text.end());
    return text;
}

/**
 * @brief looking for character from the beggining or counting exact character in equation
 * @param text equation
 * @param lookFor character user of function looking for
 * @param option 1 = position finder / 2 = counter
 * @return position of character/sum of exact character/empty value
 */

int MathFtion::findChar(string text, char lookFor, int option){
    int counter = 0;
    for(int i = 0; i < text.lenght(); i++){
        if(text[i] == lookFor){
            if(option = 1){
                return i;
            }
            else{
                counter++; 
            }
        }
    }
    if(choice == 2){
        return counter;
    }
    else{
        return MINUSONE;
    }
}

/**
 * @brief looking for character from the end as default or exact position
 * @param text equation
 * @param lookFor character user of function looking for
 * @param lastPos position frow which cycle start
 * @return position of character/empty value
 */

int MathFtion::backFindChar(string text, char lookFor, int lastPos){
    for(int i = lastPos; i >= 0; i--){
        if(test[i] == lookFor){
            return i;
        }
    }
    return MINUSONE;
}

/**
 * @brief function for finding of begin or end of a number
 * @param text equation
 * @param signPostion position of sign
 * @param option looking from the front as [0] or [1] as looking from the back
 * @return value where number ends
 */

int MathFtion::numberFinder(string text, int signPosition, int option){
    bool changePos = false;
    string numbersConst = NUMBERS;

    if(option){
        for(int i = (signPosition-ONESTEP); i >= 0; i--){
            for(int k = 0; k < numbersConst.length(); k++){
                if(text[i] == numbersConst[k]){
                    changePos = true;
                }    
            }
            if(!changePos){
                return (i+ONESTEP);
            }
            changePos = false;
        }
        return 0;
    }
    else{
        for(int i = (signPosition+ONESTEP); i <= text.length(); i++){
            for(int k = 0; k < numbersConst.length(); k++){
                if(text[i] == numbersConst[k]){
                    changePos = true;
                }
            }
            if(!changePos){
                return (i-ONESTEP);
            }
            changePos = false;
        }
        return text.length();
    }
}

/**
 * @brief function for finding signs
 * @param text equatation
 * @return char sign
 */

char MathFtion::sign(string text){
    string signsConst = SIGNS;

    for(int i = 0; i < signsConst.length(); i++){
        for(int k = 0; k < text.length(); k++){
            if(text[k] == signsConst[i]){
                return text[k];
            }
        }
    }
    return CHARFAIL
}

/**
 * @brief sum of a and b
 * @param a
 * @param b
 * @return sum
 */

double MathFtion::plusF(double a, double b){
    return a + b;
}

/**
 * multiplication of a and b
 * @param a
 * @param b
 * @return multiplication
*/

double MathFtion::multiplication(double a, double b){
    return a * b;
}

/**
 * @brief Quotient of a and b
 * @param a
 * @param b
 * @return quotient
*/

double MathFtion::dividing(double a, double b){
    if(b != 0){
        return a / b;
    } else {
        cerr << "Cannot divide by 0!" << endl;
        return 0; //TODO Solve return value
    }
}

/**
 * @brief Multipllication of same number numeros times.  
 * @param a number to multiplie
 * @param b how many times is gonna multiple. Square is based if its not defined
 * @param c to archive [a] for future multiplication
 * @return 
 */
double MathFtion::power(double a, int b){
    double c = a;
    for(int i = 0; i < b; i++)
        a *= c;
    return a;
}

/**
 * @brief nthRoot of a, where level of root is decided by value of b
 * @param a
 * @param b 
 * @return 
 * TODO look for c++ nthRoot function 
*/
double MathFtion::nthRoot(double a, int b){
    double result;
    
    //*condition for calculating root
    if (a < 0){
        fprintf(stderr, "Cannot calculate root of negative number!");
        return 0; //TODO Solve return value
    }

    if (a == 0 || a == 1){
        return a;
    }
    
    // calculation of nth root
    result = pow(a, 1/b)
    return result
        
}

/**
 * @brief Factorial of number a 
 * @param a number
 * @return factorial of a
 */
double MathFtion::factorial(double a){
    float result = 1;
    for (int i = a; i > 0; i--){
        result =  result * i;
    }
    return result;
}

/**
 * @brief Negate number
 * @param a number to negate
 * @return negate @a
 */
double MathFtion::negation(double a){
    return MINUSONE*a;
}