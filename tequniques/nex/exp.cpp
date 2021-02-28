#include <bits/stdc++.h>
using namespace std;

//愚直に行う場合
//O(n)
long long exp1(int a, int n) {
  long long x = 1;
  for (auto i = 0; i < n; i++) {
    x *= a;
  }
  return x;
}

//二分累乗法
//O(log(n))
long long exp2(long long a, int n) {
  //関数的表記
  /**
  if (n == 0) return 1;
  else if (n % 2 == 1) return a * exp2(a * a, n / 2);
  else return exp2(a * a, n / 2);
  */

  long long x = 1;

  while (n > 0) {
    if (n & 1) x = x * a; //n = 0110...と1 = ...0001のbit積. 1ビット分だけ取り出せる.
    a = a * a;
    n >>= 1; //nを1ビット右シフト.
  }

  return x;
}

int main() {
  //a^nを計算する.
  int a, n;
  long long x;
  clock_t start;
  clock_t end;

  cout << "a ^ n" << endl;
  cout << "type a, n" << endl;

  cin >> a >> n;

  //clock()は10msの精度なので1msまで計測したいときは
  //<chrono>にあるchrono::system_clock::now()を用いる.
  x = exp1(a, n);
  cout << "a^n: " << x << " time: " << end - start << endl;

  x = exp2(a, n);
  cout << "a^n: " << x << " time: " << end - start << endl;

}
