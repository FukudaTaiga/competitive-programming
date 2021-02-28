#include <bits/stdc++.h> //プリコンパイル済のライブラリを使用できるようにする宣言
using namespace std; //

//c++が読み込まれるとmainの{から}までが実行される
int main() {
  vector<int> v;
  vector<long long> u;
  vector<vector<int>> w;
  vector<vector<long long>> x;

  printf("vi-max: %.10e\n", (double) v.max_size());
  printf("vl-max: %.10e\n", (double) u.max_size());
  printf("vvi-max: %.10e\n", (double) w.max_size());
  printf("vvl-max: %.10e\n", (double) x.max_size());
}
