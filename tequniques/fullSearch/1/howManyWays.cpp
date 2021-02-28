#include <bits/stdc++.h>
#include <fstream>
using namespace std;

bool search(int n, int x) {
  if (n != 0 && x != 0) {
    int cnt = 0;

    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < n + 1; j++) {
        int k = x - i - j;
        if (0 < k && k < n && j < i && k < j) {
          cnt++;
        }
      }
    }

    cout << cnt << endl;
    return 1;
  }
  else return 0;
}

int main() {
  int n, x;
  char name[16] = "input.txt";
  bool b = true;
  ifstream fin;
  ofstream fout;

  fin.open(name);

  if (fin.fail()) cout << "input file doesnt exists" << endl;

  while (b) {
    fin >> n >> x;
    b = search(n, x);
  }
}

/**
ITP_7_B
時間制限 : 1 sec, メモリ制限 : 131072 KB
組み合わせの数

1 から n までの数の中から、重複無しで３つの数を選びそれらの合計が x となる組み合わせの数を求めるプログラムを作成して下さい。

例えば、1 から 5 までの数から３つを選んでそれらの合計が 9 となる組み合わせは、

1 + 3 + 5 = 9
2 + 3 + 4 = 9
の２通りがあります。

Input
複数のデータセットが入力として与えられます。各データセットでは、空白で区切られた n、x が 1 行に与えられます。

n、x がともに 0 のとき入力の終わりとします。

Constraints
3 ≤ n ≤ 100
0 ≤ x ≤ 300
Output
各データセットについて、組み合わせの数を１行に出力して下さい。

Sample Input
5 9
0 0
Sample Output
2
*/
