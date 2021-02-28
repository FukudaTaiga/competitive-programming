#include <bits/stdc++.h>
using namespace std;

int numsize(int n) {
  int x = 0;

  while (n != 0) {
    x += n % 10;
    n /= 10;
  }

  return x;
}

int main() {
  int a, b;

  cin >> a >> b;

  cout << max(numsize(a), numsize(b)) << endl;
}

/**
問題文
整数
n
 に対して、
n
 を十進法で表したときの各桁の和を
S
(
n
)
 で表すことにします。 例えば、
S
(
123
)
=
1
+
2
+
3
=
6
 です。

2
 つの
3
 桁の整数
A
,
B
 が与えられます。
S
(
A
)
 と
S
(
B
)
 のうち大きい方の値を求めてください。

制約
入力は全て整数
100
≤
A
,
B
≤
999
入力
入力は以下の形式で標準入力から与えられる。

A

B

出力
S
(
A
)
 と
S
(
B
)
 のうち大きい方の値を出力せよ。
S
(
A
)
 と
S
(
B
)
 が等しい場合は、
S
(
A
)
 を出力せよ。
*/
