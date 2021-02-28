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

int main() {
  int n;
  cin >> n;
  ll N = (ll) pow(2, n);
  vector<pair<ll, ll>> a(N);

  FORLL (i, 0, N) {
    ll t;
    cin >> t;
    a[i] = make_pair(t, i + 1);
  }

  while (N > 2) {
    int j = 0;
    while (j < N / 2) {
      if (a[j].first < a[j + 1].first) a.erase(a.begin() + j);
      else a.erase(a.begin() + j + 1);
      j++;
    }

    N = N / 2;
  }

  ll ans;

  if (a[0].first < a[1].first) ans = a[0].second;
  else ans = a[1].second;

  cout << ans << endl;
}
