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

//dp[i: xのi-1文字目まで][j: yのj-1文字目まで]
//0: x = "", y = ""

int mleng(string x, string y) {
  const int lx = x.length();
  const int ly = y.length();
  vvi dp(lx + 1, vi(ly + 1));

  FOR (i, 1, lx + 1) {
    FOR (j, 1, ly + 1) {
      if (x[i - 1] == y[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1; //斜めに増えている部分を見ていけば文字列得られる
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  rep (i, lx + 1) {
    rep (j, ly + 1) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  return dp[lx][ly];
}

int main() {
  ifstream fin;
  //ofstream fout;
  string name = "input.txt";
  int q;
  string x, y;

  fin.open(name);
  if (fin.fail()) cout << "file isnt found" << endl;
  else {
    fin >> q;

    rep (i, q) {
      fin >> x >> y;

      cout << mleng(x, y) << endl;
    }
  }
}

/**
最長共通部分列
最長共通部分列問題 (Longest Common Subsequence problem: LCS)は、２つの与えられた列 X={x1,x2,...,xm} と Y={y1,y2,...,yn} の最長共通部分列を求める問題です。

ある列 Z が X と Y 両方の部分列であるとき、Z を X とY の共通部分列と言います。例えば、X={a,b,c,b,d,a,b}, Y={b,d,c,a,b,a} とすると、列 {b,c,a} は X と Y の共通部分列です。一方、列 {b,c,a} は X と Y の最長共通部分列ではありません。なぜなら、その長さは 3 であり、長さ 4 の共通部分列 {b,c,b,a} が存在するからです。長さが 5 以上の共通部分列が存在しないので、列 {b,c,b,a} は X と Y の最長共通部分列の１つです。

与えられた２つの文字列 X、Yに対して、最長共通部分列 Z の長さを出力するプログラムを作成してください。与えられる文字列は英文字のみで構成されています。

入力
複数のデータセットが与えられます。最初の行にデータセットの数 q が与えられます。続く 2×q 行にデータセットが与えられます。各データセットでは２つの文字列 X, Y がそれぞれ１行に与えられます。

出力
各データセットについて X, Y の最長共通部分列 Z の長さを１行に出力してください。

制約
1≤q≤150
1≤X,Yの長さ≤1,000
X または Y の長さが 100 を超えるデータセットが含まれる場合、q は 20 以下である。
入力例 1
3
abcbdab
bdcaba
abc
abc
abc
bc
出力例 1
4
3
2
*/
