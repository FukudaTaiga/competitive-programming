#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define f first
#define s second
#define FOR(i, s, n) for (int i = (s); i < (int) (n); i++)
#define FORLL(i, s, n) for (ll i = (s); i < (ll) (n); i++)
#define FORIT(itr, t) for (auto itr = (t).begin(); itr != (t).end(); ++itr)
#define rep(i, n) FOR(i, 0, n)
#define biti(bit, i) ( (bit >> i) & 1 )
#define _GLIBCXX_DEBUG

int main() {
  int N;
  cin >> N;
  vi v(N);
  rep (i, N) {
    string str;
    cin >> str;
    if (str == "AND") v[i] = 1;
  }

  ll cnt = 1;
  ll cnf = 1;
  rep (i, N) {
    if (v[i]) cnf = cnt + 2 * cnf;
    else cnt = 2*cnt + cnf;
  }

  cout << cnt << endl;
}

/**
D - Logical Expression  /
実行時間制限: 2 sec / メモリ制限: 1024 MB

配点 :
400
 点

問題文
N
 個の文字列
S
1
,
…
,
S
N
 が与えられます。各文字列は AND または OR です。

値が
True
 または
False
 であるような
N
+
1
 個の変数の組
(
x
0
,
…
,
x
N
)
 であって、 以下のような計算を行った際に、
y
N
 が
True
 となるようなものの個数を求めてください。

y
0
=
x
0
i
≥
1
 のとき、
S
i
 が AND なら
y
i
=
y
i
−
1
∧
x
i
、
S
i
 が OR なら
y
i
=
y
i
−
1
∨
x
i
a
∧
b
 は
a
 と
b
 の論理積を表し、
a
∨
b
 は
a
 と
b
 の論理和を表します。

制約
1
≤
N
≤
60
S
i
 は AND または OR
入力
入力は以下の形式で標準入力から与えられる。

N

S
1

⋮

S
N

出力
答えを出力せよ。

入力例 1
Copy
2
AND
OR
出力例 1
Copy
5
例えば
(
x
0
,
x
1
,
x
2
)
=
(
True
,
False
,
True
)
 のとき

y
0
=
x
0
=
True
y
1
=
y
0
∧
x
1
=
True
∧
False
=
False
y
2
=
y
1
∨
x
2
=
False
∨
True
=
True
となり、
y
2
 は
True
 になります。

y
2
 が
True
 となるような
(
x
0
,
x
1
,
x
2
)
 の組み合わせは、

(
True
,
True
,
True
)
(
True
,
True
,
False
)
(
True
,
False
,
True
)
(
False
,
True
,
True
)
(
False
,
False
,
True
)
の
5
 通りで全てです。

入力例 2
Copy
5
OR
OR
OR
OR
OR
出力例 2
Copy
63
全てが
False
 のときを除く
2
6
−
1
 通りで
y
5
 は
True
 になります。
 */
