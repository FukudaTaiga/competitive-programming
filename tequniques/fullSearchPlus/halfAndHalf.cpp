#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  int X, Y;
  cin >> A >> B >> C >> X >> Y;

  int minimum = INT_MAX;

  for (int k = 0; k < max(X, Y) + 1; k++) {
    int i = max(0, X - k);
    int j = max(0, Y - k);
    minimum = min(minimum, A * i + B * j + C * 2 * k);
  }

  cout << minimum << endl;
}


/**
これだとTLE
#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  int X, Y;
  cin >> A >> B >> C >> X >> Y;

  int minimum = INT_MAX;

  for (int i = 0; i < X + 1; i++) {
    for (int j = 0; j < Y + 1; j++) {
      minimum = min(minimum, A * i + B * j + C * 2 * max(X - i, Y - j));
    }
  }

  cout << minimum << endl;
}
*/

/**
実行時間制限: 2 sec / メモリ制限: 256 MB

配点 :
300
 点

問題文
ファーストフードチェーン「ピザアット」のメニューは「A ピザ」「B ピザ」「AB ピザ」の
3
 種類です。A ピザと B ピザは全く異なるピザで、これらをそれぞれ半分に切って組み合わせたものが AB ピザです。A ピザ、B ピザ、AB ピザ
1
 枚あたりの値段はそれぞれ
A
 円、
B
 円、
C
 円です。

中橋くんは、今夜のパーティーのために A ピザ
X
 枚と B ピザ
Y
 枚を用意する必要があります。これらのピザを入手する方法は、
A
 ピザや
B
 ピザを直接買うか、AB ピザ
2
 枚を買って A ピザ
1
 枚と B ピザ
1
 枚に組み替える以外にはありません。このためには最小で何円が必要でしょうか？なお、ピザの組み替えにより、必要な量を超えたピザが発生しても構いません。

制約
1
≤
A
,
B
,
C
≤
5000
1
≤
X
,
Y
≤
10
5
入力中のすべての値は整数である。
入力
入力は以下の形式で標準入力から与えられる。

A

B

C

X

Y

出力
X
 枚の A ピザと
Y
 枚の B ピザを用意するために必要な最小の金額を出力せよ。
*/
