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
int main(){
  int n, w;
  cin >> n >> w;
  vector<int> a(n);
  rep(i,n)cin >> a[i];
  set<int> ans;
  for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<n;k++){
    int tmp = a[i] + a[j] + a[k];
    if(tmp <= w)ans.insert(tmp);
  }
  for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
    int tmp = a[i] + a[j];
    if(tmp <= w)ans.insert(tmp);
  }
  for(int i=0;i<n;i++){
    if(a[i] <= w)ans.insert(a[i]);
  }
  cout << ans.size() << endl;
}