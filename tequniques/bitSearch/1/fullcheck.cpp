#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
#define FOR(i, s, n) for (ll i = (s); i < (ll) (n); i++)
#define rep(i, n) FOR(i, 0, n)

bool check(vl a, ll m, int n) {
  ll i, x, sum;
  //bit full search
  FOR (k, 0, 1 << n) {
    i = 0;
    x = k;
    sum = 0;
    while (x > 0) {
      if (x & 1) sum += a[i];
      x >>= 1;
      i++;
    }
    if (sum == m) return true;
  }
  return false;
}

int main() {
  int N;
  vl a;
  int q;
  ll m;
  char name[16] = "input.txt";
  ifstream fin;
  ofstream fout;

  fin.open(name);
  if (fin.fail()) cout << "input file doesnt exists" << endl;

  fin >> N;
  a = vl(N);
  FOR(i, 0, N) fin >> a[i];
  fin >> q;

  rep(i, q) {
    fin >> m;
    (check(a, m, N)) ? cout << "yes" << endl : cout << "no" << endl;
  }
}

/**
総当たり
長さ n の数列 A と整数 m に対して、A の要素の中のいくつかの要素を足しあわせて m が作れるかどうかを判定するプログラムを作成してください。A の各要素は１度だけ使うことができます。

数列 A が与えられたうえで、質問として q 個の mi が与えれるので、それぞれについて "yes" または "no" と出力してください。

入力
１行目に n、２行目に A を表す n 個の整数、３行目に q、４行目に q 個の整数 miが与えられます。

出力
各質問について A の要素を足しあわせて mi を作ることができれば yes と、できなければ no と出力してください。

制約
n≤20
q≤200
1≤Aの要素≤2,000
1≤mi≤2,000
入力例 1
5
1 5 7 10 21
4
2 4 17 8
出力例 1
no
no
yes
yes
*/
