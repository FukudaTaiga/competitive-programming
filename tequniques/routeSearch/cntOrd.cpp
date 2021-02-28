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

int main() {
  int N;
  cin >> N;
  vi x(N), y(N), v(N);
  rep (i, N) {
    cin >> x[i];
    v[i] = i + 1;
  }
  rep (j, N) cin >> y[j];

  int a = -1, b = -1;

  int i = 1;
  do {
    if (x == v) a = i;
    if (y == v) b = i;

    if (a != -1 && b != -1) break;

    i++;
  } while (next_permutation(v.begin(), v.end()));

  cout << abs(a - b) << endl;
}


/**
abc150-C
実行時間制限: 2 sec / メモリ制限: 1024 MB

配点 :
300
 点

問題文
大きさ
N
 の順列 (
(
1
,

2
,

.
.
.
,

N
)
 を並び替えてできる数列)
P
,

Q
 があります。

大きさ
N
 の順列は
N
!
 通り考えられます。このうち、
P
 が辞書順で
a
 番目に小さく、
Q
 が辞書順で
b
 番目に小さいとして、
|
a
−
b
|
 を求めてください。

注記
2
 つの数列
X
,

Y
 について、ある整数
k
 が存在して
X
i
=
Y
i

(
1
≤
i
<
k
)
 かつ
X
k
<
Y
k
 が成り立つとき、
X
 は
Y
 より辞書順で小さいと定義されます。

制約
2
≤
N
≤
8
P
,

Q
 は大きさ
N
 の順列である。
入力は全て整数である。
入力
入力は以下の形式で標準入力から与えられる。

N

P
1

P
2

.
.
.

P
N

Q
1

Q
2

.
.
.

Q
N

出力
|
a
−
b
|
 を出力せよ。

入力例 1
Copy
3
1 3 2
3 1 2
出力例 1
Copy
3
大きさ
3
 の順列は、
(
1
,

2
,

3
)
、
(
1
,

3
,

2
)
、
(
2
,

1
,

3
)
、
(
2
,

3
,

1
)
、
(
3
,

1
,

2
)
、
(
3
,

2
,

1
)
 の
6
 個あります。このうち
(
1
,

3
,

2
)
 は辞書順で
2
 番目、
(
3
,

1
,

2
)
 は辞書順で
5
 番目なので、答えは
|
2
−
5
|
=
3
 です。

入力例 2
Copy
8
7 3 5 4 2 1 6 8
3 8 2 5 4 6 7 1
出力例 2
Copy
17517
入力例 3
Copy
3
1 2 3
1 2 3
出力例 3
Copy
0
*/
