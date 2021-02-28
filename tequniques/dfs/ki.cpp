#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define FOR(i, s, n) for (int i = (s); i < (int) (n); i++)
#define FORLL(i, s, n) for (ll i = (s); i < (ll) (n); i++)
#define FORIT(itr, t) for (auto itr = t.begin(); itr != t.end(); ++itr)
#define rep(i, n) FOR(i, 0, n)
#define _GLIBCXX_DEBUG

int N, Q;

void dfs(vvi &tree, int i, vl &score, vector<bool> &checker) {
  checker[i] = true;
  rep (j, tree[i].size()) {
    if (!checker[tree[i][j]]) {
      score[tree[i][j]] += score[i];
      dfs(tree, tree[i][j], score, checker);
    }
    else continue;
  }
}

//nodeの番号とvectorの添え字がずれていることが多く、これに起因するミスが多いので注意.
int main() {
  cin >> N >> Q;
  vvi tree(N);
  vl score(N);
  vector<bool> checker(N, false);

  rep (i, N - 1) {
    int a, b;
    cin >> a >> b;
    tree[a - 1].push_back(b - 1);
    tree[b - 1].push_back(a - 1);
  }

  rep (i, Q) {
    int p, x;
    cin >> p >> x;
    //先にxを記録しておく
    score[p - 1] += x;
  }

  dfs(tree, 0, score, checker);

  rep (i, N) cout << score[i] << " ";
  cout << endl;
}


/**
//単純なdfsだとO(NQ)となってしまい間に合わない
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define FOR(i, s, n) for (int i = (s); i < (int) (n); i++)
#define FORLL(i, s, n) for (ll i = (s); i < (ll) (n); i++)
#define FORIT(itr, t) for (auto itr = t.begin(); itr != t.end(); ++itr)
#define rep(i, n) FOR(i, 0, n)
#define _GLIBCXX_DEBUG

void update(vvi &tree, int p, int x, vl &score) {
  score[p] += x;
  rep (i, distance(tree[p].begin(), tree[p].end())) update(tree, tree[p][i], x, score);
}

//nodeの番号とvectorの添え字がずれていることが多く、これに起因するミスが多いので注意.
int main() {
  int N, Q;
  cin >> N >> Q;
  vvi tree(N);
  vl score(N);

  rep (i, N - 1) {
    int a, b;
    cin >> a >> b;
    tree[a - 1].push_back(b - 1);
  }

  rep (i, Q) {
    int p, x;
    cin >> p >> x;
    update(tree, p - 1, x, score);
  }

  rep (i, N) cout << score[i] << " ";
  cout << endl;
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define FOR(i, s, n) for (int i = (s); i < (int) (n); i++)
#define FORLL(i, s, n) for (ll i = (s); i < (ll) (n); i++)
#define FORIT(itr, s, e) for (auto itr = (s); itr != (e); ++itr)
#define rep(i, n) FOR(i, 0, n)
#define _GLIBCXX_DEBUG

set<int> partial(vector<set<int>> tree, int p) {
  stack<int> stk;
  stk.push(p - 1);
  set<int> s;

  while (!stk.empty()) {
    int temp = stk.top();
    s.insert(temp);
    //追加要素なし
    bool b = true;

    FORIT(itr, tree[temp].begin(), tree[temp].end()) {
      if (s.find(*itr) == s.end()) {
        stk.push(*itr);
        b = false;
      }
    }

    if (b) stk.pop();
  }

  return s;
}

void update(vector<set<int>> tree, int p, ll x, vl &score) {
  set<int> s = partial(tree, p);
  FORIT(itr, s.begin(), s.end()) {
    score[*itr] += x;
  }
}

//nodeの番号とvectorの添え字がずれていることが多く、これに起因するミスが多いので注意.
int main() {
  int N, Q;
  cin >> N >> Q;
  vector<set<int>> tree(N, set<int>());
  vl score(N);

  rep (i, N - 1) {
    int a, b;
    cin >> a >> b;
    tree[a - 1].insert(b - 1);
  }

  rep (i, Q) {
    int p, x;
    cin >> p >> x;
    update(tree, p, x, score);
  }

  rep (i, N) cout << score[i] << " ";
  cout << endl;
}
*/

/**
abc138-D
実行時間制限: 2 sec / メモリ制限: 1024 MB

配点 :
400
 点

問題文
1
 から
N
 までの番号がついた
N
 個の頂点を持つ根付き木が与えられます。 この木の根は頂点
1
 で、
i
 番目の辺
(
1
≤
i
≤
N
−
1
)
 は頂点
a
i
 と頂点
b
i
 を結びます。

各頂点にはカウンターが設置されており、はじめすべての頂点のカウンターの値は
0
 です。

これから、以下のような
Q
 回の操作が行われます。

操作
j

(
1
≤
j
≤
Q
)
: 頂点
p
j
 を根とする部分木に含まれるすべての頂点のカウンターの値に
x
j
 を足す。
すべての操作のあとの各頂点のカウンターの値を求めてください。

制約
2
≤
N
≤
2
×
10
5
1
≤
Q
≤
2
×
10
5
1
≤
a
i
<
b
i
≤
N
1
≤
p
j
≤
N
1
≤
x
j
≤
10
4
与えられるグラフは木である。
入力中の値はすべて整数である。
入力
入力は以下の形式で標準入力から与えられる。

N

Q

a
1

b
1

:

a
N
−
1

b
N
−
1

p
1

x
1

:

p
Q

x
Q

出力
すべての操作のあとの各頂点のカウンターの値を、頂点
1
,
2
,
…
,
N
 の順に空白区切りで出力せよ。

入力例 1
Copy
4 3
1 2
2 3
2 4
2 10
1 100
3 1
出力例 1
Copy
100 110 111 110
この入力中の木は次のようなものです。

図

各操作で、頂点のカウンターの値は次のように変化します。

操作
1
: 頂点
2
 を根とする部分木に含まれるすべての頂点、すなわち頂点
2
,
3
,
4
 のカウンターの値に
10
 を足す。頂点
1
,
2
,
3
,
4
 のカウンターの値はそれぞれ
0
,
10
,
10
,
10
 となる。
操作
2
: 頂点
1
 を根とする部分木に含まれるすべての頂点、すなわち頂点
1
,
2
,
3
,
4
 のカウンターの値に
100
 を足す。頂点
1
,
2
,
3
,
4
 のカウンターの値はそれぞれ
100
,
110
,
110
,
110
 となる。
操作
3
: 頂点
3
 を根とする部分木に含まれるすべての頂点、すなわち頂点
3
 のカウンターの値に
1
 を足す。頂点
1
,
2
,
3
,
4
 のカウンターの値はそれぞれ
100
,
110
,
111
,
110
 となる。
入力例 2
Copy
6 2
1 2
1 3
2 4
3 6
2 5
1 10
1 10
出力例 2
Copy
20 20 20 20 20 20
*/

/**
一度の操作が N 個の頂点すべてに影響する可能性があるため、操作をそのままシミュレートするとカウン
ターへの加算を NQ 回行うことになり実行時間制限に間に合いません。*1
このような木に関する問題では、木の代わりに 1 − 2 − 3 − . . . − N という直線的なグラフを考えると助け
になることがあり、今回はその好例です。この問題でグラフが直線的であるとすると、次のような線形時間の
解法が考えられます。
1. c1, c2, . . . , cN = 0, 0, . . . , 0 とする。
2. 各操作 j に対し、cpj に xj を加算する。
3. i = 2, . . . , N の順に、ci に ci−1 を加算する。
4. c1, c2, . . . , cN を出力する。
そして、この解法は木に対してもほぼそのまま利用できます。具体的には、手順 3 の ci−1 を cqi
(qi は頂点
i の親) と読み換えればそのまま元の問題への解法となります。、この処理を根に近い頂点から順に行えば元の
問題への解法となります。(8/19 0:05 JST 修正)
*2 *3

*/
