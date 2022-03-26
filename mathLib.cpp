#include "mathLib.h"

#define NegationOne -1

/**
 * 
 * @param a 
 * @param b
 * @return 
 */

int MathFtion::plus(int a, int b){
    return (a + b);
}

/**
 * 
 * @param a 
 * @param b
 * @return 
 */

int MathFtion::minus(int a, int b){
    return a - b;
}

int MathFtion::multiplication(int a, int b){

}

int MathFtion::dividing(int a, int b){

}
int MathFtion::square(int a, int b = 2){
    for(int i = 0; i < b; i++)
        a *= a;
}
int MathFtion::squareRoot(int a, int b){

}
int MathFtion::factorial(int a, int b){

}
int MathFtion::negation(int a){
    return NegationOne*a;
}