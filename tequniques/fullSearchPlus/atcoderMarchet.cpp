/**
これは時間かかりすぎ.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
#define FOR(i, s, n) for (int i = (s); i < (ll) (n); i++)
#define rep(i, n) FOR(i, 0, n)

#define MAX 1000000000
#define MIN 1

int main() {
  int N;
  cin >> N;
  vll a(N);
  vll b(N);

  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
  }

  ll mia = *min_element(a.begin(), a.end());
  ll mib = *min_element(b.begin(), b.end());
  ll maa = *max_element(a.begin(), a.end());
  ll mab = *max_element(b.begin(), b.end());

  ll first = min(mia, mib);
  ll last = max(maa, mab);

  ll mtime = LLONG_MAX;
  ll sum = 0;

  for (ll i = first; i <= last; i++) {
    for (ll j = first; j <= last; j++) {
      FOR(k, 0, N) {
        sum += abs(a[k] - i);
        sum += abs(b[k] - a[k]);
        sum += abs(j - b[k]);
      }
      mtime = min(mtime, sum);
      sum = 0;
    }
  }

  cout << mtime << endl;
}
*/

/**
square869120Contest B
実行時間制限: 1 sec / メモリ制限: 976 MB

配点：
300
 点

問題文
AtCoder マーケットは、
1

000

000

000
 個のマスが
1
 列につながったマス目で表されるスーパーマーケットである。ここでは、左から
i
 番目のマスを「マス
i
」とする。

ある日、
N
 人の買い物客が AtCoder マーケットに来る。
i
 人目の買い物客は、マス
A
i
 にある品物とマス
B
i
 にある品物を買う。

square1001 君は、AtCoder マーケットに入口と出口を
1
 つずつ設置することにした。
入口と出口はいずれかのマス目に設置する。入口と出口は同じ場所にあってもよい。

そのとき、買い物客は次のような経路で移動する。

まず、入口からスタートする。マス
A
i
 と
B
i
 を経由して、出口でゴールする。
すべての買い物客について、隣り合ったマス目に進むのに
1
 秒かかるとき、最適に入口と出口を設置したときの「すべての買い物客の移動時間の合計」の最小値を求めなさい。

制約
1
≤
N
≤
30
1
≤
A
i
<
B
i
≤
1

000

000

000
小課題・得点
この問題はいくつかの小課題に分けられ、その小課題のすべてのテストケースに正解した場合に「この小課題に正解した」とみなされます。
提出したソースコードの得点は、正解した小課題の点数の合計となります。

(195 点)：
1
≤
A
i
<
B
i
≤
100
 を満たす。また、移動時間が最小となるような入口と出口のマスは、マス
1
,
2
,
3
,
.
.
.
,
100
 のどれかである。
(105 点)：追加の制約はない。
入力
入力は以下の形式で標準入力から与えられます。

N

A
1

B
1

A
2

B
2

 :  :
A
N

B
N

出力
「すべての買い物客の移動時間の合計」の最小値を、秒単位で出力してください。

注意
この問題の制約上、答えが
32
 ビット整数型の範囲に収まらない可能性があることに注意してください。
例えば C / C++ では、long long 型を使うなどで、
64
 ビット整数型を使用することができます。
 */
