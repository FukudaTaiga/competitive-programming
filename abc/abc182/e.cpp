
//このコードだとTLE
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

ll dfs(vvl &v, vpl li, ll h, ll w) {
  stack<pll> stk1;
  stack<pll> stk2;
  stack<pll> stk3;
  stack<pll> stk4;

  for (auto e: li) {
    stk1.push(e);
    stk2.push(e);
    stk3.push(e);
    stk4.push(e);
  }

  ll i, j;
  ll sum = li.size();

  //a
  while (!stk1.empty()) {
    tie(i, j) = stk1.top();
    stk1.pop();

    if ((i - 1) < 0 || v[i - 1][j] == 2) continue;
    else {
      if (v[i - 1][j] == 0) sum++;
      v[i - 1][j] = 1;
      stk1.push(mkpr(i - 1, j));
    }
  }

  //b
  while (!stk2.empty()) {
    tie(i, j) = stk2.top();
    stk2.pop();

    if (h <= (i + 1) || v[i + 1][j] == 2) continue;
    else {
      if (v[i + 1][j] == 0) sum++;
      v[i + 1][j] = 1;
      stk2.push(mkpr(i + 1, j));
    }
  }

  //l
  while (!stk3.empty()) {
    tie(i, j) = stk3.top();
    stk3.pop();

    if ((j - 1) < 0 || v[i][j - 1] == 2) continue;
    else {
      if (v[i][j - 1] == 0) sum++;
      v[i][j - 1] = 1;
      stk3.push(mkpr(i, j - 1));
    }
  }

  //r
  while (!stk4.empty()) {
    tie(i, j) = stk4.top();
    stk4.pop();

    if (w <= (j + 1) || v[i][j + 1] == 2) continue;
    else {
      if (v[i][j + 1] == 0) sum++;
      v[i][j + 1] = 1;
      stk4.push(mkpr(i, j + 1));
    }
  }

  return sum;
}

int main() {
  ll H, W, N, M;
  cin >> H >> W >> N >> M;
  vvl v(H, vl(W));
  vpl li(N);
  rep (i, N) {
    ll a, b;
    cin >> a >> b;
    a--;b--;
    v[a][b] = 1;
    li[i] = mkpr(a, b);
  }
  rep (i, M) {
    ll c, d;
    cin >> c >> d;
    v[c - 1][d - 1] = 2;
  }

  cout << dfs(v, li, H, W) << endl;
}
