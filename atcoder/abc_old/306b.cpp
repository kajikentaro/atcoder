#include <bits/stdc++.h>

#include <atcoder/all>
// 多倍長テンプレ
/* ---------------------- ここから ---------------------- */
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using namespace std;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;
/* ---------------------- ここまで ---------------------- */

int main() {
  int n = 64;
  // 整数
  Bint now = 1;
  Bint ans = 0;
  Real d = -1.0;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ans += now * a;
    now *= 2;
  }
  cout << ans << endl;
}
