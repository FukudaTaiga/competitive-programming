#include <bits/stdc++.h>
using namespace std;

//queue <queue>
int main() {
  queue<int> que; //queueの宣言. {}
  //コピーは=で行える.

  // pop, push, empty, front: O(1)
  cout << "push 1" << endl;
  que.push(1); //{1}
  cout << "push 2" << endl;
  que.push(2); //{1, 2}
  cout << "push 3" << endl;
  que.push(3); //{1, 2, 3}

  cout << "size: " << que.size() << endl;

  cout << "pop" << endl;
  que.pop(); //{2, 3}

  cout << "size: " << que.size() << endl;

  cout << "queue: bot ";
  for (;!que.empty(); ) {
    cout << que.front() << " "; //アクセス
    que.pop();
  }
  cout << "top" << endl;
}
