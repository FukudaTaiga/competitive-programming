#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "__builtin_popcount" << endl;
  //2進数表記での1の個数を返す. includeは特になし.
  //__builtin_popcountll(x)もある.
  //popcnt, popcnt64は<intrin.h>
  cout << __builtin_popcount(42) << endl; //101010 -> 3

  //bitset <bitset>

  //長さ250000のbitset(250000 桁の 2 進数だと思ってよい)
  bitset<250000> bs1;

  //長さ8の bitsetを定義する.整数から初期化を行う.
  bitset<8> bs2(131); //7bit目から0bit目への順番で10000011

  //長さ8のbitsetを定義する.2進数から初期化を行う.
  bitset<8> bs3("10000011"); //7bit目から0bit目への順番で10000011

  //やってることは変わらない.ただ bitset の長さが増えただけ.
  bitset<2000> bs4("10000011"); //1999bit目から0bit目の順番で0...010000011

  bs2.set(3); //bs2の3bit目を1に. (2^3)
  bs2[3] = true;
  cout << bs2[3] << endl; //bs2の3bit目にアクセス.
  bs2.reset(3); //bs2の3bit目を0に.
  cout << bs2[3] << endl;
  bs2.flip(); //全bit反転.
  bs2.flip(2); //2bit反転.
  bs2[5].flip(); //5bit反転.

  cout << (bs2 >> 5) & 1 << endl; //5bit目が立ってるか.
  cout << bs2 & (1 << 5) << endl; //条件判定はこれでも行ける.
  //bitmaskで条件を複数判定できる.
  bitset<3> mask(5);
  cout << bs2 & mask << endl; //maskのどれかが立ってるか
  cout << (bs2 & mask) == mask << endl; //全部立ってるか.

  //bit演算 not ~, or |, and &, xor ^, right shift >>, left shift <<も同様に行える.
  //bitsetの演算はN/32でかなり早い.
}

//combinationはbit = next_combination(bit)で表現できる.
//k-conbinationならbit = (1 << k) - 1と設定する.

/**
やりたいこと                                  実装                   集合
ビット S に i 番目のフラグが立っているか       if (S & (1<<i))        i∈S
ビット S に i 番目のフラグが消えているか	      if (!(S & (1<<i)))     i∉S
ビット S に i 番目のフラグを立てる             S |= (1<<i)            S = S∪{i}
ビット S に i 番目のフラグを消す               S &= ~(1<<i)           S = S-{i}
ビット S に何個のフラグが立っているか          __builtin_popcount(S)  Sの要素数
すべてのフラグが消えている状態	                0	                     空集合∅
すべてのフラグが立っている状態	                (1<<n) - 1	           {0,1,…,n−1}
ビット S に i 番目のフラグを立てたもの         S | (1<<i)              S∪{i}
ビット S に i 番目のフラグを消したもの         S & ~(1<<i)            S-{i}
                                             S & T                  S∩T
                                             S|T                   S∪T
                                             if (S & T)	            S∩T≠∅ かどうか
                                             if (!(S & T))	        S∩T=∅ かどうか
*/
