#include <bits/stdc++.h>
using namespace std;

//priority queue <queue>, <vector>, <functional>
int main() {
  //priority_queue<type, inner container(=vec), compare(=<)> ...; 宣言
  priority_queue<int, vector<int>, less<int>> gq; // < による比較小さい方が優先. 最小値が取り出される.
  priority_queue<int, vector<int>, greater<int>> lq; // > による比較大きいほうが優先. 最大値が取り出される.

  //push, pop, top: O(logN)
  cout << "push 1" << endl;
  gq.push(1);
  lq.push(1); //{1}
  cout << "push -1" << endl;
  gq.push(-1);
  lq.push(-1); //{1, -1}
  cout << "push 0" << endl;
  gq.push(0);
  lq.push(0); //{1, 0, -1}
  cout << "push 100" << endl;
  gq.push(100);
  lq.push(100); //{100, 1, 0, -1}
  cout << "push -100" << endl;
  gq.push(-100);
  lq.push(-100); //{100, 1, 0, -1, -100}

  cout << "gq size: " << gq.size() << endl;
  cout << "lq size: " << lq.size() << endl;

  cout << "pop" << endl;
  gq.pop(); //{1, 0, -1, -100} 100 pop
  lq.pop(); //{100, 1, 0, -1} -100 pop

  cout << "gq size: " << gq.size() << endl;
  cout << "lq size: " << lq.size() << endl;

  cout << "gq: "; //{1, 0, -1, -100}
  for (; !gq.empty(); ) {
    cout << gq.top() << " ";
    gq.pop();
  }
  cout << endl;

  cout << "lq: "; //{100, 1, 0, -1}
  for (; !lq.empty(); ) {
    cout << lq.top() << " ";
    lq.pop();
  }
  cout << endl;
}
