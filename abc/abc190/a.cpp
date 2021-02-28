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

ll N, M;
const ll INF = LONG_MAX;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  while (A != 0 && B != 0) {
    A--;
    B--;
  }

  if (A == 0 && B == 0) {
    if (C == 0) cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;
  }
  else {
    if (A < B) cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;
  }
}
