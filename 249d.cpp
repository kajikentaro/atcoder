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
vector<int> func(int n) {
  vector<int> k;
  for (int i = 1; i * i <= n; i++) {
    if (i * i == n) {
      k.push_back(i);
    } else if (n % i == 0) {
      k.push_back(i);
      k.push_back(n / i);
    }
  }
  return k;
}
int main(){
  int n;
  cin >> n;
  int A[200010] = {};
  vector<int> B(n);
  rep(i,n){
    int input;
    cin >> input;
    A[input]++;
    B[i] = input;
  }
  sort(B.begin(), B.end());
  ll ans = 0;
  rep(i,n){
    int x = B[i];
    vector<int> yakusu = func(x);
    for(auto y : yakusu){
      int p = y;
      if(x % p != 0)continue;
      int q = x / p;

      int p_sum = A[p];
      int q_sum = A[q];
      ans += (ll)p_sum * q_sum;
    }
  }
  cout << ans << endl;
}