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
using mint = modint998244353;
using P = pair<int,int>;
template <typename T>
struct BIT{
  int n;
  vector<T> bit;
  BIT(int n): n(n+1), bit(n+1,0){}
  void add(int p, T x){
    // (i&-1)で末尾の1を求める
    for(int i = p;i<n;i+=(i&-i)){
      bit[i] += x;
    }
  }
  T sum(int p){
    T s(0);
    for(int i=p;i>0;i-=(i&-i)){
      s += bit[i];
    }
    return s;
  }
};
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n)cin >> a[i];
  rep(i,n)cin >> b[i];
  int max = 3001;
  BIT<mint> bit(max);
  for(int i=a[0];i<=b[0];i++){
    bit.add(i,1);
  }
  rep(i,n){
    if(i==0)continue;
    BIT<mint> bit2(max);
    for(int j=a[i];j<=b[i];j++){
      bit2.add(j,bit.sum(j));
    }
    swap(bit2,bit);
  }
  cout << bit.sum(max-1).val() << endl;

}