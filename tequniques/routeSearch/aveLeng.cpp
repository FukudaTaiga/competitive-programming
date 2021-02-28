#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define FOR(i, s, n) for (int i = (s); i < (int) (n); i++)
#define FORLL(i, s, n) for (ll i = (s); i < (ll) (n); i++)
#define FORIT(itr, s, e) for (auto itr = (s); itr != (e); ++itr)
#define rep(i, n) FOR(i, 0, n)
#define _GLIBCXX_DEBUG

double getleng(pi p, pi q) {
  return sqrt(
    (p.first - q.first) * (p.first - q.first) +
    (p.second - q.second) * (p.second - q.second)
  );
}

int main() {
  int N;
  cin >> N;

  vector<pi> v(N);
  vi z(N);

  rep (i, N) {
    int x, y;
    cin >> x >> y;
    v[i] = make_pair(x, y);
    z[i] = i;
  }

  double res = 0;
  int n = 0;

  do {
    double sum = 0;
    rep (i, N - 1) sum += getleng(v[z[i]], v[z[i + 1]]);
    res += sum;
    n++;
  } while (next_permutation(z.begin(), z.end()));

  res /= n;

  cout << fixed << setprecision(10);
  cout << res << endl;
}


/**
配点 :
300
 点

問題文
座標平面上に
N
 個の町があります。町
i
 は、座標 (
x
i
 ,
y
i
 ) に位置しています。町
i
 と町
j
 の間の距離は
√
(
x
i
−
x
j
)
2
+
(
y
i
−
y
j
)
2
 です。

これらの町を全て
1
 回ずつ訪れるとき、町を訪れる経路は全部で
N
!
 通りあります。
1
 番目に訪れる町から出発し、
2
 番目に訪れる町、
3
 番目に訪れる町、
…
、を経由し、
N
 番目に訪れる町に到着するまでの移動距離 (町から町への移動は直線移動とします) を、その経路の長さとします。これらの
N
!
 通りの経路の長さの平均値を計算してください。

制約
2
≤
N
≤
8
−
1000
≤
x
i
≤
1000
−
1000
≤
y
i
≤
1000
(
x
i
,
y
i
)
≠
(
x
j
,
y
j
)
 (
i
≠
j
 のとき)
(21:12 追記) 入力中の値はすべて整数である。
入力
入力は以下の形式で標準入力から与えられる。

N

x
1

y
1

:

x
N

y
N

出力
経路の長さの平均値を出力せよ。 出力は、ジャッジの出力との絶対誤差または相対誤差が
10
−
6
 以下のとき正解と判定される。

入力例 1
Copy
3
0 0
1 0
0 1
出力例 1
Copy
2.2761423749
町を訪れる経路は
1
 →
2
 →
3
 ,
1
 →
3
 →
2
 ,
2
 →
1
 →
3
 ,
2
 →
3
 →
1
 ,
3
 →
1
 →
2
 ,
3
 →
2
 →
1
 の
6
 通りです。

このうち、経路
1
 →
2
 →
3
 の長さは、
√
(
0
−
1
)
2
+
(
0
−
0
)
2
+
√
(
1
−
0
)
2
+
(
0
−
1
)
2
=
1
+
√
2
 となります。

同様に他の経路についても長さを計算すると、経路の長さの平均値は、

(
1
+
√
2
)
+
(
1
+
√
2
)
+
(
2
)
+
(
1
+
√
2
)
+
(
2
)
+
(
1
+
√
2
)
6
=
2.276142...

であると分かります。

入力例 2
Copy
2
-879 981
-866 890
出力例 2
Copy
91.9238815543
町を訪れる経路は
1
 →
2
 ,
2
 →
1
 の
2
 通りありますが、これらの経路の長さは一致します。

入力例 3
Copy
8
-406 10
512 859
494 362
-955 -475
128 553
-986 -885
763 77
449 310
出力例 3
Copy
7641.9817824387
*/
