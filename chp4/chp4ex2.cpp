//chp4ex2.cpp
#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include<vector>
#include "grade.h"
#include "student_info.h"

using namespace std;
const int MAX = 100;


int main(){
    for (int i = 1; i <= MAX; i++){
        cout << i << setw(6);
    }
    cout << endl << setw(0);
    for (int i = 1; i <= MAX; i++) {
        cout << i * i << setw(6);
    }


    cout << endl;

    return 0;
}
