#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define f first
#define s second
#define FOR(i, s, n) for (int i = (s); i < (int) (n); i++)
#define FORLL(i, s, n) for (ll i = (s); i < (ll) (n); i++)
#define FORIT(itr, t) for (auto itr = (t).begin(); itr != (t).end(); ++itr)
#define rep(i, n) FOR(i, 0, n)
#define biti(bit, i) ( (bit >> i) & 1 )
#define _GLIBCXX_DEBUG

const ll INF = LONG_MAX;

int check(vi v, vector<pi> cond) {
  int mini = 0;
  for (auto p : cond) {
    if (v[p.f] > 0 && v[p.s] > 0) mini++;
  }

  return mini;
}


int bi(vi &v, int k, int K, vector<pi> cond, vector<pi> put, int &maxi) {
  int ma = 0;
  if (k == K - 1) {
    v[put[k].f] += 1;
    maxi = max(maxi, check(v, cond));
    v[put[k].f] -= 1;

    v[put[k].s] += 1;
    maxi = max(maxi, check(v, cond));
    v[put[k].s] -= 1;
  }
  else {
    v[put[k].f] += 1;
    maxi = max(maxi, bi(v, k + 1, K, cond, put, ma));
    v[put[k].f] -= 1;

    v[put[k].s] += 1;
    maxi = max(maxi, bi(v, k + 1, K, cond, put, ma));
    v[put[k].s] -= 1;
  }

  return maxi;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<pi> cond(M);
  rep (i, M) {
    int p, q;
    cin >> p >> q;
    cond[i] = make_pair(p - 1, q - 1);
  }

  int K;
  cin >> K;

  vector<pi> put(K);
  rep (i, K) {
    int p, q;
    cin >> p >> q;
    put[i] = make_pair(p - 1, q - 1);
  }

  vi v(N);
  int ans = -1;
  bi(v, 0, K, cond, put, ans);

  cout << ans << endl;
}

//なんかdfsで置いてってるけど, 明らかに全探索したほうがいい. bitでできる.
