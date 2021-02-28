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

//dp[i円を作る最小枚数]
int en(vi c, int n, int m) {
  vi dp(n + 1);

  rep (i, n) {
    int temp = INT_MAX;
    rep (k, m) {
      if (c[k] <= i + 1) temp = min(temp, dp[i + 1 - c[k]] + 1);
    }

    dp[i + 1] = temp;
  }

  return dp[n];
}

int main() {
  ifstream fin;
  //ofstream fout;
  int n, m;
  string name = "input.txt";

  fin.open(name);
  if (fin.fail()) cout << "file isnt found" << endl;
  else {
    fin >> n >> m;

    vi c(m);

    rep (i, m) fin >> c[i];

    cout << en(c, n, m) << endl;
  }
}


/**
コイン問題
額面がc1, c2,..., cm　円の　m　種類のコインを使って、 n 円を支払うときの、コインの最小の枚数を求めて下さい。各額面のコインは何度でも使用することができます。

入力
n m
c1 c2 ... cm
１行目に整数 n と整数 m が１つの空白区切りで１行に与えられます。２行目に各コインの額面が１つの空白区切りで１行に与えられます。

出力
コインの最小枚数を１行に出力してください。

制約
1 ≤ n ≤ 50,000
1 ≤ m ≤ 20
1 ≤ 額面 ≤ 10,000
額面はすべて異なり、必ず1を含む。
入出力例

入力例 1
15 6
1 2 7 8 12 50
出力例 1
2

入力例 2
65 6
1 2 7 8 12 50
出力例 2
3
*/
