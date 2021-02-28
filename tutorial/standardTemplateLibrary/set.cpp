#include <bits/stdc++.h>
using namespace std;

//set <set>
//sortされる順序付き配列みたいなもの. 内部的には木.
int main() {
  set<int> s; //宣言　{}
  set<int> s1{4343, 321, 4369}; //初期化
  multiset<int> muls;

  //add
  cout << "set add" << endl;
  s.insert(1);
  cout << "set add" << endl;
  s.insert(1);
  cout << "set add" << endl;
  s.insert(2);
  cout << "set add" << endl;
  s.insert(3);
  //{1, 2, 3}

  cout << "set size" << s.size() << endl;

  cout << "multiset add" << endl;
  muls.insert(1);
  cout << "multiset add" << endl;
  muls.insert(1);
  cout << "multiset add" << endl;
  muls.insert(2);
  cout << "multiset add" << endl;
  muls.insert(3);
  //{1, 1, 2, 3}

  cout << "multiset size" << muls.size() << endl;

  cout << "erase 1" << endl;
  muls.erase(1); //{2, 3} 要素による削除

  cout << "multiset size" << muls.size() << endl;

  muls.insert(1);

  cout << "erase first" << endl;
  muls.erase(muls.begin()); //{1, 2, 3} itratorによる削除

  s1.clear(); //全削除

  cout << "s: { ";
  for (auto itr = s.begin(); itr != s.end(); ++itr) {
    cout << *itr << " "; //アクセスはiteratorによる.
  }
  cout << "}" << endl;

  //contains
  cout << s.contains(1) << endl;
  cout << (s.find(x) != s.end()) << endl;

  cout << "lower_bound index s, 2" << endl;
  cout << distance(s.begin(), s.lower_bound(2)) << endl; //lower_bound(s.begin(), s.end(), 2);
  cout << distance(s.begin(), lower_bound(s.begin(), s.end(), 2)) << endl;
}

/**
setでは比較演算子がなければならない.
存在しない場合は自分で定義
struct Person {
    string m_name;
    int    m_height;
};
// 比較演算子の定義
bool operator<(const Person &lhs, const Person &rhs)
{
    return lhs.m_name < rhs.m_name;
}
std::set<Person> st;
*/
