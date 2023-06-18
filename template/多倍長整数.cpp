#include <bits/stdc++.h>

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#define ll long long
using namespace std;

// ここから
namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;

int main() {
  Bint n_bint = (ll)1e18;

  cout << n_bint * n_bint << endl;
}