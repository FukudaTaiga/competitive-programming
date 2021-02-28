#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, T;
  int a, b;
  int temp, curr;

  cin >> N >> M >> T;
  curr = N;

  cin >> a >> b;

  //0~A1
  curr -= a;
  if (curr <= 0) {
    cout << "No" << endl;
    return 0;
  }

  if (curr < N) curr = min(curr + (b - a), N);

  temp = b;

  for (int i = 1; i < M; i++) {
    cin >> a >> b;

    curr -= a - temp;
    if (curr < 0) {
    cout << "No" << endl;
    return 0;
    }

    if (curr < N) curr = min(curr + b - a, N);

    temp = b;
  }

  curr -= T - temp;

  if (curr <= 0) {
    cout << "No" << endl;
    return 0;
  }
  else {
    cout << "Yes" << endl;
    return 0;
  }
}

/**
問題文
高橋君のスマートフォンのバッテリー容量は
N
 [mAh] であり、時刻
0.5
,
1.5
,
2.5
,
…
 に、つまり時刻
n
+
0.5
(
n
 は整数
)
 を迎える度にバッテリー残量が
1
 [mAh] ずつ減少します。
高橋君はスマートフォンを満充電した状態で時刻
0
 に外出し、途中で
M
 回カフェを訪れ、時刻
T
 に帰宅します。
i
 回目に訪れるカフェには時刻
A
i
 から時刻
B
i
 まで滞在します。カフェに滞在している間はスマートフォンを充電するため、バッテリー残量は減少せず、代わりに時刻
n
+
0.5
(
n
 は整数
)
 を迎える度に
1
 [mAh] ずつ増加します。ただし既にバッテリー残量がバッテリー容量と等しい場合、バッテリー残量は増えも減りもしません。
高橋君が途中でスマートフォンのバッテリー残量が
0
 になることなく帰宅することができるかを判定してください。

制約
1
≤
N
≤
10
9
1
≤
M
≤
1000
1
≤
T
≤
10
9
0
<
A
1
<
B
1
<
A
2
<
B
2
<
A
3
<
B
3
<
⋯
<
A
M
<
B
M
<
T
入力は全て整数
入力
入力は以下の形式で標準入力から与えられる。

N

M

T

A
1

B
1

A
2

B
2

A
3

B
3

⋮

A
M

B
M

出力
高橋君が途中でスマートフォンのバッテリー残量が
0
 になることなく帰宅することができるなら Yes を、できないなら No を出力せよ。
*/
