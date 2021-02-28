#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> x(N);
  vector<int> y(N);

  int count = 0;

  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }

  double k;

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      k = (double) (y[j] - y[i]) / (double) (x[j] - x[i]);
      if (abs(k) <= 1) count++;
    }
  }

  cout << count << endl;
}

/**
問題文
x
y
 平面上に
1
,
2
,
…
,
N
 の番号が付けられた
N
 個の点があります。点
i
 は
(
x
i
,
y
i
)
 にあり、
N
 個の点の
x
 座標は互いに異なります。

以下の条件を満たす整数の組
(
i
,
j
)

(
i
<
j
)
 の個数を求めてください。

点
i
 と点
j
 を通る直線の傾きが
−
1
 以上
1
 以下である。
制約
入力は全て整数
1
≤
N
≤
10
3
|
x
i
|
,
|
y
i
|
≤
10
3
i
≠
j
 ならば
x
i
≠
x
j
入力
入力は以下の形式で標準入力から与えられる。

N

x
1

y
1

⋮

x
N

y
N

出力
答えを出力せよ。
*/
