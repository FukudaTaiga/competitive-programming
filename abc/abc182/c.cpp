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
  string N;
  cin >> N;
  ll sz = N.size();
  ll m = 0;

  rep (i, 1 << sz) {
    ll x = i;
    ll sum = 0;
    int k = 0;
    while (k < sz) {
      if (x & 1) {
        sum += N[k] - '0'; //stringをintに変換できる.
      }
      k++;
      x >>= 1;
    }

    if (sum % 3 == 0) m = max(m, (ll) __builtin_popcountll(i));
  }

  if (m != 0) cout << sz - m << endl;
  else cout << -1 << endl;
}
