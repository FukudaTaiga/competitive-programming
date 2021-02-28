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
  vvi v(N, vi(N));

  rep (i, N) {
    cin >> v[i][i];
    rep (j, i) v[j][i] = min(v[j][i - 1], v[i][i]);
  }

  ll m = 0;
  rep (i, N) {
    FOR (j, i, N) {
      ll temp = v[i][j] * (j - i + 1);
      m = max(m, temp);
    }
  }

  cout << m << endl;
}


//最大長方形
//オフラインクエリ
/**
C - Mandarin Orange  /
実行時間制限: 1.5 sec / メモリ制限: 1024 MB

配点 :
300
 点

問題文
高橋君の前に
N
 枚の皿が一列に並べられており、左から
i
 番目の皿には
A
i
 個のみかんが置かれています。

高橋君は次の
3
 つの条件を全て満たすような整数の組
(
l
,
r
,
x
)
 を
1
 つ選びます。

1
≤
l
≤
r
≤
N
1
≤
x
l
 以上
r
 以下の全ての整数
i
 について、
x
≤
A
i
その後、高橋君は
l
 番目から
r
 番目まで (両端を含む) の全ての皿からみかんを
x
 個ずつ取って食べます。

整数の組
(
l
,
r
,
x
)
 を適切に選んだとき、高橋君は最大で何個のみかんを食べることができますか。

制約
入力は全て整数
1
≤
N
≤
10
4
1
≤
A
i
≤
10
5
入力
入力は以下の形式で標準入力から与えられる。

N

A
1

…

A
N

出力
高橋君が食べることのできるみかんの個数の最大値を出力せよ。

入力例 1
Copy
6
2 4 4 9 4 9
出力例 1
Copy
20
(
l
,
r
,
x
)
=
(
2
,
6
,
4
)
 としたとき、
20
 個のみかんを食べることができます。

入力例 2
Copy
6
200 4 4 9 4 9
出力例 2
Copy
200
(
l
,
r
,
x
)
=
(
1
,
1
,
200
)
 としたとき、
200
 個のみかんを食べることができます。
 */
