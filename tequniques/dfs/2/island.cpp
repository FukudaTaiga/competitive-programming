#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define FOR(i, s, n) for (int i = (s); i < (int) (n); i++)
#define FORLL(i, s, n) for (ll i = (s); i < (ll) (n); i++)
#define FORIT(itr, s, e) for (auto itr = (s); itr != (e); ++itr)
#define rep(i, n) FOR(i, 0, n)
#define _GLIBCXX_DEBUG

void coutp(pi p) {
  cout << p.first << " " << p.second << endl;
}

void couts(stack<pi> s) {
  while (!s.empty()) {
    coutp(s.top());
    s.pop();
  }
  cout << endl;
}

//check
//xxx
//xox
//xxx
pi check(int i, int j, vi seen, vi v, int w, int h) {
  //above
  if (0 < i) {
    if (v[w * (i - 1) + j] == 1 && seen[w * (i - 1) + j] != 1) return make_pair(i - 1, j);
  }
  //below
  if (i < h - 1) {
    if (v[w * (i + 1) + j] == 1 && seen[w * (i + 1) + j] != 1) return make_pair(i + 1, j);
  }
  //right
  if (j < w - 1) {
    if (v[w * i + j + 1] == 1 && seen[w * i + j + 1] != 1) return make_pair(i, j + 1);
  }
  //left
  if (0 < j) {
    if (v[w * i + j - 1] == 1 && seen[w * i + j - 1] != 1) return make_pair(i, j - 1);
  }
  //above right
  if (0 < i && j < w - 1) {
    if (v[w * (i - 1) + j + 1] == 1 && seen[w * (i - 1) + j + 1] != 1) return make_pair(i - 1, j + 1);
  }
  //above left
  if (0 < i && 0 < j) {
    if (v[w * (i - 1) + j - 1] == 1 && seen[w * (i - 1) + j - 1] != 1) return make_pair(i - 1, j - 1);
  }
  //below right
  if (i < h - 1 && j < w - 1) {
    if (v[w * (i + 1) + j + 1] == 1 && seen[w * (i + 1) + j + 1] != 1) return make_pair(i + 1, j + 1);
  }
  //below
  if (i < h - 1 && 0 < j) {
    if (v[w * (i + 1) + j - 1] == 1 && seen[w * (i + 1) + j - 1] != 1) return make_pair(i + 1, j - 1);
  }

  return make_pair(-1, -1);
}

//connect
void connect(int idx, vi &seen, vi &v, int w, int h) {
  stack<pi> stk;
  stk.push(make_pair(idx / w, idx % w));
  int x, y;

  while (!stk.empty()) {
    tie(x, y) = stk.top();
    idx = w * x + y;
    seen[idx] = 1;
    tie(x, y) = check(x, y, seen, v, w, h);

    if (x < 0 && y < 0) {
      v[idx] = 0;
      stk.pop();
    }
    else stk.push(make_pair(x, y));
  }
}

//1: land, 0: sea
int dfs(vi v, int w, int h) {
  auto itr = find(v.begin(), v.end(), 1);
  int idx = distance(v.begin(), itr);
  vi seen(h * w);
  int cnt = 0;

  while (itr != v.end()) {
    connect(idx, seen, v, w, h);
    cnt++;
    itr = find(v.begin(), v.end(), 1);
    idx = distance(v.begin(), itr);
  }

  return cnt;
}

int main() {
  ifstream fin;
  ofstream fout;
  string name = "input.txt";

  fin.open(name);
  if (fin.fail()) cout << "file isnt found" << endl;
  else {
    int w, h;
    fin >> w >> h;
    vi v;

    while (w != 0 && h != 0) {
      v = vi(h * w);
      rep (i, h * w) fin >> v[i];
      /**
      rep (i, h * w) {
        if (i != 0 && i % w == 0) cout << endl;
        cout << v[i] << " ";
      }
      cout << endl;
      */
      cout << dfs(v, w, h) << endl;
      fin >> w >> h;
    }
  }
}


/**
How Many Islands?
時間制限 : 1 sec, メモリ制限 : 131072 KB
English / Japanese
Problem B: 島はいくつある？
この問題では，同じ大きさの正方形に区切られたメッシュ状の地図が与えられる． この地図は，ある海域を表しており，各正方形の領域が陸または海に対応する． 図B-1は地図の一例である．


図B-1：ある海域の地図
陸に対応する二つの正方形領域が，地図上で縦，横または斜め方向に隣接しているなら，一方から他方へ歩いて行くことができる． 陸に対応する二つの領域が同じ島に属するのは，一方から他方へ（一般には別の陸地を経由して）歩いて行ける時であり，またその時のみである． なお，この地図の海域は海で囲まれており，その外側へ歩いて出ることはできない．

与えられた地図を読み取り，この海域に島がいくつあるか数えるプログラムを作成して欲しい． たとえば，図B-1の地図には，全部で三つの島がある．

Input
入力はデータセットの列であり，各データセットは次のような形式で与えられる．

w h
c1,1 c1,2 ... c1,w
c2,1 c2,2 ... c2,w
...
ch,1 ch,2 ... ch,w
w と h は地図の幅と高さを表す50以下の正の整数であり，地図は w×h 個の同じ大きさの正方形から構成される． w と h の間は空白文字1個で区切られる．

ci, j は，0 または 1 であり，空白文字1個で区切られる． ci, j = 0 なら，地図上で左から i 番目，上か ら j 番目の正方形は海であり，ci, j = 1 なら陸である．

入力の終わりは，空白文字1個で区切られた2個のゼロのみからなる行で表される．

Output
各データセットに対し，島の個数を1行に出力せよ． それ以外の余計な文字を含んではいけない．

Sample Input
1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0
Output for the Sample Input
0
1
1
3
1
9
*/
