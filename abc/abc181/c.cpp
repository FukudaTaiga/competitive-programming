#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;

#define fi first
#define se second
#define pb push_back
#define mkpr make_pair
#define mktp make_tuple
#define rep2(i, s, n) for (ll i = (s); i < (ll) (n); i++)
#define rep(i, n) rep2(i, 0LL, n)
#define repit(itr, t) for (auto itr = (t).begin(); itr != (t).end(); ++itr)
#define all(c) begin(c), end(c)
#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define biti(bit, i) ( (bit >> i) & 1 )
#define _GLIBCXX_DEBUG

template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

const ll VLMAX = 200010;
const ll MOD = 1000000007;
const ll INF = LONG_MAX;


int main() {
  ll N;
  cin >> N;

  vpl v(N);
  vector<vector<double>> k(N, vector<double>(0));

  rep(i, N) {
    ll x, y;
    cin >> x >> y;
    v[i] = mkpr(x, y);
    rep (j, i) {
      double a;
      if (v[i].fi == v[j].fi) a = INF;
      else a = 1.0 * (v[i].se - v[j].se) / (v[i].fi - v[j].fi);
      k[i].pb(a);
      rep2 (l, j + 1, i) if (a == k[l][j]) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}
