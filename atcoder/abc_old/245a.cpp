#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(x, y) for (int x = 0; x < y; x++)
#define rrep(x, y) for (int x = y - 1; x >= 0; x--)
#define orep(x, y) for (int x = 1; x <= y; x++)
#define ll long long
template <class T>
bool chmax(T &a, const T &b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
  if (b < a)
  {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int, int>;
string func()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  string T = "Takahashi";
  string A = "Aoki";
  if (a > c)
  {
    return T;
  }
  if (a < c)
  {
    return A;
  }
  if (b > d)
  {
    return T;
  }
  if (b < d)
  {
    return A;
  }
  return T;
}
int main()
{
  cout << func() << endl;
}