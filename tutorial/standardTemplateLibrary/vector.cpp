#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> vec; //宣言
  //初期化前に代入, copyはNG!
  //初期化
  vec = {1, 1, 2, 3, 5};
  vector<int> vec1(5); //{0,0,0,0,0}で初期化される. stringだったら"".
  /**
  以下は同義だが, vector推奨
  int vec1[5]; vec1がそのままiteratorになる
  array<int, 5> vec1;
  */
  vector<int> vec2(5, 3); //{3,3,3,3,3} 初期化
  vector<int> vec3 = vector<int>(5, 3); //上書きも可能.
  //slice(itr1, itr2) itr1 -> itr2-1
  vec3 = vector<int>(vec.begin() + 1, vec.end() - 1);
  vec3 = vector<int> (vec); //copy

  cout << "vec: { ";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i) << " "; //i番目のアクセス.
    //vec[i]でも可能. #define _GLIBCXX_DEBUGと書かないと[]でのアクセスはエラー分かりづらい.
  }
  cout << "}" << endl;

  cout << "first element is " << *vec.begin() << endl; //先頭要素への参照 = vec.front()
  cout << "last element is " << vec.back() << endl; //末尾要素への参照
  //末尾の次のイテレータ vec.end();

  vec.push_back(8); //末尾に追加. {1, 1, 2, 3, 5, 8}
  vec.pop_back(); //末尾を削除. {1, 1, 2, 3, 5}
  //いずれもO(1)

  //配列の比較
  vector<int> v1 = { 1, 2, 3 };
  vector<int> v2 = { 1, 2, 3 };

  cout << vec1 == vec2 << endl; //true

  /**↓これはコンパイルエラーになる
  if (vec1 == { 1, 2, 3 }) {
    cout << "NG" << endl;
  }
  */


  //多次元配列
  int h = 5, w = 5;

  vector<vector<int>> vv(h, vector<int>(w));

  for (int i = 0; i < h; i++) {
    cout << "[" << endl;
    for (int j = 0; j < w; j++) {
      cout << vv.at(i).at(j) << " ";
    }
    cout << "]" << endl;
  }

  cout << endl;

  //一次元配列による表現
  vector<int> vv1(h * w);
  cout << "[" << endl;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << vv.at(w*i + j) << " ";
    }
    cout << endl;
  }
  cout << "]" << endl;

  //Nx0の行列(縦の初期値の省略)
  vector<vector<int>> vv0(h);


}
