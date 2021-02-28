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

  vl a(n), b(n);

  rep (i, n) cin >> a[i];
  rep (i, n) cin >> b[i];

  ll sum = 0;

  rep (i, n) sum += a[i] * b[i];

  if (sum == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}
