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

int main() {
  ll N;
  ll X;
  cin >> N >> X;
  ll cnt = -1;
  ll sum = 0;

  rep (i, N) {
    ll v, p;
    cin >> v >> p;
    sum += v * p;
    //intで比較できる場合はintで比較したほうがよさそう.
    if (100 * X - sum < 0) {
      cnt = i + 1;
      break;
    }
  }

  cout << cnt << endl;
}


/**
以下のコードはdoubleの誤差を考慮しなければならない場合通らない.

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

int main() {
  int N;
  double X;
  cin >> N >> X;
  int cnt = -1;
  double sum = 0;

  rep (i, N) {
    int v, p;
    cin >> v >> p;
    sum += 0.01 * v * p;
    if (X < sum) {
      cnt = i + 1;
      break;
    }
  }

  cout << cnt << endl;
}


abc-189
B - Alcoholic  /
実行時間制限: 2 sec / メモリ制限: 1024 MB

配点 :
200
 点

問題文
高橋君はお酒を
N
 杯飲みました。

i
 番目に飲んだお酒は、量が
V
i
 ml、アルコール度数が
P
i
 % です。

高橋君はアルコールの摂取量が
X
 ml を超えると酔っ払います。

高橋君が酔っ払ったのは何杯目のお酒を飲んでいるときですか。ただし、
N
 杯全てのお酒を飲んだあとでも酔っ払っていない場合は、かわりに -1 を出力してください。

制約
入力は全て整数
1
≤
N
≤
10
3
0
≤
X
≤
10
6
1
≤
V
i
≤
10
3
0
≤
P
i
≤
100
入力
入力は以下の形式で標準入力から与えられる。

N

X

V
1

P
1

⋮

V
N

P
N

出力
高橋君が酔っ払ったのが何杯目のお酒を飲んでいるときか出力せよ。ただし、
N
 杯全てのお酒を飲んだあとでも酔っ払っていない場合は、かわりに -1 を出力せよ。

入力例 1
Copy
2 15
200 5
350 3
出力例 1
Copy
2
1
 杯目のお酒には、
200
×
5
100
=
10
 ml のアルコールが含まれています。

2
 杯目のお酒には、
350
×
3
100
=
10.5
 ml のアルコールが含まれています。

2
 杯目のお酒を飲んでいるときに、初めてアルコールの摂取量が
15
 ml を超えます。

入力例 2
Copy
2 10
200 5
350 3
出力例 2
Copy
2
アルコールの摂取量がちょうど
X
 ml のとき、高橋君はまだ酔っ払っていません。

入力例 3
Copy
3 1000000
1000 100
1000 100
1000 100
出力例 3
Copy
-1
高橋くんはお酒にとても強いようです。
*/
