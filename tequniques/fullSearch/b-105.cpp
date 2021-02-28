#include <bits/stdc++.h>
using namespace std;

//count divisor of n
int divnum(int n) {
  int cnt = 0;
  for (int k = 1; k < n + 1; k++) {
    if (n % k == 0) cnt++;
  }
  return cnt;
}

int main() {
  int N;
  int cnt;
  cin >> N;

  for (int n = 1; n < N + 1; n++) {
    if (divnum(n) == 8 && n % 2 == 1) cnt++;
  }

  cout << cnt << endl;
}


/**
atcorder abc106 b
問題文
105
 という数は, 非常に特殊な性質を持つ - 奇数なのに, 約数が
8
 個もある.
さて,
1
 以上
N
 以下の奇数のうち, 正の約数を ちょうど
8
 個持つようなものの個数を求めよ.

制約
N
 は
1
 以上
200
 以下の整数
入力
入力は以下の形式で標準入力から与えられる.

N

出力
条件を満たす数の個数を出力しなさい.


*/
