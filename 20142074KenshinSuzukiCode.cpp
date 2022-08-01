#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

//�N���X�̒�`(�u�Ǝ��̃N���X�A�֐��v���܂�)
class Person {
private:
	string Runner; //����(��������string)
	double Record; //�L�^(�����_���"double")
	int Lane; //��H���[��(�������int)
	int Race; //��H���[�X(�������int)
public:
	void setRunner(const string& Who) { Runner = Who; } //����������������A�N�Z�X���䁫������
	string getRunner() { return Runner; } 

	void setRecord(double Time) { Record = Time; }
	double getRecord()const { return Record; }

	void setLane(int LaneNum) { Lane = LaneNum; }
	int getLane() { return Lane; }

	void setRace(int RaceNum) { Race = RaceNum; }
	int getRace() { return Race; } //�������������܂ŃA�N�Z�X���䁪������
};

//��r�֐��uHAYAI�v�̒�`
bool HAYAI(const Person& a, const Person& b) {
	return a.getRecord() < b.getRecord(); //�~��(�L�^���ǂ���)�ɕ��ѕς��邱�Ƃ�ړI�Ƃ���
}

//���C���֐��̒�`
int main() {
	//�t�@�C������
	ifstream datafile("Paper2.cpp");
	
	//�t�@�C�����J�������ǂ����̊m�F
	//�t�@�C�����J���Ȃ������ꍇ
	if (!datafile) {
		cout << "�ǂݍ��ރf�[�^�����݂��܂���B\n";
	}

	//�t�@�C�����J�����ꍇ
	else {

		//�R���e�i�̒�`
		vector<Person>v1;

		//�v�f�ɂ������p�����[�^�̒�`
		string a;
		double b;
		int c;
		int d;

		//while���ɂ������p�����[�^�̒�`
		int i = 0;

		//while���ŃR���e�i�֊i�[
		while (datafile >> a >> b >> c >> d) {
			v1.emplace_back();
			v1[i].setRunner(a);
			v1[i].setRecord(b);
			v1[i].setLane(c);
			v1[i].setRace(d);
			i++; //i��1�������
		}

		//��r�֐��uHAYAI�v��p����sort�����s
		sort(v1.begin(), v1.end(), HAYAI); //�u�C�e���[�^�̎g�p�v���܂�

		//���ёւ��ς̃����o��\��(���ʂ�\��)
		//�e���[�X�I����("Paper2.cpp"���͎�)�Ɏ��s���ׂ�����
		for (auto View : v1) {
			cout << View.getRunner() << "�@�L�^�F" << View.getRecord() << "�b�@��" << View.getLane() << "���[��" << endl; //�u��H���[�X���v�͕\�����Ȃ�
		}

		////�S���[�X�I����("Paper.cpp"���͎�)�Ɏ��s���ׂ�����
		//for (auto View : v1) {
		//	cout << View.getRunner() << "�@�L�^�F" << View.getRecord() << "�b�@��"  << View.getLane()  << "���[���@��"  << View.getRace() << "���[�X" << endl;
		//}
	}
}