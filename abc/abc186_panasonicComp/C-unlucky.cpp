#include <bits/stdc++.h>
using namespace std;

bool check(int l, int k) {
  int i = l;
  bool b = true;

  while (i != 0) {
    if (i % k == 7) {
      b = false;
      break;
    }

    i /= k;
  }

  return b;
}

int main() {
  int n;
  int count = 0;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    if (check(i, 10) && check(i, 8)) count++;
  }

  cout << count;
}
/**
問題文
高橋君は 7が嫌いです。
1以上 N
以下の整数のうち、10進法で表しても 8進法で表しても
7を含まないような数はいくつありますか？

制約
1 ≤ N ≤ 10~5
Nは整数である。

入力

入力は以下の形式で標準入力から与えられる。
N

出力
答えを整数で出力せよ。
*/
