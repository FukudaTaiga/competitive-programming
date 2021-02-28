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
  string str;
  cin >> str;

  if (str[0] == str[1] && str[1] == str[2]) cout << "Won" << endl;
  else cout << "Lost" << endl;
}

/**

AtCoder Beginner Contest 189
コンテスト時間: 2021-01-23(土) 21:00 ~ 2021-01-23(土) 22:40 (100分)AtCoderホームへ戻る
A - Slot  /
実行時間制限: 2 sec / メモリ制限: 1024 MB

配点 :
100
 点

問題文
あなたはスロットマシーンで遊んでいます。

スロットを回した結果は
3
 文字の英大文字
C
1
,
C
2
,
C
3
 で表され、これらが全て同じ文字であるとき当たりです。

当たりかどうか判定してください。

制約
C
i
 は英大文字
入力
入力は以下の形式で標準入力から与えられる。

C
1
C
2
C
3

出力
当たりなら Won を、当たりでないなら Lost を出力せよ。

入力例 1
Copy
SSS
出力例 1
Copy
Won
全て同じ文字なので当たりです。

入力例 2
Copy
WVW
出力例 2
Copy
Lost
当たりではありません。

*/
