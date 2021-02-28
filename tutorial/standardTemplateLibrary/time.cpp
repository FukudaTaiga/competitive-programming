#include <bits/stdc++.h>
using namespace std;

int main() {
  //clock()で実行時間計測. <ctime>
  //CLOCKS_PER_SEC:  ?clock/1secが分かる.
  //clock() / CLOCKS_PER_SECで実行時間が得られる.
  //最適化問題等でぎりぎりまで計算したいとき等純粋に実行時間を知る以外にも使い道がある.

  int N;
  vector<int> v(0);

  cin >> N;

  int start = clock(); //std::chrono::system_clock::now()
  for (int i = 0; i < N; i++) {
    v.push_back(1);
  }
  int end = clock();

  cout << "execution time: " << (double) (end - start) / CLOCKS_PER_SEC << endl;
}
