//chp4ex5
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
istream& readWords(istream& in, vector<string>& words){
    if (in){
        words.clear();
        string s;
        while (in >> s) {
            words.push_back(s);
        }
        in.clear();
    }
    return in;
}
int main(void){
    cout << "단어를 입력하세요: " << endl;
    vector<string> words;
    readWords(cin, words);
    sort(words.begin(), words.end());
    cout << "입력한 단어의 수: " << words.size() << endl;
    string temp = words[0];
    int cnt = 1;
    for (vector<string>::size_type i = 1; i < words.size(); i++)
    {
        if (temp == words[i])
        {
            cnt++;
            continue;
        }
        cout << temp << " : " << cnt << "번" << endl;
        temp = words[i];
        cnt = 1;
    }
    
    cout << temp << " : " << cnt << "번" << endl;
   
    
    
    return 0;
}

