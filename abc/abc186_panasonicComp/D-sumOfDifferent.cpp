#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);

  for (int i = 0; i < n; i ++) {
    cin >> a.at(i);
  }

  long long s = 0, sum = 0;
  /**
   s = accumulate(a.begin(), a.end(), 0);
   では計算できない　=>　桁数が大きいため.
   s = accumulate(a.begin(), a.end(), 0LL); (longの0)
   とすれば可能.

  namespace std {
  template <class InputIterator, class T>
  T accumulate(InputIterator first, InputIterator last, T init);           // (1) C++03
  template <class InputIterator, class T>
  constexpr T accumulate(InputIterator first, InputIterator last, T init); // (1) C++20

  template <class InputIterator, class T, class BinaryOperation>
  T accumulate(InputIterator first, InputIterator last, T init,
               BinaryOperation binary_op);                                 // (2) C++03
  template <class InputIterator, class T, class BinaryOperation>
  constexpr T accumulate(InputIterator first, InputIterator last, T init,
                         BinaryOperation binary_op);                       // (2) C++20
  }
   返り値はinitの型とおなじになる.
  */

  for (int i = 0; i < n; i++) {
    s += a.at(i);
  }

  sort(a.begin(), a.end());

  for (int i = 0; i < n - 1; i++) {
    sum += s - a.at(i) * (n - i);
    s -= a.at(i);
  }

  cout << sum << endl;
}

/**
問題文
N個の整数 A_1,…,A_N
 が与えられます。

1≤i<j≤Nを満たす全ての i,jの組についての
|A_i−A_j|の和を求めてください。

すなわち、
∑^N−1_i=1  ∑^N_j=i+1 |Ai−Aj|
 を求めてください。

制約
2≤N≤2×10~5
|Ai|≤10^8
Aiは整数である。

入力
入力は以下の形式で標準入力から与えられる。

N
A_1 … A_N

出力
答えを出力せよ。
*/
