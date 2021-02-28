#include <bits/stdc++.h>
using namespace std;

int main() {
  //abs: 絶対値を得る. #include <cmath>で使える.
  //int, float, double全部対応.
  double a = 255, b = 63;

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "absolute value of a - b: " << abs(a - b) << endl;
  cout << endl;

  //sin(x), cos(x), tan(x)
  //xはラジアンで与える.
  const double pi = 3.141592653589793238;
  double x = 30;
  double rad = x * (pi / 180);

  cout << "x: " << x << "゜" << endl;
  cout << "x: " << rad << "radian" << endl;
  cout << "sin(x): " << sin(rad) << endl; //sin(x)は間違い.
  cout << "cos(x): " << cos(rad) << endl;
  cout << "tan(x): " << tan(rad) << endl;
  cout << endl;

  //min, max
  int d = 1, e = 2, f = 3;
  vector<int> v = {1000, 27, 3, 54, 0, -48};

  cout << "d: " << d << endl;
  cout << "e: " << e << endl;
  cout << "f: " << f << endl;
  cout << "min of d and e" << min(d, e) << endl;
  cout << "max of d and e and f" << max({d, e, f}) << endl; //複数要素を比較するときは{}忘れないように.
  cout << "vector v: ";
  for (auto e : v) {
    cout << e << " ";
  }
  cout << endl;
  cout << "minimum element of v" << *min_element(v.begin(), v.end()) << endl;
  //iteratorが返ってくるから*で値を取ってくる.
}
