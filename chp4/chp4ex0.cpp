// chp4ex0.cpp
// 중간고사, 기말고사, 그리고 과제 점수 몇개를 받고
// 마지막 평균 결과 점수를 계산하기.
#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include<vector>

using namespace std;
//함수로 호출하면 안수로 제공된 백터를 통째로 복사 ,중앙값을 구함
	double median(vector<double>vec) {
	//과제 점수의 입력 유무를 확인
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	if (size == 0) {
		cout << endl << "no grades. try again " << endl;
		return 1;
	}
	//점수를 정렬
	sort(vec.begin(), vec.end());

	//과제 점수의 중앙값을 구함
	vec_sz mid = size / 2;
	double median;
	return size % 2 == 0;
	median = size % 2 == 0 ?
		(vec[mid] + vec[mid - 1]) / 2
		: vec[mid];
	}
	//학생의 종합점수를 가함(더함)
	double grade(double mt, double ft, double hw) {
		return 0.2 * mt + 0.4 * ft + 0.4 * hw;
	}
	//학생의 종합점수를 가함 이함수는 인수를 복사하지 않고 median 함수가 해당 작업을 살행
	double grade(double mt, double ft, const vector<double>& hw) {
		if (hw.size() == 0)
			throw domain_error("no homework!");
		return grade(mt, ft, median(hw));
	}
	double grade(const student_info& s) {
		return grade(s.midtrem, s.final, s.homework);
	}



	istream& read_hw(istream& in, vector<double>& hw) {
		if (in) {


			hw.clear();

			double x;
			//불변성
			while (in >> x) {

				hw.push_back(x);
			}

			in.clear();

		}
		return in;
	}

	istream& read(istream& is, student_info& s) {
		//학생의 이름, 중간고사 점수, 기말고사 점수를 읽어 저장
		is >> s.name >> s.midtrem >> s.final;
		//과제 점수를 읽음
		read_hw(is, s.homework);
		return is; //return is ,s;
	}
	bool compare(const student_info& x, const student_info& y) {
		return x.name < y.name;

	}

	struct student_info {
		string name;
		double midtrem, final;
		vector<double>homework;

	};
	int main(){
		vector<student_info> students;
		student_info record;
		string::size_type maxlen = 0;

		//학생이름과 모든 점수를 읽어 저장하고 
		//가장긴 이름을 찾음
		while (read(cin, record)) {
			maxlen = max(maxlen, record.name.size());
			// asdfg=(이름) max(0, 5) = 5
			students.push_back(record);

		}
		//학생 정보를 알파벳 순으로 정렬
		sort(students.begin(),students.end(),compare);
		for (vector<student_info>::size_type i = 0;
			i != students.size(); ++i) {
			//이름과 공백을포함하여 maxlen +1개의 문자를 출력
			cout << students[i].name
				<< string(maxlen + 1 - students[i].name.size(), ' ');





			//종합 점수를 계산해 생성
			try {
				double final_grade = grade(students[i]);
				//결과 출력
				streamsize prec = cout.precision();
				cout << "final grade" << setprecision(3)
					<< final_grade << setprecision(prec) << endl;

			}
			catch (domain_error e) {
				cout << e.what();
			}
		} //for 끝
		return 0;
	} // main 끝
