#include <bits/stdc++.h>
using namespace std;

//nが素数か判定
//O(√n)
bool isprime(int n) {
  int l = sqrt(n);

  for (auto i = 1; i < l + 1; i++) {
    if (n % i == 0) return false;
  }

  return true;
}

//二分累乗法
//O(log(n))
long long exp(long long a, long long n, long long mod) {
  long long x = 1;

  while (n > 0) {
    if (n & 1) x = x * a % mod;
    a = a * a % mod;
    n >>= 1;
  }

  return x;
}

//fermatの小定理 a^p-1 = 1 mod pを用いて求める.
//pは素数
//O(log(p))
long long modinv1(long long a, long long p) {
  return exp(a, p - 2, p) ;
}

//extended euclid
//ax + by = 1
//n > m
pair<long long, long long> ex_euc(long long n, long long m) {
  int x = 0, y = 1, z = 1, w = - (n / m);
  //(0   1 ) (x y)(a)   (r_k  )  b
  //(1 -n/m) (z w)(b) = (r_k+1)  a%b

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

//拡張ユークリッドの互除法による求め方.
//a, pが互いに素であれば解が求まる.
//a*x = 1 mod m <=> a*x - m*y = 1なるx, yが存在する
long long modinv2(long long a, long long m) {
  long long temp;
  int x, y;
  int mod = m;

  temp = a;
  a = max(a, m);
  m = min(temp, m);

  tie(x, y) = ex_euc(a, m);

  if (x < 0) x += mod;
  if (y < 0) y += mod;

  if (temp == a) return x;
  else return y;
}

//a * x = 1 mod nを満たすようなx(aの逆元を求める)
//a * x = b mod nをx = a^-1 * b mod n として求められる.
int main() {
  int i;
  int a, n;
  cout << "type 1 or 2" << endl;
  cin >> i;
  cout << "a * x = 1 mod n" << endl;
  cout << "type a, n" << endl;
  cin >> a >> n;

  if (i == 1) cout << "x = " << modinv1(a, n) << endl;
  else cout << "x = " << modinv2(a, n) << endl;
}
