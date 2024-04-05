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

const int MAX = 1000;


int main() {
    const int pad = log10(MAX * MAX) + 2;
    for (int i = 1; i <= MAX; i++)
    {
        cout << i << setw(pad);
    }
    cout << endl << setw(0);
    for (int i = 1; i <= MAX; i++)
    {
        cout << i * i << setw(pad);
    }
    cout << endl;
    return 0;
}