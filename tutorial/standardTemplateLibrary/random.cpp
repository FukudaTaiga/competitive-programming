#include <bits/stdc++.h>
using namespace std;

int main() {
  //rand. <ctime>のインクルードが必要.
  srand((unsigned)time(NULL)); //生成毎に値を変える.

  int r = rand(); //gccでは0~2^31 - 1までの整数を出力.

  cout << "random integer: " << r << endl;
  cout << "random in 0 ~ 1: " << (double) r / INT_MAX << endl;
}
