#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  string str;
  map<string, bool> m;

  for (int i = 0; i < N; i++) {
    cin >> str;

    if (str.at(0) == '!') {
      str = str.substr(1);

      auto itr = m.find(str);

      if (itr != m.end()) {
        if (itr->second == true) {
          cout << str << endl;
          return 0;
        }
      }
      else {
        m[str] = false;
      }
    }
    else {
      auto itr = m.find(str);

      if (itr != m.end()) {
        if (itr->second == false) {
          cout << str << endl;
          return 0;
        }
      }
      else {
        m[str] = true;
      }
    }
  }

  cout << "satisfiable" << endl;
}

/**
問題文
N
 個の文字列
S
1
,
S
2
,
…
,
S
N
 が与えられます。 各文字列は、英小文字からなる空でない文字列の先頭に ! を
0
 文字か
1
 文字付加したものです。
文字列
T
 は、
T
 の先頭に ! を
0
 文字付加しても
1
 文字付加しても
S
1
,
S
2
,
…
,
S
N
 のいずれかに一致するとき、不満な文字列であるといいます。
不満な文字列があるかどうか判定し、あれば
1
 つ示してください。

制約
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
|
S
i
|
≤
10
S
i
 は英小文字からなる空でない文字列の先頭に ! を
0
 文字か
1
 文字付加したものである。
入力
入力は以下の形式で標準入力から与えられる。

N

S
1

⋮

S
N

出力
不満な文字列が存在する場合、不満な文字列を
1
 つ出力せよ。
不満な文字列が存在しない場合、satisfiable と出力せよ。

例
入力
6
a
!a
b
!c
d
!d
出力
a
*/
