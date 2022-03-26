#include "mathLib.h"

#define MinusOne -1

/**
 * sum of a and b
 * @param a 
 * @param b
 * @return sum
 */

int MathFtion::plus(int a, int b){
    return a + b;
}

/**
 * difference of a and b
 * @param a
 * @param b
 * @return difference
 */

int MathFtion::minus(int a, int b){
    return a - b;
}

/**
 * multiplication of a and b
 * @param a
 * @param b
 * @return multiplication
*/

int MathFtion::multiplication(int a, int b){
    return a * b;
}

/**
 * Quotient of a and b
 * @param a
 * @param b
 * @return quotient
*/

int MathFtion::dividing(int a, int b){
    if(b != 0){
        return a / b;
    } else {
        return "Cannot divide by 0!";
    }
}

/**
 * Multipllication of same number numeros times. 
 * @param a number to multiplie
 * @param b how many times is gonna multiple. Square is based if its not defined
 * @return 
 */
int MathFtion::square(int a, int b = 2){
    for(int i = 0; i < b; i++)
        a *= a;
    return a;
}

/**
 * nthRoot of a, where level of root is decided by value of b
 * @param a
 * @param b 
 * @return 
*/
int MathFtion::nthRoot(int a, int b){
    float result;
    
    //*condition for calculating root
    if (a < 0){
        return "Cannot calculate root of negative number!";
    }
    //TODO: rest of this function
}

/**
 * Factorial of number a 
 * @param a number
 * @return factorial of a
 */
int MathFtion::factorial(int a){
    float result = 1;
    for (int i = a; i > 0; i--){
        result =  result * i;
    }
    return result;
}

/**
 * Negate number
 * @param a number to negate
 * @return negate @a
 */
int MathFtion::negation(int a){
    return MinusOne*a;
}