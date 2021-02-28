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
#define biti(bit, i) ( ((bit) >> i) & 1 )
#define _GLIBCXX_DEBUG

void rec(vvi &w, int s, int bit, int t, int v, int e, vector<vvi> &dp) {
  if (dp[s][bit][t] != -1) {}
  else {
    if (biti(bit, t)) {
      if (__builtin_popcount(bit) == 1) dp[s][bit][t] = w[s][t];
      else {
        int m = INT_MAX;
        int pre = bit & (~(1 << t));

        rep (k, v) {
          if (w[k][t] != -1) {
            rec(w, s, pre, k, v, e, dp);
            if (dp[s][pre][k] != -1) m = min(m, dp[s][pre][k] + w[k][t]);
          }
        }

        if (m != INT_MAX) dp[s][bit][t] = m;
      }
    }
  }
}

//dp[][v]
int tsp(vvi w, int v, int e) {
  vector<vvi> dp(v, vvi(1 << v, vi(v, -1)));
  const int n = (1 << v) - 1;
  int m = INT_MAX;

  rep (i, v) rec(w, i, n, i, v, e, dp);

  rep (i, v) m = min(m, dp[i][n][i]);

  return m; //min_2^v dp[(1 << v) - 1][v];
}

int main() {
  ifstream fin;
  //ofstream fout;
  string name = "input.txt";

  fin.open(name);

  if (fin.fail()) cout << "file isnt found" << endl;
  else {
    int V, E;
    fin >> V >> E;
    //グラフ理論においてついてない木は必ず-1で初期化する.
    vvi w(V, vi(V, -1));
    rep (i, E) {
      int s, t, d;
      fin >> s >> t >> d;
      w[s][t] = d;
    }

    cout << tsp(w, V, E) << endl;
  }
}

/**
巡回セールスマン問題
重み付き有向グラフ G(V,E) について、以下の条件を満たす最短経路の距離を求めて下さい：

ある頂点から出発し、出発点へ戻る閉路である。
各頂点をちょうど１度通る。
入力
|V| |E|
s0 t0 d0
s1 t1 d1
:
s|E|−1 t|E|−1 d|E|−1
|V|, |E| はそれぞれグラフ G の頂点の数と辺の数を示す。グラフ G の頂点にはそれぞれ 0, 1, ..., |V|-1 の番号が付けられている。

si, ti はグラフ G の i 番目の辺が結ぶ２つの頂点を表す（有向）。di は si と ti の間の距離　（i 番目の辺の重み）である。

出力
最短経路の距離を1行に出力する。条件を満たす経路がない場合は -1 と出力する。

制約
2 ≤ |V| ≤ 15
0 ≤ di ≤ 1,000
G に多重辺はない
入力例 1
4 6
0 1 2
1 2 3
1 3 9
2 0 1
2 3 6
3 2 4
出力例 1
16

入力例 2
3 3
0 1 1
1 2 1
0 2 1
出力例 2
-1
*/
