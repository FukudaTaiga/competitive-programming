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
  int N;
  ll C;
  cin >> N >> C;

  vector<pair<ll, ll>> a(N), b(N);
  ll m = 0;

  rep (i, N) {
    ll p, q, r;
    cin >> p >> q >> r;
    a[i] = make_pair(p, r);
    b[i] = make_pair(q, r);
    m = max(q, m);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll day = 1;
  ll sum = 0;
  ll cost = 0;
  ll i = 0, j = 0;

  while (day < m + 1) {
    while (day == a[i].first) {
      cost += a[i].second;
      i++;
    }

    sum += min(cost, C);

    while (day == b[j].first) {
      cost -= b[j].second;
      j++;
    }

    day++;
  }

  cout << sum << endl;
}

/**
いもす法による解法も実装できるが,
今回の制限ではdayが極端に大きくなるため不可能.

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
  int N;
  ll C;
  cin >> N >> C;

  vl a(N), b(N), c(N);
  ll m = 0;

  rep (i, N) {
    cin >> a[i] >> b[i] >> c[i];
    m = max(b[i], m);
  }

  ll sum;
  vl v(m);

  rep (i, N) {
    if ((a[i] - 1 <= i) && (i <= b[i] - 1)) {
      FORLL (j, a[i], b[i] + 1) {
        if (v[i] + c[i] < C) v[i] += c[i];
      	else v[i] = C;
      }
    }
  }

  sum = accumulate(v.begin(), v.end(), 0LL);
  cout << sum << endl;
}
*/
