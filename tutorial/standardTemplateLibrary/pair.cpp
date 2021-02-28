#include <bits/stdc++.h>
using namespace std;

int main() {
  //pair <utility>だがしなくても使えたりする
  pair<string, int> p; //宣言
  pair<string, int> p2("abc", 3); //初期化
  p = make_pair("*", 1); //pair<string, int>("*", 1)
  string s;
  int k;
  tie(s, k) = p; //各要素を変数に代入. ignoreとかつけると切り捨てたりできる.

  //アクセス
  cout << "p: (" << p.first << " " << p.second << ")" << endl;  // * 3
  cout << "assign pair first" << endl;
  p.first = "hello";
  cout << "p: (" << p.first << " " << p.second << ")" << endl;  // hello 3

  //tieを使ったアクセス
  cout << s << endl;
  cout << k << endl;

  //tuple <tuple>
  tuple<int, int, string, double> t; //宣言
  tuple<int, int, string, double> t2(1, 2, "aaa", 3.14); // 初期化
  t = make_tuple(0, -1, "*", 99.9); //tuple<int, int, string, double>(0, 1, "*", 99.9);
  // アクセス. get<k>(t) kに変数は使えない.
  cout << "t: (" << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << ")" << endl;

  int i, j;
  string str;
  double a;

  //for とかでアクセスするときは有用.
  tie(i, j, str, a) = t;

  cout << "t: (" << i << " " << j << " " << str << " " << a << ")" << endl;

  /**
  比較
  型が同じならできる.
  < : 1番目の要素で, 同じなら2番目で, ...と比較
  == : 全要素が等しい
  */

  cout << "compare" << endl;

  cout << (t == t2) << endl; //false
  cout << (t < t2) << endl; //true

}
