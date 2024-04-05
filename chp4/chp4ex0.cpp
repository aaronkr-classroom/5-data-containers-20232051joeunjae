// chp4ex0.cpp
// �߰����, �⸻���, �׸��� ���� ���� ��� �ް�
// ������ ��� ��� ������ ����ϱ�.
#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include<vector>

using namespace std;
//�Լ��� ȣ���ϸ� �ȼ��� ������ ���͸� ��°�� ���� ,�߾Ӱ��� ����
	double median(vector<double>vec) {
	//���� ������ �Է� ������ Ȯ��
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	if (size == 0) {
		cout << endl << "no grades. try again " << endl;
		return 1;
	}
	//������ ����
	sort(vec.begin(), vec.end());

	//���� ������ �߾Ӱ��� ����
	vec_sz mid = size / 2;
	double median;
	return size % 2 == 0;
	median = size % 2 == 0 ?
		(vec[mid] + vec[mid - 1]) / 2
		: vec[mid];
	}
	//�л��� ���������� ����(����)
	double grade(double mt, double ft, double hw) {
		return 0.2 * mt + 0.4 * ft + 0.4 * hw;
	}
	//�л��� ���������� ���� ���Լ��� �μ��� �������� �ʰ� median �Լ��� �ش� �۾��� ����
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
			//�Һ���
			while (in >> x) {

				hw.push_back(x);
			}

			in.clear();

		}
		return in;
	}

	istream& read(istream& is, student_info& s) {
		//�л��� �̸�, �߰���� ����, �⸻��� ������ �о� ����
		is >> s.name >> s.midtrem >> s.final;
		//���� ������ ����
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

		//�л��̸��� ��� ������ �о� �����ϰ� 
		//����� �̸��� ã��
		while (read(cin, record)) {
			maxlen = max(maxlen, record.name.size());
			// asdfg=(�̸�) max(0, 5) = 5
			students.push_back(record);

		}
		//�л� ������ ���ĺ� ������ ����
		sort(students.begin(),students.end(),compare);
		for (vector<student_info>::size_type i = 0;
			i != students.size(); ++i) {
			//�̸��� �����������Ͽ� maxlen +1���� ���ڸ� ���
			cout << students[i].name
				<< string(maxlen + 1 - students[i].name.size(), ' ');





			//���� ������ ����� ����
			try {
				double final_grade = grade(students[i]);
				//��� ���
				streamsize prec = cout.precision();
				cout << "final grade" << setprecision(3)
					<< final_grade << setprecision(prec) << endl;

			}
			catch (domain_error e) {
				cout << e.what();
			}
		} //for ��
		return 0;
	} // main ��
