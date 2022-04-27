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
#define SIGNS "!?^*/-+" //Signs for searching cycle
#define ONESTEP 1 //adding value to cycles or functions 
#define TESTMODE "test mode" //Password for testing mode
#define CHARFAIL 35 //Value for return from function that inform about missing signs 
#define ROOTSUBSTITUTE 63 //substitute for root
#define ROOTSIGN "√" //actual root sign in string

using namespace std;

/**
 * @brief public function to control private functios
 * @param text equation
 * @return string answer
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
 * @brief sort out equation in brackeys, solve them, return them into equation
 * @param text equation
 * @return string asnwer
 */

string MathFtion::sorter(string text){
    int firBrack, secBrack, brackeys;
    string tempLeft, tempRight, tempCount;
    brackeys = findChar(text, LEFTBRACKEY, 2);
    while(brackeys){
        firBrack = backFindChar(text, LEFTBRACKEY, text.length());
        secBrack = findChar(text, RIGHTBRACKEY,1,firBrack);
        if(firBrack != 0){
            tempLeft = text.substr(0,firBrack);
        }
        else{
            tempLeft = ' ';
        }
        if(secBrack != text.length()){
            tempRight = text.substr((secBrack+ONESTEP),(text.length() - secBrack));
        }
        else{
            tempRight = ' ';
        }
        tempCount = solver(text.substr(firBrack+ONESTEP, (secBrack - firBrack - ONESTEP)));
        text = cleaner(tempLeft+tempCount+tempRight);
        brackeys--;
    }   
    return solver(text);
}

/**
 * @brief solving equation
 * @param text equation
 * @return string asnwer
 * @return string FAIL if after reduction of signs 
 */

string MathFtion::solver(string text){
    
    string tempCount, tempLeft, tempRight;
    int negFir = 0, negSec = 0;
    char solvingSign = '+';
    double numberOne, numberTwo;
    int signPosition, numberOnePosition, numberTwoPosition;
    text = signRepair(text);
    if(signsTest(text)){
        return FAIL;
    }
    while((solvingSign = sign(text, &signPosition)) != CHARFAIL){
        numberOnePosition = numberFinder(text, signPosition, OPTIONONE);
        if(numberOnePosition != 0 && text[numberOnePosition-ONESTEP] == '-' && solvingSign != '!'){
            text.erase(numberOnePosition-ONESTEP,ONESTEP);
            numberOnePosition--;
            signPosition--;
            negFir = 1;
        }
        if(numberOnePosition == ONESTEP && text[0] == '+'){
            text.erase(0, ONESTEP);
            numberOnePosition--;
            signPosition--;
        }
        if(numberOnePosition != 0){
                tempLeft = text.substr(0, numberOnePosition);

            }
        else{
                tempLeft = ' ';
        }
        numberOne = stod(text.substr(numberOnePosition, (signPosition-numberOnePosition)));
        if(negFir){
            numberOne = negation(numberOne);
        }

        if(solvingSign != '!'){
            if(text[signPosition+ONESTEP] == '-'){
                text.erase(signPosition+ONESTEP, ONESTEP);
                negSec = 1;
            }
            if(text[signPosition+ONESTEP] == '+'){
                text.erase(signPosition+ONESTEP,ONESTEP);
            }
            numberTwoPosition = numberFinder(text, signPosition);
            numberTwo = stod(text.substr((signPosition+ONESTEP), (numberTwoPosition-signPosition)));
            if(negSec){
                numberTwo = negation(numberTwo);
            }
            tempCount = to_string(mathCaller(numberOne, numberTwo, solvingSign));
            
            if(numberTwoPosition != text.length()){
                tempRight = text.substr(numberTwoPosition+1,(text.length()-numberTwoPosition));
            }
            else{
                tempRight = ' ';
            }
            text = tempLeft+tempCount+tempRight;
            
        }
        else{
            if((signPosition+ONESTEP) < text.length()){
                tempRight = text.substr((signPosition+ONESTEP), text.length());
            }
            else{
                tempRight = ' ';
            }
            tempCount = to_string(mathCaller(numberOne,0,solvingSign));
            text = tempLeft+tempCount+tempRight;

        }
        text = cleaner(text);
        text = signRepair(text);
        negFir = 0;
        negSec = 0;
    }
    return text;
}

/**
 * @brief get rid off excess plus and minus
 * @param text equation
 * @return repaired equation
 */

string MathFtion::signRepair(string text){
    char lastChar = text[0];
    int counter = 0;
    for(int i = 0; i < text.length(); i++){
        cout << text << endl;
        if(lastChar == text[i]){
            counter++;
            if(counter == 2){
                switch(lastChar){
                    case '-':
                        text.erase(i,ONESTEP);
                        text[i-ONESTEP] = '+';
                        i -= ONESTEP;
                        lastChar = text[i];
                        counter = 1;
                        break;

                    case '+':
                        text.erase(i,1);
                        i -= 1; 
                        lastChar = text[i];
                        counter = 1;
                        break;

                    default:
                        continue;
                        break;
                }
            }
        }
        else{
            if(lastChar == '+' && text[i] == '-'){
                text.erase(i-ONESTEP, ONESTEP);
                i--;
            }
            if(lastChar == '-' && text[i] == '+'){
                text.erase(i, ONESTEP);
                i--;
            }
            counter = 1;
            lastChar = text[i];
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
        case ROOTSUBSTITUTE: 
            return nthRoot(numberTwo, (int)numberOne);
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
 * @brief test logic of equation
 * @param text equation
 * @return true unsuccessful test
 * @return false successful test
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
    if((left != MINUSONE) || (right != MINUSONE)){
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
 * @return true unsuccessful test
 * @return false successful
 */

bool MathFtion::brackeysSubTest(string text){
    int right = backFindChar(text, RIGHTBRACKEY, text.length());
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
 * @brief tests if arithmetic operators are not repeating one after another
 * @param text equation
 * @return true as unsuccessful test
 * @return false as successful test
 */
bool MathFtion::signsTest(string text){

    for(int i = 0; i < text.length(); i++){

        if (text[i] == ('^') || text[i] == (ROOTSUBSTITUTE) || text[i] == ('*') || text[i] == ('/') ){
            if (text[i+1] == ('^') || text[i+1] == (ROOTSUBSTITUTE) || text[i+1] == ('*') || text[i+1] == ('/') ) {
                return true;
            }
        }
    }
    return false;
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
 * @brief si
 * @param
 * @return
*/
string roootSwitch(string text){
    char newSign = ROOTSUBSTITUTE;
    int position = 0;
    string rootSign = ROOTSIGN;
    while((position = text.find(rootSign)) != MINUSONE){
        text.erase(position+1, (rootSign.length()-MINUSONE));
        text[position] = newSign;
    }
    return text;
}

/**
 * @brief looking for character from the beggining or counting exact character in equation
 * @param text equation
 * @param lookFor character user of function looking for
 * @param option 1 = position finder / 2 = counter
 * @param position can be send startion position, default = 0;
 * @return position of character/sum of exact character/empty value
 */

int MathFtion::findChar(string text, char lookFor, int option, int position){
    int counter = 0;
    for(int i = position; i < text.length(); i++){
        if(text[i] == lookFor){
            if(option = 1){
                return i;
            }
            else{
                counter++; 
            }
        }
    }
    if(option == 2){
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
        if(text[i] == lookFor){
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
 * @param position pointer on signPosition
 * @return char sign
 * @return send position of solving sign throught pointer
 */

char MathFtion::sign(string text, int*position){
    string signsConst = SIGNS;
    string numberConst = NUMBERS;
    int actualPos, numPos = text.length();
    for(int j = 0; j < numberConst.length(); j++){
        actualPos = text.find(numberConst[j]);
        if(actualPos >= 0 && numPos > actualPos ){
            numPos = actualPos; 
        }
    }
    
    for(int i = 0; i < signsConst.length(); i++){
        for(int k = numPos; k < text.length(); k++){
            if(text[k] == signsConst[i]){
                *position = k;
                return text[k];
            }
        }
    }
    return CHARFAIL;
}

/**
 * @brief sum of a and b
 * @param a number one
 * @param b number two
 * @return answer
 */

double MathFtion::plusF(double a, double b){
    return a + b;
}

/**
 * multiplication of a and b
 * @param a number one
 * @param b number two
 * @return answer
*/

double MathFtion::multiplication(double a, double b){
    return a * b;
}

/**
 * @brief Quotient of a and b
 * @param a number one
 * @param b number two
 * @return answer
*/
double MathFtion::dividing(double a, double b){
    if(b != 0){
        return a / b;
    } else {
        cerr << "Cannot divide by 0!" << endl;
        return 0;
    }
}

/**
 * @brief Multipllication of same number numeros times.  
 * @param a number to multiplie
 * @param b how many times is gonna multiple. Square is based if its not defined
 * @param c to archive [a] for future multiplication
 * @return answer
 */
double MathFtion::power(double a, int b){
    if(b == 0){
        return 1;
    }
    else if(b == 1){
        return a;
    }
    else{
        int c = a;
        for(int i = 1; i < b; i++)
            a = a*c;
    
        return a;
    }
}

/**
 * @brief nthRoot of a, where level of root is decided by value of b
 * @param a number under root sign 
 * @param b number of root
 * @return answer
*/
double MathFtion::nthRoot(double a, int b){
    double result;
    
    //*condition for calculating root
    if (a < 0){
        fprintf(stderr, "Cannot calculate root of negative number!");
        return 0;
    }

    if (a == 0 || a == 1){
        return a;
    }
    
    // calculation of nth root
    result = pow(a, 1/b);
    return result;
        
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