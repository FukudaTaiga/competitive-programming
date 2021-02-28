#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;

  cin >> N >> S;

  int k = 0, cnt = 0;
  string str;

  for (int i = 0; i < 1000; i++) {
    str = to_string(i);
    if (0 <= i && i < 10) str = "00" + str;
    else if (10 <= i && i < 100) str = "0" + str;

  	for (int j = 0; j < N && k < 3; j++) {
      if (str[k] == S[j]) k++;
    }
    if (k == 3) cnt++;
    k = 0;
  }

  cout << cnt << endl;
}


/**
純粋な全探索だと時間が足りない. 以下のコードは×.
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;

  cin >> N >> S;

  int i = 0;
  set<string> s;
  string str = "";

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        str += S[i];
        str += S[j];
        str += S[k];
        s.insert(str);
        str = "";
      }
    }
  }

  cout << s.size() << endl;
}
*/

/**
実行時間制限: 2 sec / メモリ制限: 1024 MB

配点:
400
 点

問題文
AtCoder 社は、オフィスの入り口に
3
 桁の暗証番号を設定することにしました。

AtCoder 社には
N
 桁のラッキーナンバー
S
 があります。社長の高橋君は、
S
 から
N
−
3
 桁を消して残りの
3
 桁を左から読んだものを暗証番号として設定することにしました。

このとき、設定されうる暗証番号は何種類あるでしょうか？

ただし、ラッキーナンバーや暗証番号はいずれも
0
 から始まっても良いものとします。

制約
4
≤
N
≤
30000
S
 は半角数字からなる長さ
N
 の文字列
入力
入力は以下の形式で標準入力から与えられます。

N

S

出力
設定されうる暗証番号の種類数を出力してください。


*/
