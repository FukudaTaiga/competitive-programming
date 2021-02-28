#include <bits/stdc++.h>
using namespace std;

int main() {
  //__gcd(a, b): a, bのgcd. <algorism>のインクルードが必要.
  //O(log(max(a,b)))
  //gccでは使えるが, 他では... C++17 以降では gcd/lcm が使える.
  int a, b;

  cout << "type integer a, b" << endl;
  cin >> a >> b;

  cout << "GCD: " << __gcd(a, b) << endl;
  cout << "LCM: " << a / __gcd(a, b) * b << endl; //a * b / __gcd(a, b)よりオーバーフローしづらい.
}
