#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  long long a, t;
  vector<long long> v(N);
  long long sum = 0;
  int count = 0;

  // a0 a1 ... an: sa
  //b0 b1 ... bn: sb    の和を比較するとき: sa < sbを比較する代わりに
  //b0 - a0, b1 - a1, ... bn - an なる cnの和 sc < 0 和を取ることが必要.
  //sa - (b0 - 2* a0), sa - (b1 - 2* a1), ... sa - (bn - 2* an)なる dn < 0 和を取る必要がない.
  //が考えられる.

  for (int i = 0; i < N; i++) {
    cin >> a >> t;

    v[i] = 2*a + t;
    sum += a;
  }

  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  for (auto i = 0; i < N; i++) {
    if (sum < 0) break;

    sum -= v[i];
    count++;
  }

  cout << count << endl;
}

/**
以下のコードはダメだった.
multimapが大きい入力に対して意図した動作になっていないかも.
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  long long a, t;
  multimap<long long, long long, greater<long long>> m;
  long long v = 0;
  int count = 0;

  for (int i = 0; i < N; i++) {
    cin >> a >> t;

    m.insert(make_pair(a + t, a));
    v += a;
  }

  t = 0;

  for (auto e : m) {
    if (v < t) break;

    t += e.first;
    v -= e.second;
    count++;
  }

  cout << count << endl;
}
*/

/**
問題文
AtCoder 市で市長選挙が行われます。候補者は青木氏と高橋氏です。
市には
N
 個の町があり、
i
 番目の町には青木派の有権者が
A
i
 人、高橋派の有権者が
B
i
 人います。他に有権者はいません。
高橋氏は、それぞれの町で演説を行うことができます。
高橋氏がある町で演説を行った場合、その町の高橋派も青木派も全員高橋氏に投票します。
一方、高橋氏がある町で演説を行わなかった場合、その町の青木派は全員青木氏に投票し、高橋派は投票に行きません。
高橋氏が青木氏より多く票を獲得するためには、最小でいくつの町で演説をする必要があるでしょうか？

制約
入力は全て整数
1
≤
N
≤
2
×
10
5
1
≤
A
i
,
B
i
≤
10
9
入力
入力は以下の形式で標準入力から与えられる。

N

A
1

B
1

⋮

A
N

B
N

出力
答えを出力せよ。
*/
