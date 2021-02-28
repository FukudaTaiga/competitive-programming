#include <bits/stdc++.h>
using namespace std;

int main() {
  //swap. 特にincludeは必要ない.
  int N;

  cout << "type array size N" << endl;
  cin >> N;

  //bubble sort
  vector<int> v(N);
  cout << "type " << N << " elements" << endl;
  for (auto i = 0; i < N; i++) {
    cout << i + 1 << "th element" << endl;
    cin >> v[i];
  }

  cout << "bubble sort" << endl;

  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j < N - i; j++) {
      if (v[j + 1] < v[j]) swap(v[j], v[j + 1]); //swap(a, b): a, bの入れ替え
    }
  }

  cout << "vector v: ";
  for (auto e : v) {
    cout << e << " ";
  }
  cout << endl;
}
