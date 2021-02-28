#include <bits/stdc++.h>
using namespace std;

int maxv(vector<vector<int>> a, int h, int w) {
  int ma = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a.at(i).at(j) > ma) ma = a.at(i).at(j);
    }
  }

  return ma;
}

int minv(vector<vector<int>> a, int h, int w) {
  int mi = maxv(a, h, w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a.at(i).at(j) < mi) mi = a.at(i).at(j);
    }
  }

  return mi;
}

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a.at(i).at(j);
    }
  }

  int m = minv(a, h, w);

  int count = 0;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      count += a.at(i).at(j) - m;
    }
  }

  cout << count;
}

/**
問題文
縦 Hマス、横 Wマスのマス目があります。上から
i行目、左から j列目のマスには、ブロックが
A_i,j個あります。

どのマスにも同じ個数のブロックがある状態にするには、
最小で何個のブロックを取り除けばよいでしょうか？

制約
1≤H,W≤100
0≤ A_i,j ≤ 100

入力

入力は以下の形式で標準入力から与えられる。
H W
A_1,1 A_1,2 ... A_1,W
A_H,1 A_H,2 ... A_H,W

出力
取り除くブロックの個数の最小値を出力せよ。
*/
