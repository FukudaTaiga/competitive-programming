#include <bits/stdc++.h>
using namespace std;

//GCD(greatest common diveiser) of a and b
long long euclid(long long a, long long b) {
  while (b != 0) { //a % b != 0
    a %= b;
    swap(a, b);
  }

  return a; //return b;
}

//n * x + m * y = 1を満たすl, kを求める.
//n, mは互いに素でなければならない.
pair<long long, long long> ex_euc(long long n, long long m) {
  //行列表記にして逆行列を考えると変数更新が分かりやすい.
  long long x = 0, y = 1;
  long long z = 1, w = - (n / m);

  while (n % m != 0) {
    n %= m;
    swap(n, m);
    x -= (n / m) * z;
    y -= (n / m) * w;
    swap(x, z);
    swap(y, w);
  }

  return make_pair(x, y);
}

int main() {
  //extended euclid
  long long a, b, c;
  long long x, y;
  long long temp;

  cout << "input ax + by = c" << endl;
  cout << "type a" << endl;
  cin >> a;
  cout << "type b" << endl;
  cin >> b;
  cout << "type c" << endl;
  cin >> c;

  temp = a;
  a = max(a, b);
  b = min(temp, b);

  const long long d = euclid(a, b);

  //a'x + b'y = 1なるx, yを求めれば,
  //(a'*d)*(x*c') + (b'*d)*(y*c') = c'*dとして解が求まる.
  if (c % d == 0) {
    tie(x, y) = ex_euc(a / d, b / d);
    x *= c / d;
    y *= c / d;
  }
  else {
    cout << "there is no solution" << endl;
    return 0;
  }

  if (max(a, b) == temp) {
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
  }
  else {
    cout << "x: " << y << endl;
    cout << "y: " << x << endl;
  }

  return 0;
}


/**
pair<int, int> ex_euc(int n, int m) {
  //2020/12/28
  vector<int> v(0);
  //この方法だとサイズが非常に大きくなり実行時エラーになる.

  while ((n % m) != 1) {
    v.push_back(- n / m);
    n %= n % m;
    swap(n, m);
  }

  int k = 1, l = - n / m;

  reverse(v.begin(), v.end());

  for (auto i = 0; i < (int) v.size(); i++) {
    k += l * v.at(i);
    swap(k, l);
  }

  return make_pair(k, l);
}
*/
