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
#define biti(bit, i) ( (bit >> i) & 1 )
#define _GLIBCXX_DEBUG

const ll INF = LONG_MAX;

int main() {
  ll N;
  cin >> N;
  ll cnt = 0;

  while (N % 2 == 0) N /= 2;

  ll sq = sqrt(N);

  for (int i = 1; i <= sq; i++) if (N % i == 0) cnt += 2;

  if (sq * sq == N) cnt--;

  cout << cnt * 2 << endl;
}

/**
この問題は数学的考察で解ける範囲だった.
焦らず解いた方が結局プラスになる.
*/
