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

//with map
//output start / finish
int rec(map<int, set<int>> mp, int n, vector<bool> &b, int t, int id) {
  auto itr = next(mp.begin(), id);
  auto key = itr->first;
  auto value = itr->second;
  int m = t;
  b[key - 1] = true;
  for (auto e : value) {
    if (!b[e - 1]) m = rec(mp, n, b, m + 1, e - 1);
  }
  cout << key << " " << t << " " << m + 1 << endl;
  return m + 1;
}

void dfs(map<int, set<int>> mp, int n) {
  vector<bool> b(n, false);
  auto fst = mp.begin()->first;
  rec(mp, n, b, 1, 0);
}

//with vector
void dfs(vvi v, int n) {
  //time to begin searching
  vi d(n, -1);
  //time to finish searching the vertex
  vi f(n, -1);
  stack<int> stk;
  stk.push(1);
  int temp;
  //time
  int t = 1;

  while (!stk.empty()) {
    //未探索のvertexがあるか
    bool b = false;
    temp = stk.top();

    if (d[temp- 1] == -1) d[temp - 1] = t;

    for (auto e : v[temp - 1]) if (d[e - 1] == -1) {
      stk.push(e);
      b = true;
      break;
    }
    t++;
    if (!b) {
      f[temp - 1] = t;
      stk.pop();
    }
  }

  rep (i, n) cout << i + 1 << " " << d[i] << " " << f[i] << endl;
}

int main() {
  ifstream fin;
  //ofstream fout;
  string name = "input.txt";
  fin.open(name);

  if (fin.fail()) cout << "file isnt found" << endl;
  else {
    int n, k;
    fin >> n;
    vvi v(n, vi(0));
    map<int, set<int>> mp;

    rep (i, n) {
      int u;
      fin >> u;
      fin >> k;
      int d;
      set<int> s;
      rep (j, k) {
        fin >> d;
        v[i].push_back(d);
        s.insert(d);
      }
      mp.insert(make_pair(u, s));
    }

    dfs(v, n);
    cout << endl;
    dfs(mp, n);
  }
}


/**
Depth First Search
時間制限 : 1 sec, メモリ制限 : 131072 KB
English / Japanese
深さ優先探索
深さ優先探索（Depth First Search: DFS）は、可能な限り隣接する頂点を訪問する、という戦略に基づくグラフの探索アルゴリズムです。未探索の接続辺が残されている頂点の中で最後に発見した頂点 v の接続辺を再帰的に探索します。v の辺をすべて探索し終えると、v を発見したときに通ってきた辺を後戻りして探索を続行します。

探索は元の始点から到達可能なすべての頂点を発見するまで続き、未発見の頂点が残っていれば、その中の番号が一番小さい１つを新たな始点として探索を続けます。

深さ優先探索では、各頂点に以下のタイムスタンプを押します：

タイムスタンプ d[v]: v を最初に発見した発見時刻を記録します。
タイムスタンプ f[v]: v の隣接リストを調べ終えた完了時刻を記録します。
以下の仕様に基づき、与えられた有向グラフ G=(V,E) に対する深さ優先探索の動作を示すプログラムを作成してください：

G は隣接リスト表現の形式で与えられます。各頂点には 1 から n までの番号がふられています。
各隣接リストの頂点は番号が小さい順に並べられています。
プログラムは各頂点の発見時刻と完了時刻を報告します。
深さ優先探索の過程において、訪問する頂点の候補が複数ある場合は頂点番号が小さいものから選択します。
最初に訪問する頂点の開始時刻を 1 とします。
入力
最初の行に G の頂点数 n が与えられます。続く n 行で各頂点 u の隣接リストが以下の形式で与えられます：

u k v1 v2 ... vk

u は頂点の番号、k は u の出次数、v1v2...vk 　は u に隣接する頂点の番号を示します。

出力
各頂点について id、 d、 fを空白区切りで１行に出力してください。id は頂点の番号、d はその頂点の発見時刻、f はその頂点の完了時刻です。頂点の番号順で出力してください。

制約
1≤n≤100
入力例 1
4
1 1 2
2 1 4
3 0
4 1 3
出力例 1
1 1 8
2 2 7
3 4 5
4 3 6

入力例 2
6
1 2 2 3
2 2 3 4
3 1 5
4 1 6
5 1 6
6 0
出力例 2
1 1 12
2 2 11
3 3 8
4 9 10
5 4 7
6 5 6

入力例2に対応するグラフ(発見時刻/終了時刻)


Depth First Search
Depth-first search (DFS) follows the strategy to search ”deeper” in the graph whenever possible. In DFS, edges are recursively explored out of the most recently discovered vertex v that still has unexplored edges leaving it. When all of v's edges have been explored, the search ”backtracks” to explore edges leaving the vertex from which v was discovered.

This process continues until all the vertices that are reachable from the original source vertex have been discovered. If any undiscovered vertices remain, then one of them is selected as a new source and the search is repeated from that source.

DFS timestamps each vertex as follows:

d[v] records when v is first discovered.
f[v] records when the search finishes examining v’s adjacency list.
Write a program which reads a directed graph G=(V,E) and demonstrates DFS on the graph based on the following rules:

G is given in an adjacency-list. Vertices are identified by IDs 1,2,...n respectively.
IDs in the adjacency list are arranged in ascending order.
The program should report the discover time and the finish time for each vertex.
When there are several candidates to visit during DFS, the algorithm should select the vertex with the smallest ID.
The timestamp starts with 1.
Input
In the first line, an integer n denoting the number of vertices of G is given. In the next n lines, adjacency lists of u are given in the following format:

u k v1 v2 ... vk

u is ID of the vertex and k denotes its degree. vi are IDs of vertices adjacent to u.

Output
For each vertex, print id, d and f separated by a space character in a line. id is ID of the vertex, d and f is the discover time and the finish time respectively. Print in order of vertex IDs.

Constraints
1≤n≤100
Sample Input 1
4
1 1 2
2 1 4
3 0
4 1 3
Sample Output 1
1 1 8
2 2 7
3 4 5
4 3 6
Sample Input 2
6
1 2 2 3
2 2 3 4
3 1 5
4 1 6
5 1 6
6 0
Sample Output 2
1 1 12
2 2 11
3 3 8
4 9 10
5 4 7
6 5 6

This is example for Sample Input 2 (discover/finish)

Reference
Introduction to Algorithms, Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein. The MIT Press.
*/
