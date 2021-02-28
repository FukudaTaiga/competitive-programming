#include <bits/stdc++.h>
using namespace std;

int main() {
  string str = "hello";
  char ch;

  ch = str.at(2); //l 添え字は0から. str[2].

  cout << "str: " << str << endl;
  cout << "str.size(): " << str.size() << endl; //5
  cout << "str(3): " << ch << endl;

  str.at(2) = 'z'; //hezlo
  str += "ooo"; //hezloooo str = str + "ooo"
  str += 'o'; //hezlooooo str = str + 'o'

  cout << "str: " << str << endl; //hezlooooo
  cout << "str 3~: " << str.substr(2) << endl; //zlooooo substr(l): l文字目から最後まで
  //zloo substr(l, k): l文字目からl + (k-1)文字目まで. lを含めて取り出したいk文字分取り出す.
  cout << "str 3~6: " << str.substr(2, 4) << endl;

  //stringを使うときは全角に注意

  cout << "Hello"s.size() << endl; // 5（sを末尾につける）
  //cout << "Hello".size() << endl; // できない

  //stringの比較演算
  cout << "ABC < XY: " << ("ABC" < "XY") << endl; //true. 辞書式

  /**
  input OKに対して順に入力を取れる.
  char a, b;
  cin >> a >> b;

  cout << a << endl; //O
  cout << b << endl; //K
  */

  /**
  getlineで一行ずつ入力を取れる.
  string s, t;
  getline(cin, s); // 変数sで入力を一行受け取る
  getline(cin, t); // 変数tで入力を一行受け取る

  cout << "一行目 " << s << endl;
  cout << "二行目 " << t << endl;
  */

  //stringとchar[]では違いがある.
  char text1[] = "ABCDEFGH";

  cout << "[Before]" << endl;
  cout << "text1         : " << text1 << endl;
  cout << "strlen(text1) : " << std::strlen(text1) << endl;

  text1[4] = '\0';

  cout << "[After]" << endl;
  cout << "text1         : " << text1 << endl;
  cout << "strlen(text1) : " << std::strlen(text1) << endl;

  string text2 = "ABCDEFGH";

  cout << "[Before]" << endl;
  cout << "text2          : " << text2 << endl;
  cout << "text2.size()   : " << text2.size() << endl;
  cout << "text2.length() : " << text2.length() << endl;

  text2[4] = '\0';

  cout << "[After]" << endl;
  cout << "text2          : " << text2 << endl;
  cout << "text2.size()   : " << text2.size() << endl;
  cout << "text2.length() : " << text2.length() << endl;

}
