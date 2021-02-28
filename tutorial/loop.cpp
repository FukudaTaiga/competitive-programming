#include <bits/stdc++.h>
using namespace std;

int main() {
  /**
  for文: 回数が明示的であるとき使うと楽.

  for (型 変数名; 継続条件; 更新操作) {
  処理
  }
  */

  /**
  範囲for文: コンテナのデータ型に対して使える.配列の要素全てに対する操作等で有用.

  for (配列の要素の型 変数名 : 配列変数) { //&変数名とすると参照できる. 元の配列の書き換えが×.
  処理
  }
  */

  /**
  while文: ループ処理.

  (型 変数名;) <-必要なら
  while(継続条件) {
  処理
  }
  */

  /**
  多重ループを一度にbreakしたいとき
  1.フラグ変数

  bool finished = false;  // 外側のループを抜ける条件を満たしているかどうか(フラグ変数)

  for (int i = 0; i < ... ; i++) {
    for (int j = 0; j < ... ; j++) {

       処理

      if ( 2重ループを抜ける条件 ) {
        finished = true;
        break;  // (＊)
        // finishをtrueにしてからbreakすることで、
        //   内側のループを抜けたすぐ後に外側のループも抜けることができる
      }
    }
    // (＊)のbreakでここに来る

    if (finished) {
      break;  // (＊＊)
    }
  }
  // (＊＊)のbreakでここに来る

  2.returnを使う

  void func( 処理に必要な変数 ) {
  for (int i = 0; i < ... ; i++) {
    for (int j = 0; j < ... ; j++) {

       処理

      if ( 2重ループを抜ける条件 ) {
        return;  // 関数のreturnはループに関係なく抜けることができる
      }
    }
  }
  }

  int main() {
    func();
  }
  */
}
