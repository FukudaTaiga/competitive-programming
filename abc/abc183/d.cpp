#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
using tll = tuple<ll, ll, ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;
using vti = vector<tii>;
using vtl = vector<tll>;

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
const ll INF = LONG_MAX;

//イベント型の解法.
//ソートを利用して, 後は全部見てくだけなので, O(NlogN)
int main() {
  ll N, W;
  cin >> N >> W;
  vpl v(0);

  rep (i, N) {
    ll s, t, p;
    cin >> s >> t >> p;
    v.pb(mkpr(s, p));
    v.pb(mkpr(t, -p));
  }

  sort(all(v));

  ll c = 0;
  rep (i, v.size()) {
    c += v[i].se;

    if (c > W) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}

/**
いもす法を用いた解法.
こちらは配列サイズが大きすぎると扱えない. (= 空間計算量が大きい.)
実装が楽. O(N + T)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
using tll = tuple<ll, ll, ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;
using vti = vector<tii>;
using vtl = vector<tll>;

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
const ll INF = LONG_MAX;

int main() {
  ll N, W;
  cin >> N >> W;
  vl c(VLMAX);
  ll s, t, p;

  rep (i, N) {
    cin >> s >> t >> p;
    c[s] += p;
    c[t] -= p;
  }

  rep (i, VLMAX - 1) {
    c[i + 1] += c[i];

    if (i == VLMAX - 2) if (c[i + 1] > W) {
      cout << "No" << endl;
      return 0;
    }

    if (c[i] > W) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
*/
