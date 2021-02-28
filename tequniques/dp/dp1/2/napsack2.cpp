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
#define FOR(i, s, n) for (int i = (s); i < (int) (n); i++)
#define FORLL(i, s, n) for (ll i = (s); i < (ll) (n); i++)
#define FORIT(itr, s, e) for (auto itr = (s); itr != (e); ++itr)
#define rep(i, n) FOR(i, 0, n)

//dp[i: 重さi以下]
int nap2(vi a, vi b, int n, int w) {
  vi dp(w + 1);

  rep (i, w) {
    int m = dp[i];
    rep (k, n) {
      if (b[k] <= i + 1) m = max(m, dp[i + 1 - b[k]] + a[k]);
    }
    //cout << "dp[" << i << "] = " << m << endl;

    dp[i + 1] = m;
  }

  return dp[w];
}

int main() {
  ifstream fin;
  //ofstream fout;
  int n, w;
  vi a, b;
  string name = "input.txt";

  fin.open(name);
  if (fin.fail()) cout << "file doesnt exist" << endl;
  else {
    fin >> n >> w;
    a = vi(n);
    b = vi(n);

    rep (i, n) fin >> a[i] >> b[i];

    cout << nap2(a, b, n, w) << endl;
  }
}


/**
時間制限 : 1 sec, メモリ制限 : 131072 KB
ナップザック問題
価値が vi 重さが wi であるような N 種類の品物と、容量が W のナップザックがあります。

次の条件を満たすように、品物を選んでナップザックに入れます：

選んだ品物の価値の合計をできるだけ高くする。
選んだ品物の重さの総和は W を超えない。
同じ種類の品物はいくつでも選ぶことができる。
価値の合計の最大値を求めてください。

入力
N W
v1 w1
v2 w2
:
vN wN
１行目に２つの整数　N、W　が空白区切りで１行に与えられる。

続く N 行で i 番目の品物の価値と重さが空白区切りで与えられる。

出力
価値の合計の最大値を１行に出力する。

制約
1 ≤ N ≤ 100
1 ≤ vi ≤ 1000
1 ≤ wi ≤ 1000
1 ≤ W ≤ 10000
入力例 1
4 8
4 2
5 2
2 1
8 3
出力例 1
21

入力例 2
2 20
5 9
4 10
出力例 2
10
入力例 3
3 9
2 1
3 1
5 2
出力例 3
27
*/
