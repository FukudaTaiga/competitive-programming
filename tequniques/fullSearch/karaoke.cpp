#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<long long>> v(N, vector<long long>(M));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> v[i][j];
    }
  }

  //tuple<int, int, long long> mtp(-1, -1, 0LL);
  long long m;
  long long sum = 0LL;

  for (int t1 = 0; t1 < M; t1++) {
    for (int t2 = t1 + 1; t2 < M; t2++) {
      for (int i = 0; i < N; i++) sum += max(v[i][t1], v[i][t2]);
      m = max(m, sum);
      sum = 0LL;
    }
  }

  cout << m << endl;
}


/**
2019 pakenhai C-karaoke
問題文
1,2,...,Nと番号づけられているN人の生徒から成るグループが，「全国統一カラオケコンテスト」に出場することとなりました．

このコンテストで歌える曲は，曲
1
，曲
2
，...，曲
M
 の
M
 曲あります．また，番号
i
 の生徒が曲
j
 を歌うと，必ず
A
i
,
j
 点を取ります．

さて，コンテストのルールは，以下のようになります．

M
 曲の中から
2
 つの曲を選ぶ．（それぞれ
T
1
 と
T
2
 とする．）
それぞれの生徒が，曲
T
1
 と曲
T
2
 の両方を歌う．
各生徒の得点は，その生徒が歌った
2
 つの曲の点数のうち高い方となる．
グループの得点は，生徒
1
,
2
,
.
.
.
,
N
 の得点の合計となる．
そのとき，グループの得点として考えられる最大の値を求めてください．

制約
1
≤
N
≤
100
2
≤
M
≤
100
0
≤
A
i
,
j
≤
100

000

000
入力はすべて整数
部分点
この問題はいくつかの小課題に分けられ，その小課題のすべてのテストケースに正解した場合に「この小課題に正解した」とみなされます．
提出したソースコードの得点は，正解した小課題の点数の合計となります．

(10 点)
N
=
1
，
M
=
2
．
(25 点)
M
=
2
．
(35 点)
N
=
1
．
(30 点) 追加の制約はない．
入力
入力は以下の形式で標準入力から与えられます．

N

M

A1,1 A1,2 A1,3 ... A1,M

A2,1 A2,2 A2,3 ... A2,M

A3,1 A3,2 A3,3 ... A3,M
:
AN,1 AN,2 AN,3 ... AN,M

出力
グループの得点として考えられる最大の値を，整数で出力してください．
*/