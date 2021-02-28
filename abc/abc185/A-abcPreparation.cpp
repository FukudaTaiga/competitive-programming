#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  cout << min(min(min(a, b), c), d) << endl;
}

/**
問題文
高橋君は、プログラミングコンテストを何回か開くことにしました。
コンテストを
1
 回開くには、
100
 点問題、
200
 点問題、
300
 点問題、
400
 点問題が
1
 問ずつ必要です。
100
,
200
,
300
,
400
 点問題の案がそれぞれ
A
1
,
A
2
,
A
3
,
A
4
 個あるとき、コンテストを最大で何回開けるでしょうか？
なお、同じ問題案は
1
 度しか使えません。

制約
1
≤
A
i
≤
100

(
1
≤
i
≤
4
)
入力は全て整数
入力
入力は以下の形式で標準入力から与えられる。

A
1
A
2
A
3
A
4

出力
コンテストを開催可能な最大回数を表す整数を出力せよ。


*/
