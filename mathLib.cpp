#include<iostream>
#include<math.h>
#include "mathLib.h"

#define MinusOne -1

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
        fprintf(stderr, "Cannot divide by 0!");
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
    double result;
    
    //*condition for calculating root
    if (a < 0){
        fprintf(stderr, "Cannot calculate root of negative number!");
        return 0; //TODO Solve return value
    }

    if (a == 0 || a == 1){
        return a;
    }
    
    //TODO: rest of this function
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
    return MinusOne*a;
}