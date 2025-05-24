#include <bits/stdc++.h>

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#define rep(x, y) for (int x = 0; x < y; x++)
#define ll long long
using namespace std;

// ここから
namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;

int main() {
  Bint ans = (ll)1;

  int n, k;
  cin >> n >> k;
  rep(i, n) {
    ll a;
    cin >> a;
    ans = ans * a;
    if (ans >= (ll)pow(10, k)) {
      ans = 1;
    }
  }

  cout << ans << endl;
}