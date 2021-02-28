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

void coutv(vvi v, int n) {
  rep (i, n) {
    rep (j, n) {
      if (v[i][j] == 0) cout << "- ";
      else cout << "Q ";
    }
    cout << endl;
  }
}

void coutv(vvi v, int n, int x, int y) {
  rep (i, n) {
    rep (j, n) {
      if (i == x && j == y) cout << "x ";
      else if (v[i][j] == 0) cout << "- ";
      else cout << "Q ";
    }
    cout << endl;
  }
}

void coutv(vi u, int n) {
  rep (i, n * n) {
    if (i != 0 && i % n == 0) cout << endl;

    if (u[i] == 0) cout << "- ";
    else cout << "Q ";
  }
  cout << endl;
}

bool check(int x, int y, vvi v, int n) {
  //horizontal
  rep (j, n) if (v[x][j] != 0 && j != y) return false;

  //vertical
  rep (i, n) if (v[i][y] != 0 && i != x) return false;

  //right below diagonal
  FOR (i, 1, n) {
    if (y + i >= n || x + i >= n) break;
    else {
      if (v[x + i][y + i] != 0) return false;
    }
  }

  //left below diagonal
  FOR (i, 1, n) {
    if (y - i <= -1 || x + i >= n) break;
    else {
      if (v[x + i][y - i] != 0) return false;
    }
  }

  //right above diagonal
  FOR (i, 1, n) {
    if (y + i >= n || x - i <= -1) break;
    else {
      if (v[x - i][y + i] != 0) return false;
    }
  }

  //left above diagonal
  FOR (i, 1, n) {
    if (y - i <= -1 || x - i <= -1) break;
    else {
      if (v[x - i][y - i] != 0) return false;
    }
  }

  return true;
}

bool check(int x, int y, vi v, int n) {
  //horizontal
  rep (j, n) if (v[n * x + j] != 0) return false;

  //vertical
  rep (i, n) if (v[n * i + y] != 0) return false;

  //right below diagonal
  rep (i, n) {
    if (y + i >= n || x + i >= n) break;
    else {
      if (v[n * (x + i) + y + i] != 0) return false;
    }
  }

  //left below diagonal
  rep (i, n) {
    if (y - i <= -1 || x + i >= n) break;
    else {
      if (v[n * (x + i) + y - i] != 0) return false;
    }
  }

  //right above diagonal
  rep (i, n) {
    if (y + i >= n || x - i <= -1) break;
    else {
      if (v[n * (x - i) + y + i] != 0) return false;
    }
  }

  //left above diagonal
  rep (i, n) {
    if (y - i <= -1 || x - i <= -1) break;
    else {
      if (v[n * (x - i) + y - i] != 0) return false;
    }
  }

  return true;
}

//get queen in row x. return column y.
int getloc(int x, vvi v, int n) {
  int y = -1;

  rep (j, n) {
    if (v[x][j] == 1 || v[x][j] == 2) {
      y = j;
      break;
    }
  }

  return y;
}

//v: board, m: queen already set, n: num of queen to set
//0: unset, 1: set, 2: already set
//backtrack
pair<vvi, bool> setQwithBackTrack(vvi v, int k, int n) {
  int i = 0, j = 0;

  while (k < n && -1 < i) {
    int c = getloc(i, v, n);
    //coutv(v, n, i, j);
    //cout << k << endl;



    if (c != -1) {
      i++;
      j = 0;
    }
    else {
      if (n <= j) {
        while (-1 < i) {
          i--;
          j = getloc(i, v, n);
          if (v[i][j] == 1) {
            v[i][j] = 0;
            j++;
            k--;
            break;
          }
        }
      }
      else {
        if (check(i, j, v, n)) {
          v[i][j] = 1;
          i++;
          j = 0;
          k++;
        }
        else {
          v[i][j] = 0;
          j++;
        }
      }
    }
  }

  return make_pair(v, k == n);
}

void cpv(vi s, vi t, int n) {
  int j = 0;

  rep (i, n * n) {
    if (t[i] == 0) {
      t[i] = s[j];
      j++;
    }
  }
}

pair<vi, bool> setQ(vi u, int k, int n) {
  bool b = false;
  vi z(n * n - k);
  vi w;

  rep (i, n - k) z[i] = k + i + 1;

  bool flag;

  do {
    w = u;
    //見つかったことを表す.
    flag = true;
    cpv(z, w, n);
    rep (i, n * n) if (w[i] != 0) {
      if (!check(i / n, i % n, w, n)) {
        flag = false;
        break;
      }
    }
    if (flag) break;
  } while (!flag && next_permutation(z.begin(), z.end()));

  return make_pair(w, flag);
}

int main() {
  ifstream fin;
  //ofstream fout;
  string name = "input.txt";
  int n = 8;
  cout << "type board size with edge" << endl;
  cin >> n;
  int k;
  vvi v(n, vi(n));
  vi u(n * n);

  fin.open(name);
  if (fin.fail()) cout << "fail isnt found" << endl;
  else {
    bool b = true;
    fin >> k;
    rep (i, k) {
      int r, c;
      fin >> r >> c;
      if (check(r, c, v, n)) {
        v[r][c] = 2;
        u[n * r + c] = i + 1;
      }
      else b = false;
    }

    pair<vi, bool> ans1;
    pair<vvi, bool> ans2;
    /**
    if (b) ans1 = setQ(u, k, n);
    else ans1 = make_pair(u, false);
    */

    if (b) ans2 = setQwithBackTrack(v, k, n);
    else ans2 = make_pair(v, false);

    if (ans2.second) {
      cout << "solution is " << endl;
      coutv(ans2.first, n);
    }
    else cout << "theres no solution" << endl;
  }
}

/**
8 Queens Problem
時間制限 : 1 sec, メモリ制限 : 131072 KB
English / Japanese
8クイーン問題
8 クイーン問題とは、8×8 のマスから成るチェス盤に、どのクイーンも他のクイーンを襲撃できないように、8 つのクイーンを配置する問題です。チェスでは、クイーンは次のように８方向のマスにいるコマを襲撃することができます。



すでにクイーンが配置されている k 個のマスが指定されるので、それらを合わせて８つのクイーンを配置したチェス盤を出力するプログラムを作成してください。

入力
１行目に整数 k が与えられます。続く k 行にクイーンが配置されているマスが２つの整数 r, c で与えられます。r, c はそれぞれ０から始まるチェス盤の行と列の番号を表します。

出力
出力は 8×8 のチェス盤を表す文字列で、クイーンが配置されたマスを 'Q'、配置されていないマスを '.' で表します。

制約
入力に対する解はただ１つ存在する。
入力例 1
2
2 2
5 3
出力例 1
......Q.
Q.......
..Q.....
.......Q
.....Q..
...Q....
.Q......
....Q...
*/
