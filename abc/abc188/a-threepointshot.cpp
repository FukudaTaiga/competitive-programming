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
  int X, Y;
  cin >> X >> Y;

  int a, b;
  a = max(X, Y);
  b = min(X, Y);

  if (a < b + 3) cout << "Yes" << endl;
  else cout << "No" << endl;
}
