#include <bits/stdc++.h>
#include <fstream>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
#define FOR(i, s, n) for (int i = (s); i < (int) (n); i++)
#define FORLL(i, s, n) for (ll i = (s); i < (ll) (n); i++)
#define FORIT(itr, s, e) for (auto itr = (s); itr != (e); ++itr)
#define rep(i, n) FOR(i, 0, n)

//dp[i個][重さj]
int nap(int n, int w, vi a, vi b) {
  vvi dp(n + 1, vi(w + 1));

  rep (i, n) {
    rep (j, w + 1) {
      if (b[i] > j) dp[i + 1][j] = dp[i][j];
      else dp[i + 1][j] = max(dp[i][j], dp[i][j - b[i]] + a[i]);
      //0個から始めないとdpの初期値を調整しないといけなくなる. => 0, 1, ... nまでが必要になる.
    }
  }

  return dp[n][w];
}

int main() {
  int n, w;
  ifstream fin;
  //ofstream fout;
  string name = "input.txt";

  fin.open(name);

  if (fin.fail()) cout << "file can't open" << endl;
  else {
    fin >> n >> w;

    vi a(n);
    vi b(n);

    rep (i, n) fin >> a[i] >> b[i];

    cout << nap(n, w, a, b) << endl;
  }
}

/**
0-1 ナップザック問題
価値が vi 重さが wi であるような N 個の品物と、容量が W のナップザックがあります。次の条件を満たすように、品物を選んでナップザックに入れます：

選んだ品物の価値の合計をできるだけ高くする。
選んだ品物の重さの総和は W を超えない。
価値の合計の最大値を求めてください。

入力
１行目に２つの整数　N、W　が空白区切りで１行に与えられます。 続く N 行で i 番目の品物の価値 vi と重さ wi が空白区切りで与えられます。

出力
価値の合計の最大値を１行に出力してください。

制約
1 ≤ N ≤ 100
1 ≤ vi ≤ 1,000
1 ≤ wi ≤ 1,000
1 ≤ W ≤ 10,000
入出力例

入力例 1
4 5
4 2
5 2
2 1
8 3
出力例 1
13

入力例 2
2 20
5 9
4 10
出力例 2
9
*/
