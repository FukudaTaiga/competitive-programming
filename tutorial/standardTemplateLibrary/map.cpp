#include <bits/stdc++.h>
using namespace std;

//map <map>
int main() {
  //map: keyがsortされている.
  //map<key, value (, compare, allocator)>
  map<string, int> m; //宣言. {}で初期化
  map<string, int> mp{ {"aaa", 1}, {"bbb", 2}, {"ccc", 3}, {"ddd", 3}, {"eee", 3} }; //初期化.
  multimap<string, int> mulm; //{}

  mp.erase(m.begin()); //itr指定で削除
  mp.erase(m.begin(), m.begin() + 2); //erase(itr1, itr2): itr2の手前まで削除.
  mp.erase("eee"); //値指定で削除.
  mp.clear(); //全削除 {}

  //add 重複は許さない.
  //insertの戻り値はpair<iterator, bool>で挿入された場合, trueが返ってくる.
  cout << "map add" << endl;
  m.insert(make_pair("x", 0)); //{ x -> 0  }
  //m["x"] = 0としても追加できる.
  cout << "map add" << endl;
  m.insert(make_pair("y", 1)); //{ x -> 0, y->1 }
  cout << "map add" << endl;
  m.insert(make_pair("z", -1)); //{ x -> 0, y->1, z->-1 }
  cout << "map add" << endl;
  m.insert(make_pair("z", -2)); //{ x -> 0, y->1, z->-1 } 上書きされない.

  cout << "map size " << m.size() << endl;

  //insertの戻り値はiterator. 位置が返ってくる.
  cout << "multimap add" << endl;
  mulm.insert(make_pair("x", 0)); //{ x -> 0  }
  cout << "multimap add" << endl;
  mulm.insert(make_pair("y", 1)); //{ x -> 0, y->1 }
  cout << "multimap add" << endl;
  mulm.insert(make_pair("z", -1)); //{ x -> 0, y->1, z->-1 }
  cout << "multimap add" << endl;
  mulm.insert(make_pair("z", -2)); //{ x -> 0, y->1, z->-1, z -> -2 }

  cout << "multimap size " << mulm.size() << endl;

  /**
  m.insert(itr1, itr2);として範囲内の要素を全部追加できる. void
  m.insert({ {"sss", 3}, {"gtf", 788} });等も可能.
  */

  //mapでは[], atによるアクセスが可能.
  cout << "map(z)" << m.at("z") << endl; //-2
  cout << "map(u)" << m["u"] << endl; //0
  //[]はkeyがない場合はデフォルト値を返す.mapのみ.意図しないkeyの追加が行われる可能性もあるため注意.
  //cout << "m(z)" << m.at("u") << endl; エラー

  //pairなのでfirst, secondによるアクセスが可能.
  cout << "map : key -> value" << endl;
  for (auto itr = m.begin(); itr != m.end(); ++itr) {
    cout << "      " << itr->first << " -> " << itr->second << endl;
  }
  //u, x, y, zの順で表示される.

  cout << "multimap : key -> value" << endl;
  for (auto itr = mulm.begin(); itr != mulm.end(); ++itr) {
    cout << "      " << itr->first << " -> " << itr->second << endl;
  }
  //u, x, y, zの順で表示される.

  string str;
  cout << "type key" << endl;
  cin >> str;
  //mapでkeyが見つかったらそのiteratorを, 見つからなければmap.end()が返される.
  auto itr = m.find(str);
  if (itr != m.end()) cout << "key exists. " << itr->second << endl;
  else cout << "key not exists." << endl;

}
