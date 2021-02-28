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
  ll n = 10;
  //container class
  //array access O(1), insert(N), search(N): sortedならO(logN)
  vector<ll> v(n);
  array<ll, 10> a;
  deque<ll> d(n); //双方向キュー. stack<ll> , queue<ll> , pq<ll>

  //list access O(N), insert(1), search(N)
  list<ll> l;
  forward_list<ll> fl;

  //binary tree access O(N), insert(logN), search(logN)
  map<ll, ll> m; //multimap<ll, ll> mm
  set<ll> s; //multiset<ll> ms

  //hash table access O(N), insert(1), search(1)
  unordered_map<ll, ll> um; //unordered_multimap<ll, ll> mm
  unordered_set<ll> us; //unordered_multiset<ll> ms

  srand(time(NULL));

  rep (i, n - 1) v[i] = rand();
  v[n - 1] = 0;
  rep (i, n) a[i] = 1;

  //iterator
  auto itr = v.begin(); //std::vector<ll>::iterator
  auto itr1 = next(itr); // next(itr, 1);
  auto itr2 = next(itr1, 3); // next(itr, 4);
  auto itr3 = prev(itr2, 4); //v.begin();

  cout << "itr " << *itr << endl;
  cout << "itr1 " << *itr1 << endl;
  cout << "itr2 " << *itr2 << endl;
  cout << "itr3 " << *itr3 << endl;

  //lambda formula
  //[]: 外部変数を利用するとき&: 参照, =: 値. 何も変数をつけなければデフォルトの渡し方, 明示的に書くと変数ごとに指定できる.
  //(): 引数
  //{}: operation
  auto fun = [](ll a){ return a == 0; };
  function<void(ll)> fun1 = [](ll a){ cout << a << " "; };

  cout << "all_of(v, ? = 0) " << all_of(all(v), fun) << endl;
  cout << "any_of(v, ? = 0) " << any_of(all(v), fun) << endl;
  cout << "none_of(v, ? = 0) " << none_of(all(v), fun) << endl;

  cout << "v { ";
  for (auto e: v) fun1(e);
  cout << "}" << endl;
}
