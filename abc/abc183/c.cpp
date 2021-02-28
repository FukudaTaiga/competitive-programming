#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<vector<long long>> t(N, vector<long long>(N, 0));
  vector<int> b(N - 1);
  long long total = 0;
  long count = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> t[i][j];
    }
  }

  for (int i = 0; i < N - 1; i++) {
    b[i] = i + 1;
  }


  do {
    total += t[0][b[0]];
    for (int i = 0; i < N - 2; i++) {
      //cout << b[i] << " ";
      total += t[b[i]][b[i + 1]];
    }
    //cout << b[N-2] << endl;

    total += t[b[N-2]][0];

    if (total == K) count++;

    //cout << "total: " << total << endl;

    total = 0;
  } while (next_permutation(b.begin(), b.end()));

  cout << count << endl;
}
