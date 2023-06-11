#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define orep(x,y) for(int x=1;x<=y;x++)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int,int>;
long long merge_cnt(vector<ll> &a);
int main(){
    //和が等しくない＝-1
    vector<ll> test = {8,5,4,7,5};
    vector<ll> test2 = {10,5,6,7,4,1};
    cout << merge_cnt(test) << endl;;
    cout << merge_cnt(test2) << endl;;
}

long long merge_cnt(vector<long long> &a) {
  int n = a.size();

  if (n <= 1) {
    return 0;
  }

  long long cnt = 0;

  vector<long long> b(a.begin(), a.begin() + n / 2);
  vector<long long> c(a.begin() + n / 2, a.end());

  cnt += merge_cnt(b);
  cnt += merge_cnt(c);

  int ai = 0, bi = 0, ci = 0;
  // merge の処理
  while (ai < n) {
    if (bi < (int)b.size() && (ci == (int)c.size() || b[bi] <= c[ci])) {
      a[ai++] = b[bi++];
    } else {
      cnt += n / 2 - bi;
      a[ai++] = c[ci++];
    }
  }
  return cnt;
}