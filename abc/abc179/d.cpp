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
const ll MOD = 998244353;
const ll INF = LONG_MAX;

int main() {
  ll n, k;
  cin >> n >> k;
  ll l, r;
  //iまでの総数 i:0~n
  vpl v(k);
  vl cnt(n);
  //累積和で更新するから. 応用.
  cnt[0] = 1;
  cnt[1] = -1;
  rep (i, k) {
    cin >> l >> r;
    v[i] = mkp(l, r+1);
  }

  rep (i, n) {
    //前しか更新しないのでcnt[i]が正しい値ならok.
    //更新値を蓄積していき, 累積和を取っていけば問題ない.
    if (i > 0) cnt[i] += cnt[i-1];
    cnt[i] %= MOD;

    rep (j, k) {
      tie(l, r) = v[j];
      if (i+l < n) {
        cnt[i+l] += cnt[i];
        cnt[i+l] %= MOD;
      }
      if (i+r < n) {
        cnt[i+r] -= cnt[i];
      	cnt[i+r] %= MOD;
      }
    }
    if (cnt[i] < 0) cnt[i] += MOD;
  }

  cout << cnt[n-1] << endl;
}
