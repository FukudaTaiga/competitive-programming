#include <bits/stdc++.h>
using namespace std;

int main() {
  int a = 44;
  //int a = 5; この行でコンパイルエラーになる
  double b = 3.0, c = a; // int,doubleは互いに代入可能
  //c = a;としたときは値渡し. 実態は別.
  //c = &a;で参照渡し.
  string str; //この時点では初期化していないから何が入っているかわからない. 多くは""
  //_はvariable名に使用可. 数字から始まる, 記号が利用されている, キーワードは不可.
  str = "string";
  string num = "12345";
  bool t, f;
  t = 10; //0以外は全て1になる
  f = false; //true:1, false:0

  cout << c << endl;
  cout << b + a << endl; //型の変換がされる
  cout << str << endl;
  cout << str + to_string(a) << endl; //ll -> string
  cout << stol(num) + a << endl; //string -> ll stod, stoi,stof
  cout << "t: " << t << ", f: " << f << endl;

  //初期化を伴う変数宣言, 範囲for文では型をautoで書ける&varを定義するときとかも使える.
  auto z = 10;
  auto v = {1, 1, 2, 3, 5, 8, 13};
  for (auto e : v) {
    cout << e << endl;
  }

  //型エイリアス: 別名宣言
  //using 新しい型名 = 型名;
  //typedef 型名 新しい型名
  using vi1 = vector<int>;
  typedef vector<int> vi2;
}
