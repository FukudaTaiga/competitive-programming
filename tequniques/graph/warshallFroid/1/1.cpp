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
#define rep(i, n) FORLL(i, 0LL, n)
#define biti(bit, i) ( (bit >> i) & 1 )
#define _GLIBCXX_DEBUG

ll N, M;
const ll INF = LONG_MAX;

vvl warshal_froid(vector<vector<pl>> w) {
  ll v = w.size();
  vvl dp(v, vl(v, INF));
  ll t, d;

  //本来はdp[k][i][j]: 0~(k - 1)までを使ってi -> jに遷移するときの最小コスト. - k = 0のときは直接 i-jの重みになる.
  //i - jの最短経路がkを含まない = dp[k + 1][i][j] = dp[k][i][j]
  //                   含む    = dp[k][i][k] + dp[k][k][j]

  rep (i, v) {
    for (auto e: w[i]) {
      tie(t, d) = e;
      dp[i][t] = d;
    }

    dp[i][i] = 0;
  }

  rep (k, v) { //via
    rep (i, v) { //start
      rep (j, v) { //end
        if (dp[i][k] != INF && dp[k][j] != INF) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  return dp;
}

int main() {
  ifstream fin;
  string name = "input.txt";

  fin.open(name);

  if (fin.fail()) cout << "file isnt found" << endl;
  else {
    ll V, E;
    fin >> V >> E;
    vector<vector<pl>> w(V, vector<pl>(0));
    rep (i, E) {
      ll s, t, d;
      fin >> s >> t >> d;
      w[s].push_back(make_pair(t, d));
    }

    vvl dp = warshal_froid(w);

    rep (i, V) if (dp[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }

    for (auto r: dp) {
      for (auto c: r) {
        if (c == INF) cout << "INF ";
        else cout << c << " ";
      }
      cout << endl;
    }
  }
}


/**
全点対間最短経路
重み付き有向グラフ
G
=
(
V
,
E
)
 の全点対間最短経路の距離を列挙してください。

入力
入力は以下の形式で与えられます。

|
V
|
|
E
|

s
0
t
0
d
0

s
1
t
1
d
1

:

s
|
E
|
−
1
t
|
E
|
−
1
d
|
E
|
−
1

|
V
|
,
|
E
|
 はそれぞれグラフ
G
 の頂点の数と辺の数を示します。グラフ
G
 の頂点はそれぞれ
0
,
1
,
.
.
.
,
|
V
|
−
1
 の番号が付けられているものとします。

s
i
,
t
i
,
d
i
 はグラフ
G
 の
i
 番目の辺が結ぶ（有向）２つの頂点の番号とその重みを表します。

出力
グラフ
G
 が負の閉路（辺の重みの和が負になるような閉路）を持つ場合は NEGATIVE CYCLE と１行に出力してください。それ以外の場合以下の形式で距離を出力してください。

D
0
,
0
D
0
,
1
.
.
.
D
0
,
|
V
|
−
1

D
1
,
0
D
1
,
1
.
.
.
D
1
,
|
V
|
−
1

:
D
|
V
|
−
1
,
0
D
|
V
|
−
1
,
1
.
.
.
D
|
V
|
−
1
,
|
V
|
−
1

出力は
|
V
|
 行からなります。
i
 行目に頂点
i
 から各頂点
j
(
j
=
0
,
1
,
.
.
.
|
V
|
−
1
)
 への最短経路の距離を出力してください。
i
 から
j
 への経路がない場合は INF と出力してください。距離の間に１つの空白を出力してください。

制約
1
≤
|
V
|
≤
100
0
≤
|
E
|
≤
9
,
900
−
2
×
10
7
≤
d
i
≤
2
×
10
7
G
 に多重辺はない
G
 に自己ループはない
入力例 1
4 6
0 1 1
0 2 5
1 2 2
1 3 4
2 3 1
3 2 7
出力例 1
0 1 3 4
INF 0 2 3
INF INF 0 1
INF INF 7 0

入力例 2
4 6
0 1 1
0 2 -5
1 2 2
1 3 4
2 3 1
3 2 7
出力例 2
0 1 -5 -4
INF 0 2 3
INF INF 0 1
INF INF 7 0

入力例 3
4 6
0 1 1
0 2 5
1 2 2
1 3 4
2 3 1
3 2 -7
出力例 3
NEGATIVE CYCLE
*/
