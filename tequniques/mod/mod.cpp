#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
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

struct modint {
  ll r;
  static ll mod;

  static void set(ll m) {
    if (0 < m) mod = m;
  }

  modint(const ll v = 0LL) {
    ll x = v % mod;
    if (x < 0) x += mod;
    r = x;
  }

  ll value() { return (r < 0) ? r + mod : r; }

  modint operator-() { return modint(r - mod); }
  modint& operator+=(const modint& a) { r = (r + a.r) % mod; if (r < 0) r += mod; return *this; }
  modint& operator++() { r++; if (r < 0) r += mod; return *this; }
  modint& operator-=(const modint& a) { r = (r - a.r) % mod; if (r < 0) r += mod; return *this; }
  modint& operator--() { r--; if (r < 0) r += mod; return *this; }
  modint& operator*=(const modint& a) { r = (r * a.r) % mod; if (r < 0) r += mod; return *this; }
  modint& operator=(const modint& a) { r = a.r; return *this; }

  //r*y = 1 % mod <=> -mod*x + r*y = 1
  modint inv() {
    if (r == 0) return modint(0);

    ll n = mod, m = r;
    ll x = 0, y = 1;
    ll z = 1, w = -(n / m);

    while (n % m != 0) {
      n %= m;
      swap(n, m);
      x -= z * (n / m);
      y -= w * (n / m);
      swap(x, z);
      swap(y, w);
    }

    return modint(y);
  }

  modint pow(ll n) {
    ll x = 1;
    ll a = r;
    while (n != 0) {
      if (n & 1) x *= a;

      n >>= 1;
      a *= a;
    }

    return modint(x);
  }

  friend ostream& operator<<(ostream &os, const modint &m){
    os << m.r;
    return os;
  }
};
modint operator+(const modint& a, const modint& b) { return modint(a.r + b.r); }
modint operator-(const modint& a, const modint& b) { return modint(a.r - b.r); }
modint operator*(const modint& a, const modint& b) { return modint(a.r * b.r); }
bool operator==(const modint& a, const modint& b) { return a.r == b.r; }
bool operator!=(const modint& a, const modint& b) { return !(a == b); }
bool operator<(const modint & a, const modint& b) { return a.r < b.r; }
bool operator<=(const modint& a, const modint& b) { return a.r <= b.r; }
bool operator>(const modint & a, const modint& b) { return !(a <= b); }
bool operator>=(const modint& a, const modint& b) { return !(a < b); }
ll modint::mod;

int main() {
  uint mod = 13;
  using M = modint;

  M::mod = mod;

  M x(1);
  M y(3);
  M z(11);

  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  cout << "z: " << z << endl;
  cout << "x - y: "<< x - y << endl;
  cout << "y * z: " << y * z << endl;
  cout << "x + y + z: " << x + y + z << endl;
  cout << "x * (y + z): " << x * (y + z) << endl;
  cout << "x + y * z: " << x + y * z << endl;
  cout << "y^3: " << y.pow(3) << endl;
  cout << "x^-1: " << x.inv() << endl;
  cout << "y^-1: " << y.inv() << endl;
  cout << "z^-1: " << z.inv() << endl;
  cout << "x == x: " << (x == x) << endl;
  cout << "y != z: " << (y != z) << endl;
  cout << "z < z^-1: " << (z < z.inv()) << endl;
  cout << "z <= y + x * 10: " << (z <= y + x * modint(10)) << endl;
  x = modint(9);
  cout << "x = 9" << endl << "x: " << x << endl;;
}
