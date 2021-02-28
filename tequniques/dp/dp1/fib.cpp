#include <bits/stdc++.h>
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

ll fibdp(int n) {
  vl v(2, 1);
  int i = 1;

  while (i < n) {
    v[0] = v[0] + v[1];
    swap(v[0], v[1]);
    i++;
  }

  return v[1];
}

ll fibrec(int n) {
  if (n <= 0 || n == 1) return 1;
  else return fibrec(n - 1) + fibrec(n - 2);
}

int main() {
  int n;

  cout << "calc fib" << endl << "type suffix n" << endl;
  cin >> n;

  cout << fibdp(n) << endl;
  //cout << fibrec(n) << endl;
}


/**
フィボナッチ数列
フィボナッチ数列の第 n 項の値を出力するプログラムを作成してください。
ここではフィボナッチ数列を以下の再帰的な式で定義します：

fib(n)=⎧⎩⎨⎪⎪1　1　fib(n−1)+fib(n−2)(n=0)(n=1)
入力
１つの整数 n が与えられます。

出力
フィボナッチ数列の第 n 項の値を出力してください。

制約
0≤n≤44
入力例 1
3
出力例 1
3
*/
