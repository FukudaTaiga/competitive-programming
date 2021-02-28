#include <bits/stdc++.h>
using namespace std;

//stack <stack>
int main() {
  stack<int> stk; //intのstackの宣言. {}
  //コピーは=で行える.

  // pop, push, empty, top: O(1)
  cout << "push 1" << endl;
  stk.push(1); //{1}
  cout << "push 2" << endl;
  stk.push(2); //{1, 2}
  cout << "push 3" << endl;
  stk.push(3); //{1, 2, 3}

  cout << "size: " << stk.size() << endl; //size

  cout << "pop" << endl;
  stk.pop(); //{1, 2}

  cout << "size: " << stk.size() << endl;

  cout << "stack: top ";
  for (; !stk.empty(); ) { //stk.emptyで空判定. stk.size() != 0でも良いが効率的には前者
    cout << stk.top() << " "; //アクセス
    stk.pop();
  }
  cout << "bot" << endl;

}
