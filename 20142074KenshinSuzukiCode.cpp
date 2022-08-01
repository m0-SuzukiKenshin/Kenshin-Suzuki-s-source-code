#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

//クラスの定義(「独自のクラス、関数」を含む)
class Person {
private:
	string Runner; //走者(文字列よりstring)
	double Record; //記録(小数点より"double")
	int Lane; //第？レーン(整数よりint)
	int Race; //第？レース(整数よりint)
public:
	void setRunner(const string& Who) { Runner = Who; } //↓↓↓↓ここからアクセス制御↓↓↓↓
	string getRunner() { return Runner; } 

	void setRecord(double Time) { Record = Time; }
	double getRecord()const { return Record; }

	void setLane(int LaneNum) { Lane = LaneNum; }
	int getLane() { return Lane; }

	void setRace(int RaceNum) { Race = RaceNum; }
	int getRace() { return Race; } //↑↑↑↑ここまでアクセス制御↑↑↑↑
};

//比較関数「HAYAI」の定義
bool HAYAI(const Person& a, const Person& b) {
	return a.getRecord() < b.getRecord(); //降順(記録が良い順)に並び変えることを目的とする
}

//メイン関数の定義
int main() {
	//ファイル入力
	ifstream datafile("Paper2.cpp");
	
	//ファイルが開けたかどうかの確認
	//ファイルが開けなかった場合
	if (!datafile) {
		cout << "読み込むデータが存在しません。\n";
	}

	//ファイルが開けた場合
	else {

		//コンテナの定義
		vector<Person>v1;

		//要素にかかわるパラメータの定義
		string a;
		double b;
		int c;
		int d;

		//while文にかかわるパラメータの定義
		int i = 0;

		//while文でコンテナへ格納
		while (datafile >> a >> b >> c >> d) {
			v1.emplace_back();
			v1[i].setRunner(a);
			v1[i].setRecord(b);
			v1[i].setLane(c);
			v1[i].setRace(d);
			i++; //iに1足される
		}

		//比較関数「HAYAI」を用いたsortを実行
		sort(v1.begin(), v1.end(), HAYAI); //「イテレータの使用」を含む

		//並び替え済のメンバを表示(結果を表示)
		//各レース終了後("Paper2.cpp"入力時)に実行すべき部分
		for (auto View : v1) {
			cout << View.getRunner() << "　記録：" << View.getRecord() << "秒　第" << View.getLane() << "レーン" << endl; //「第？レースか」は表示しない
		}

		////全レース終了後("Paper.cpp"入力時)に実行すべき部分
		//for (auto View : v1) {
		//	cout << View.getRunner() << "　記録：" << View.getRecord() << "秒　第"  << View.getLane()  << "レーン　第"  << View.getRace() << "レース" << endl;
		//}
	}
}