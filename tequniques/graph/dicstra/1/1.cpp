#include <bits/stdc++.h>
#include <fstream>
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

//O((E + V)logV) priority_queue使わない場合はO(V^2)
vl dicstra(vvl w, ll r, ll v) {
  vl dis(v, INF);
  priority_queue<pl> que;
  que.push(make_pair(0, r));

  ll node, curr;

  //queには行けるノードとその距離が入ってる.
  //取り出してすでに最短距離を超えている場合はもう更新しない.(追加される要素の方が今後常に遠くなるから.)
  //そうでなければ, queに追加する.
  //この方法は負の辺が存在する場合は使えない.
  while (!que.empty()) {
    tie(curr, node) = que.top();
    que.pop();

    if (dis[node] <= curr) continue;
    else {
      dis[node] = curr;
      rep (i, v) if (w[node][i] != -1) que.push(make_pair(curr + w[node][i], i));
    }
  }

  return dis;
}

int main() {
  ifstream fin;
  string name = "input.txt";

  fin.open(name);
  if (fin.fail()) cout << "file isnt found" << endl;
  else {
    ll V, E;
    ll r; //start node
    fin >> V >> E >> r;
    vvl w(V, vl(V, -1));
    rep (i, E) {
      ll s, t, d;
      fin >> s >> t >> d;
      w[s][t] = d;
    }

    for (auto e: dicstra(w, r, V)) {
      if (e == INF) cout << "INF" << endl;
      else cout << e << endl;
    }
  }
}

/**
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja
単一始点最短経路
与えられたグラフ
G
=
(
V
,
E
)
 と始点
r
 について、単一始点最短経路の重みを求めるプログラムを作成してください。
G
 のノード
r
 を始点とし、
r
 から各ノードについて、最短経路上の辺の重みの総和を出力してください。

入力
|
V
|
|
E
|
r

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
の頂点の数と辺の数を示す。グラフ
G
の頂点にはそれぞれ
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
 の番号が付けられている。
r
 は始点の番号である。

s
i
,
t
i
 はグラフ
G
 の
i
 番目の辺が結ぶ２つの頂点を表す（有向）。
d
i
 は
i
 番目の辺の重みである。

出力
出力は
|
V
|
 行からなる。各頂点
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
 について、始点
r
 からの最短経路上の重みの総和を順番に出力する。ただし、
r
 からの経路が存在しない場合は INF と出力する。

制約
1
≤
|
V
|
≤
100000
0
≤
d
i
≤
10000
0
≤
|
E
|
≤
500000
G
 に平行辺はない
G
 に自己ループはない
入力例 1
4 5 0
0 1 1
0 2 4
1 2 2
2 3 1
1 3 5
出力例 1
0
1
3
4

入力例 2
4 6 1
0 1 1
0 2 4
2 0 1
1 2 2
3 1 1
3 2 5
出力例 2
3
0
2
INF
*/
