#include<iostream>
#include "librarie/mathLib.h"
#include<string>

#define MAXSIGHNS 2

using namespace std;

string baseInput();

int main(void){
  bool reset;
  while(reset){
    mathFtion newMathFtion;
    string newInput = baseInput();
    if(newInput == '0'){
      cerr << "Input is empty" << endl;
      cout << newInput << endl;
      continue;
    }
    string newInput = newMathFtion.inputFtion(newInput);
    cout << newInput << endl;
  }
  return 0;
}

/**
 * @brief reading from console
 * @return string value from user input
 */

string baseInput(){
  string newInput;
  if(getline(cin, newInput)){
    return newInput;
    }
  else{
    return '0';
  }
}
