#include <bits/stdc++.h>
using namespace std;

int main() {
  int i = pow(2, 38);
  cout << "overflow: " << i << endl; //intは-2^31~2^31-1
  int64_t i64 = pow(2, 38);
  cout << "valid" << i64 << endl;
  i64 = -pow(2, 63);
  //10: int
  //10LL: int64_t
  cout << "overflow: " << i64 << endl; //int64_tは-2^63~2^63-1

  //他にもsigned char, short, unsigned charとかある.

  /**
  cast

  numeralな型間では
  int a = 10;
  double b = (double) a;
  のようにcast可能.

  stringとかはダメ.
  int->string: to_string(a)
  string->int: stoi(s)
  string->int64_t:stoll
  string->double: stod
  */

  //cout << fixed << setprecision(桁数); 四捨五入防ぐ.
  //doubleで精度が保障できるのは16桁まで
  double pi = stod("3.141592653589793238");
  cout << pi << endl;
  //10桁
  cout << fixed << setprecision(10);
  cout << pi << endl;

  //情報落ち
  double x = 1000000000;
  double y = 0.000000001;

  // 1000000000.000000001 を表現するには19桁分必要 → 扱えない
  double z = x + y;  // yの分が消えてしまう

  cout << fixed << setprecision(16);
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  cout << "z: " << z << endl;

  x = 0.1234567890123
  y = 0.1233456789012
  z = x - y //0.0001111111111...
  cout << fixed << setprecision(16);
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  cout << "z: " << z << endl;

  //精度指定等の場合はcoutより便利.
  //printf(フォーマット文字列, 埋め込みたい値1, 埋め込みたい値2, ...)
  //cinと同様に使える.
  //scanf(フォーマット文字列, &変数1, &変数2, &変数3, ...);
  /**
  %d: int
  %ld: int64_t
  %f: float
  %lf: double
  %c: char
  %s: string ただし, 変数.c_str()と書く.scanfでは扱えない.
  */
  // %.桁数f とすると小数点以下「桁数」だけ出力される
  // %0桁数d とすると表示桁数が「桁数」に満たない場合に0埋めされる
}
