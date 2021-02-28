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
  string S;
  cin >> S;

  bool b = !(S.size() == 1 && 8 == S[0] - '0');

  for (ll i = 11; i < 100 && S.size() == 2; i++) {
    vl a = {i / 10, i % 10};
    if (i % 8 != 0 || a[0] == 0 || a[1] == 0) continue;

    vl c = {-1, -1};

    rep (j, 2) rep (k, 2) {
      if (a[j] == S[k] - '0' && find(all(c), k) == c.end()) c[j] = k;
    }
    if (c[0] != -1 && c[1] != -1) b = false;
  }

  for (ll i = 100; i < 1000 && b; i++) {
    vl a = {i / 100, (i % 100) / 10, i % 10};
    if (i % 8 != 0 || a[0] == 0 || a[1] == 0 || a[2] == 0) continue;

    vl c = {-1, -1, -1};

    rep (j, 3) rep (k, S.size()) {
      if (a[j] == S[k] - '0' && find(all(c), k) == c.end()) c[j] = k;
    }
    if (c[0] != -1 && c[1] != -1 && c[2] != -1) b = false;
  }

  if (b) cout << "No" << endl;
  else cout << "Yes" << endl;
}
