#include<iostream>
#include<string>
#include<fstream>
#include"mathLib.h"

#define NEGATIVEONE -1 // for difference calculation of counter 

using namespace std;

double profiling(string fileName, MathFtion NewCalculate); 

int main(int argc, char* argv[]){
    MathFtion NewCalculate;
    string text;
    int iterator = 0;
    if(argc == 2){
        cout << (text = to_string(profiling(argv[1], NewCalculate))) << endl;
    }
    else{
        while((text[iterator] = getchar()) != EOF){
            if(text[iterator] == 32){
                continue;
            }
            if(text[iterator] == '\n' || text[iterator+1] == EOF){
                cout << (text = (NewCalculate.inputFtion(text))) << endl;
                iterator = 0;
                continue;
            }
            iterator++;
        }
    return 0;
}

double profiling(string fileName, MathFtion NewCalculate){
    string text;
    double answer;
    double s = 0, num = 0; //s_sqrt = 0
    double sum_avg = 0, sum_sq = 0;
    int counter = 0;
    ifstream readfile(fileName);
    while(readFile >> num){
        counter++;
        sum_avg = NewCalculate.plusF(sum_avg, num);
        sum_sq = NewCalculate.plusF(sum_sq,(NewCalculate.power(num)));
    }
    answer = NewCalculate.dividing(NewCalculate.plusF(sum_sq,NewCalculate.negation(NewCalculate.dividing(NewCalculate.power(sum_avg),counter))),NewCalculate.plusF(counter, NEGATIVEONE)); //s_sqrt

    readfile.close();
    return answer;
}


/**
int main()
{
    string text;
    float s = 0;
    float s_sqrt = 0;
    float num = 0;
    float sum_avg = 0;
    float sum_sq = 0;
    int counter = 0;
    ifstream readFile("numbers.txt");
    while(readFile >> num)
        {
            cout << num << "\n";
            counter++;
            sum_avg += num;
            sum_sq += num*num;
        }
    cout << "avg " << sum_avg/counter << " sum " << sum_sq << " counter " << counter << "\n";
    s_sqrt = (sum_sq - (sum_avg * sum_avg / counter))/(counter - 1);
    cout << s_sqrt << "\n";
    //s = sqrt(s_sqrt);
    readFile.close();
    return 0;
}
*/