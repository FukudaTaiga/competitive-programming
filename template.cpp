#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using pll = pair<ll, ll>;
using vpl = vector<pll>;

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define mkt make_tuple
#define rep2(i, m, n) for (ll i = (m); i < (ll) (n); i++)
#define rep(i, n) rep2(i, 0LL, n)
#define per2(i, n, m) for (ll i = n - 1; i >= m; i--)
#define per(i, n) per2(i, n, 0LL)
#define repit(itr, t) for (auto itr = (t).begin(); itr != (t).end(); ++itr)
#define all(c) begin(c), end(c)
#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define biti(bit, i) ( (bit >> i) & 1 )
#define _GLIBCXX_DEBUG

template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U> p) {
  os << "(" << p.fi << " " << p.se << ")" << endl;
  return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T> v) {
  os << "{ ";
  for (auto e: v) os << e << " ";
  os << "}";
  return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<vector<T>> vv) {
  os << "{" << endl;
  for (auto v: vv) {
    for (auto e: v) os << e << " ";
    os << endl;
  }
  os << "}";
  return os;
}

const ll VLMAX = 200010;
const ll MOD = 1000000007;
const ll INF = LONG_MAX;

int main() {

}
