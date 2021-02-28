#include<bits/stdc++.h>
using namespace std;

//mod の世界における逆元
int main() {
  long long a, n;
  cout << "a op b mod n = x?" << endl;
  cout << "type a, n" << endl;

  cin >> a >> n;

  cout << a << " + b " << "mod " << n << " = x"<< endl;
  for (auto i = 0; i < n; i++) {
    cout << "b: " << i << ", x: " << (i + a) % n << endl;
  }
  cout << endl;

  cout << a << " - b " << "mod " << n << " = x"<< endl;
  for (auto i = 0; i < n; i++) {
    //c++ではa % nを考えるとき a = n * (a / n) + a % nとなるようにとる.
    //そのため0~n-1でなく-が出力されることがある.
    if ((i - a) % n < 0) {
      cout << "b: " << i << ", x: " << (i - a) % n + n << endl;
    }
    else cout << "b: " << i << ", x: " << (i - a) % n << endl;
  }
  cout << endl;

  cout << a << " * b " << "mod " << n << " = x"<< endl;
  for (auto i = 0; i < n; i++) {
    //*を考えるとき, オーバーフローする可能性は頭の隅に置いておくと良い.
    //a * b % nを計算するときは
    //(a % n) * (b % n) % n
    //とすることも考えておくこと;
    cout << "b: " << i << ", x: " << (i % n) * (a % n) % n << endl;
  }
  cout << endl;
}
