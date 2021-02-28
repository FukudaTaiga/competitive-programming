#include <bits/stdc++.h>
using namespace std;

long long euclid(long long a, long long b) {
  if (abs(a) < abs(b)) swap(a, b);

  while (b) {
    a %= b;
    swap(a, b);
  }

  return a;
}

pair<long long, long long> ex_euc(long long n, long long m, long long mod) {
  int x = 0, y = 1, z = 1, w = - (n / m);

  while (n % m != 0) {
    n %= m;
    swap(n, m);
    x -= ((n / m) % mod) * (z % mod);
    y -= ((n / m) % mod) * (w % mod);
    x %= mod;
    y %= mod;
    z %= mod;
    w %= mod;
    swap(x, z);
    swap(y, w);
  }

  return make_pair(x, y);
}

//ゴリ押しだと計算量が多くできない. modの逆元を用いた解法が必要.

int main() {
  int T;
  long long N, S, K;

  cin >> T;

  for (int i = 0; i < T; i++) {
    long long x, y;
    cin >> N >> S >> K;
    long long d = abs(euclid(euclid(N, S), K));

    N /= d;
    K /= d;
    S /= d;

    if (euclid(N, K) == 1) {
      if (K < N) tie(y, x) = ex_euc(N, K, N);
      else tie(x, y) = ex_euc(K, N, N);

      x = ((x % N) * (-S % N)) % N;

      if (x < 0) x += N;

      cout << x << endl;
    }
    else cout << -1 << endl;
  }
}

/**
問題文
円周上に N個の椅子が並べられています。
そのうち1つは玉座です。

高橋君は最初、玉座から時計回りに数えて
S個隣の椅子に座っており、次の行動を繰り返します。

行動：いま座っている椅子から時計回りに数えてK個隣の椅子に移動し座る。

高橋君がはじめて玉座に座ることができるのは何回目の行動の後ですか？　
ただし、玉座に座ることが永遠にできない場合は、代わりに -1 を出力してください。

T個のテストケースに答えてください。

制約
1≤T≤100
2≤N≤10^9
1≤S<N
1≤K≤10^9

input
4
10 4 3
1000 11 2
998244353 897581057 595591169
10000 6 14

output
2
-1
249561088
3571
*/
