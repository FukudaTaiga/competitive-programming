#include <bits/stdc++.h>
using namespace std;

const float pi = 3.141592653589793238;

int main() {
  //printf(),fprintf(),sprintf()

  //表示桁数: %<全体の幅>.<小数点以下の幅><フォーマット指定子>

  printf("char %c\n", 'a'); //%c: char
  printf("string %s\n", "str"); //%s: char*, string

  printf("int %d\n", 1); //%d: int, short, ... , %o: 8進数表記, %x: 16進数表記, %u: unsigned ~
  printf("long %ld\n", 100000000000); //%ld: long, %lo: 8進数表記, %lx: 16進数表記, %u: unsigned long

  //%gで適した方が選ばれる.
  printf("float %8.3f\n", pi); //%f: float 実数
  printf("float %.3e\n", pi*100); //%e: float .....e^? <仮数>*10^<指数>表記

  printf("double %.10lf\n", 123456789.123456789); //%lf: double

  printf("ゼロ詰め %05d\n", 1); //ゼロ詰め　00001
  //右詰め -つける. デフォルトは左詰め.
  printf("右詰め [%-15s]\n", "I am a boy."); //[I am a boy.    ]
  //符号表記 +つける.
  printf("符号表記 +: %+5d\n", 32); //  +32
  printf("符号表記 -: %+5d\n", -32); //  -32
}
