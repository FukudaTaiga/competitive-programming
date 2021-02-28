#include <bits/stdc++.h>
using namespace std;

int main() {
  double sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;

  gy *= -1;

  double k = (gy - sy) / (gx - sx);

  //y - sy = k(x - sx)
  double x = sx - (sy / k);

  cout << fixed << setprecision(10);
  cout << x << endl;
}
