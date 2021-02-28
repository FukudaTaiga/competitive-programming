#include <bits/stdc++.h>
using namespace std;

int main() {
  //<numeric> に定義されている関数も参照すると良い. 
  int a[8] = {8, 3, 7, 1, 4, 6, 2, 5};
  vector<int> b = {8, 3, 7, 1, 4, 6, 2, 5};
  cout << "original: ";
  for (int i = 0; i < 8; i++) cout << a[i] << " ";
  cout << endl;

  cout << "reverse" << endl;
  //O(N) <algorism>
  //reverse(itr1, itr2): itr1からitr2-1までreverse

  reverse(a + 2, a + 7); //2~6がreverse
  cout << "a: ";
  for (int i = 0; i < 8; i++) cout << a[i] << " ";
  cout << endl;

  reverse(b.begin() + 2, b.begin() + 7); //2~6がreverse
  cout << "b: ";
  for (auto i : b) cout << i << " ";
  cout << endl;

  cout << "sort" << endl;
  //O(NlogN) <algorism>
  //sort(itr1, itr2, {compare: defaultで<, つまり昇順}): itr1からitr2-1までsort
  //greater<int>(): <functional>

  sort(a + 1, a + 5, greater<int>()); //1~4だけソートされる
  cout << "a: ";
  for (int i = 0; i < 8; i++) cout << a[i] << " ";
  cout << endl;

  sort(b.begin(), b.end()); //最初から最後まで
  cout << "b: ";
  for (auto i : b) cout << i << " ";
  cout << endl;
  //{1, 2, 3, 4, 5, 6, 7, 8}

  cout << "lower_bound 5, b" << endl;
  //sort済み配列に対して二分探索. O(logN) <algorism>
  //lower_bound(itr1, itr2, x): itr1からitr2-1までの中で始めてx <= *itr となるitrator返す
  //iteratorが返されることに注意.
  //lower_bound(a+l, a+r, x) - a: a[]のindex返される.

  auto itr = lower_bound(b.begin(), b.end(), 5);
  cout << distance(b.begin(), itr) << endl;

  cout << "count" << endl;
  //count O(N) <algorism>
  //count(itr1, itr2, x): itr1からitr2の直前までのxの個数を数える.
  cout << count(b.begin(), b.end(), 5) << endl; //1
  cout << count(b.begin(), b.end(), 100) << endl; //0

  cout << "find 5 in b" << endl;
  //find O(N) <algorism>
  //find(itr1, itr2, x): itr1からitr2-1でxを検索し, 存在するならxのitr, ないならend()
  auto it = find(b.begin(), b.end(), 2);
  if (it != b.end()) cout << distance(b.begin(), it) << endl;

  cout << "next_permutation" << endl;
  //next_permutation: 辞書式で次の順列. boolを返す. 次があるならtrue.
  //O(N)かかる可能性がある. whileだとN!回くらい回るから大変...
  vector<int> v = {1, 2, 3};
  int count = 0;
  do {
    cout << "v" << count << ": ";
    for (int i = 0; i < 3; i++) cout << v[i] << " ";
    cout << endl;
    count++;
  } while (next_permutation(v.begin(), v.end()));
}
