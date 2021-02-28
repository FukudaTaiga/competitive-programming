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
  int N, M;
  cin >> N >> M;
  vvi r(N, vi(N));
  int x, y;

  rep(i, M) {
    cin >> x >> y;
    r[x - 1][y - 1] = 1;
    r[y - 1][x - 1] = 1;
  }
  set<int> g;

  int people = 0;

  rep (k, 1 << N) {
    g.clear();
    int n = k;
    x = 0;
    bool flag = true;
    while (n > 0 && flag) {
      if (n & 1) {
        FORIT (itr, g.begin(), g.end()) {
          if (r[x][*itr] == 0) {
            flag = false;
            break;
          }
        }
        if (flag) g.insert(x);
      }
      x++;
      n >>= 1;
    }
    if (flag) people = max(people, (int) g.size());
  }

  cout << people << endl;
}


/**
abc002 D
実行時間制限: 2 sec / メモリ制限: 64 MB

問題文
神からの財産と、母音を取り戻した高橋くんは、AtCoder国の腐敗した政治を正すため、国会議員となろうと決めました。
もともと人心掌握術とスピーチに定評があった高橋くんは、何の苦労をすることもなく当選しました。
しかし、議員になってからが本番です。国を正すためには、首相に任命される必要があります。

AtCoder国には高橋くんを除いて
N
 人の国会議員と、
M
 個の人間関係
(
x
,

y
)
 が存在します。
人間関係
(
x
,

y
)
 とは、議員
x
 と議員
y
 が知り合いであることを意味します。
高橋くんは
N
 人の議員から何人かを選んで派閥を作ろうと企んでいます。
派閥に含まれるすべての議員は互いに知り合いでなければなりません。
高橋くんが作成することができる最大の派閥に属する議員数を求めるプログラムを書いてください。
入力
入力は以下の形式で標準入力から与えられる。
N

M

x
1

y
1

x
2

y
2

:
x
M

y
M

1
 行目には、高橋くん以外の国会議員の数
N

(
1
≦
N
≦
12
)
 と、人間関係の数
M

(
0
≦
M
≦
N
(
N
−
1
)
/
2
)
 が半角空白区切りで与えられる。
2
 行目から
M
+
1
 行目までの
M
 行で、人間関係が与えられる。
各議員は
1
 から
N
 までの整数で番号がつけられている。
2
 行目を基準とした第
i

(
1
≦
i
≦
M
)
 行において、議員
x
i
 と議員
y
i
 は知り合いであることを意味する。
x
i
 と
y
i
 はともに整数で、
1
≦
x
i
<
y
i
≦
N
 を満たす。
i
≠
j
 のとき、
(
x
i
,

y
i
)
≠
(
x
j
,

y
j
)
 であることが保証されている。
出力
高橋くんが作成することができる最大の派閥に属する議員数を
1
 行で出力してください。
また、出力の末尾には改行を入れること。
*/
