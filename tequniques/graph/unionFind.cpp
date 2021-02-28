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
#define mkp make_pair
#define mkt make_tuple
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

//Union find tree
struct unionFind {
  //0~N-1
  // i-j: parent r[j] = i
  // j: root r[j] = -k (k: tree j のノード数)
  vl r;

  UnionFind(ll n) {
    r = vl(n, -1); //全てのノードが独立した状態で初期化.
  }

  //find
  ll root(ll x) {
    if (r[x] < 0) return x;
    else {
      //path complession: findされる度, 深さが浅くなるよう根に直接つける.
      r[x] = root(r[x]);
      return r[x];
    }
  }

  //union
  bool unite(ll x, ll y) {
    x = root(x);
    y = root(y);

    if (x == y) return false; //同じ木の場合は何もしない.
    else {
      //union by rank: 大きい木に小さい木をつける.
      if (r[y] < r[x]) swap(x, y); //xの方が大きい木にしておく.

      r[x] += r[y];
      r[y] = x;
      return true;
    }
  }

  ll size(ll x) {
    return -r[root(x)];
  }
};

int main() {
  
}
