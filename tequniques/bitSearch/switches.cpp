#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
#define FOR(i, s, n) for (int i = (s); i < (int) (n); i++)
#define rep(i, n) FOR(i, 0, n)


//bit full search
int main() {
  int N, M;
  cin >> N >> M;
  int k;
  vector<vi> s(M, vi(N));
  vi p(N);
  ll cnt = 0;
  rep (i, M) {
    int sij;
    cin >> k;
    rep (j, k) {
      cin >> sij;
      s[i][sij - 1] = 1;
    }
  }
  rep (i, M) cin >> p[i];

  vi v(M);

  rep (i, 1 << N) {
    int x = i;
    k = 0;

    while (x > 0) {
      if (x & 1) {
        rep (j, M) {
          if (s[j][k] == 1) v[j]++;
        }
      }
      k++;
      x >>= 1;
    }

    bool b = true;

    rep (j, M) {
      if (v[j] % 2 != p[j]) {
        b = false;
        break;
      }
    }

    v = vi(M);

    if (b) {
      cnt++;
    }
  }

  cout << cnt << endl;
}


/**
abc128 C
実行時間制限: 2 sec / メモリ制限: 1024 MB

配点 :
300
 点

問題文
on と off の状態を持つ
N
 個の スイッチと、
M
 個の電球があります。スイッチには
1
 から
N
 の、電球には
1
 から
M
 の番号がついています。

電球
i
 は
k
i
 個のスイッチに繋がっており、スイッチ
s
i
1
,
s
i
2
,
.
.
.
,
s
i
k
i
 のうち on になっているスイッチの個数を
2
 で割った余りが
p
i
 に等しい時に点灯します。

全ての電球が点灯するようなスイッチの on/off の状態の組み合わせは何通りあるでしょうか。

制約
1
≤
N
,
M
≤
10
1
≤
k
i
≤
N
1
≤
s
i
j
≤
N
s
i
a
≠
s
i
b
(
a
≠
b
)
p
i
 は
0
 または
1
入力は全て整数である
入力
入力は以下の形式で標準入力から与えられる。

N

M

k
1

s
11

s
12

.
.
.

s
1
k
1

:

k
M

s
M
1

s
M
2

.
.
.

s
M
k
M

p
1

p
2

.
.
.

p
M

出力
全ての電球が点灯するようなスイッチの on/off の状態の組み合わせの個数を出力せよ。
*/
