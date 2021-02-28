#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << 1 + 1 << endl; //2
  cout << 1 - 1 << endl; //0
  cout << 2 * 3 << endl; //6
  cout << 7 / 3 << endl; //2
  cout << 7.0 / 3 << endl; //2.333...
  cout << 7 / 3.0 << endl; //2.333...
  cout << 4 % 3 << endl; //1
  cout << -4 % 3 << endl; //-1
  cout << 4 % 3 << endl; //1
  cout << -4 % -3 << endl; //-1
  //a % b: a = (a / b) * b + a % bが等しくなうように計算されるので結果的にaと(a % b)の符号は等しくなる 
}
