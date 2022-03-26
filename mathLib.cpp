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

int MathFtion::multiplication(int a, int b){

}

int MathFtion::dividing(int a, int b){

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

int MathFtion::squareRoot(int a, int b){

}
int MathFtion::factorial(int a, int b){

}

/**
 * Negate number
 * @param a number to negate
 * @return negate @a
 */
int MathFtion::negation(int a){
    return MinusOne*a;
}