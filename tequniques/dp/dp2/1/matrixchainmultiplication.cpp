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
#define _GLIBCXX_DEBUG

void coutmat(vvi v, int n) {
  int m = 0;
  rep (i, n) {
    rep (j, n) {
      int x = v[i][j];
      int k = 0;
      while (x / 10 != 0) {
        x /= 10;
        k++;
      }
      m = max(m, k);
    }
  }

  rep (i, n) {
    rep (j, n) {
      int k = 0;
      int x = v[i][j];
      while (x / 10 != 0) {
        x /= 10;
        k++;
      }
      cout << " ";
      cout << v[i][j];
      rep (l, m - k) cout << " ";
    }
    cout << endl;
  }
}

//二分割する全パターンを探索. より短い範囲は計算済み.
void rec(vector<pi> &v, int i, int j, vvi &dp) {
  if (j - i == 0) dp[i][j] = 0;
  else if (j - i == 1) dp[i][j] = v[i].f * v[i].s * v[j].s;
  else {
    if (dp[i][j] != -1) {}
    else {
      int m = INT_MAX;

      rep (k, j - i) {
        rec(v, i, i + k, dp);
        rec(v, i + k + 1, j, dp);
        m = min(m,
          dp[i][i + k] + dp[i + k + 1][j] + v[i].f * v[i + k].s * v[j].s
        );
      }

      dp[i][j] = m;
    }
  }
}

//dp[l][r]: M_l ... M_{r-1}を計算するために必要な最小計算量.
int minmul(vector<pi> v, int n) {
  vvi dp(n, vi(n, -1));

  rec(v, 0, n-1, dp);

  //coutmat(dp, n);

  return dp[0][n-1];
}

int main() {
  ifstream fin;
  //ofstream fout;
  string name = "input.txt";

  fin.open(name);
  if (fin.fail()) cout << "file isnt found" << endl;
  else {
    int n;
    fin >> n;
    vector<pi> v(n);

    rep (i, n) {
      int row, column;
      fin >> row >> column;
      v[i] = make_pair(row, column);
    }

    cout << minmul(v, n) << endl;
  }
}


/**
ALDS1
連鎖行列積
n 個の行列の連鎖 M1,M2,M3,...,Mn が与えられたとき、スカラー乗算の回数が最小になるように積 M1M2M3...Mn の計算順序を決定する問題を連鎖行列積問題(Matrix-Chain Multiplication problem)と言います。

n 個の行列について、行列 Mi の次元が与えられたとき、積 M1M2...Mn の計算に必要なスカラー乗算の最小の回数を求めるプログラムを作成してください。

入力
入力の最初の行に、行列の数 n が与えられます。続く n 行で行列 Mi(i=1...n) の次元が空白区切りの２つの整数 r、c で与えられます。r は行列の行の数、c は行列の列の数を表します。

出力
最小の回数を１行に出力してください。

制約
1≤n≤100
1≤r,c≤100
入力例 1
6
30 35
35 15
15 5
5 10
10 20
20 25
出力例 1
15125
*/
