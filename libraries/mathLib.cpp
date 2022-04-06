#include<iostream>
#include<string>
#include "mathLib.h"
#include<algorithm>

#define MINUSONE -1 //Negation number/empty return value
#define FAIL "You inserted wrong equation: "
#define SPACE 32 //ASCII value of space
#define LEFTBRACKEY 40 //ASCII value of (
#define RIGHTBRACKEY 41 //ASCII value of )
#define OPTIONONE 1 //for functions which needs option choice
#define OPTIONTWO 2 //for functions which needs option choice

/**
 * @brief 
 * TODO
 * @param text 
 * @return string 
 */

string MathFtion::inputFtion(string text){
    string output;
    if(validTest(text)){
        return text;
    }
    output = sorter(&text);
    return output;
}

/**
 * @brief 
 * TODO
 * @param text 
 * @return string 
 */

string MathFtion::sorter(string text){
    int firBrack = text.
    int lastBrak 
    if(){
        sorter(substr());
    }
    else{
        text = cleaner(text);
        text = solver(text); 
    }
    return text;
}

/**
 * @brief 
 * TODO
 * @param text 
 * @return string 
 */

string MathFtion::solver(string text){
    
    return text;
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
 * TODO test if brackys match one to another like (()()) and not like )))(((
 * @param text tested text
 * @return true if brackeys don't match
 * @return false if brackeys match or there they aren't there
 */

bool MathFtion::brackeysTest(string text){
    int left = findChar(text, LEFTBRACKEY, OPTIONTWO);
    int right = findChar(text, RIGHTBRACKEY, OPTIONTWO);
    if((left != NEGATIVEONE) || (right != NEGATIVEONE)){
        if(left == right){
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
    for(int i = lastPos; i > 0; i--){
        if(test[i] == lookFor){
            return i;
        }
    }
    return MINUSONE;
}

/**
 * @brief sum of a and b
 * @param a
 * @param b
 * @return sum
 */

double MathFtion::plus(double a, double b){
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
double MathFtion::square(double a, int b = 2){
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
*/
double MathFtion::nthRoot(double a, int b){
    float result;
    
    //*condition for calculating root
    if (a < 0){
        cerr << "Cannot calculate root of negative number!" << endl;
        return 0; //TODO Solve return value
    }

    if (x == 0 || x == 1){ //TODO Repair meaning of [x]? undefined (Alan)
        return x;
    }
    
    
        
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