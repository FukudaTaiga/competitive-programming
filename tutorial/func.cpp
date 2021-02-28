#include <bits/stdc++.h>
using namespace std;

/**
関数の定義

引数は基本値渡し. &引数の名前 とすると参照渡しにできる.

返り値の型 関数名(引数1の型 引数1の名前, 引数2の型 引数2の名前, ...) {
  処理
  return 返り値; //voidの場合はreturn;. 省略可能.
}

プロトタイプ宣言

これをすると定義前に呼び出せる. 引数の名前は省略可能.
相互再帰のときは必須.

返り値の型 関数名(引数1の型 引数1の名前, 引数2の型 引数2の名前, ...);

オーバーロード: 引数の型, 引数の数のいずれかが異なれば同名で関数を宣言できる.

スコープ: 完全に関数の中のみ.

再帰: 普通にかける.
*/

int main() {
  int a = 1, b = 7;
  vector<int> vec = {1, 6, 3, 8, 2, 100};

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "vec: { ";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i) << " "; //i番目のアクセス
  }
  cout << "}" << endl;
  cout << endl;

  cout << "min: " << min(a, b) << endl;
  cout << "max: " << max(a, b) << endl;
  swap(a, b);
  cout << "swap" << endl;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;

  sort(vec.begin(), vec.end()); //tupleとかでもできる.
  cout << "sort vec" << endl;
  cout << "vec: { ";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i) << " ";
  }
  cout << "}" << endl;
  reverse(vec.begin(), vec.end());
  cout << "reverse vec" << endl;
  cout << "vec: { ";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i) << " ";
  }
  cout << "}" << endl;

  return 0;
}
