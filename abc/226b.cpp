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
bool cmp(P& a, P& b){
  return a.first < b.second;
}
int main(){
  int n;
  cin >> n;
  set<string> a;
  rep(i,n){
    int l;
    cin >> l;
    string str;
    rep(j,l){
      string tmp;
      cin >> tmp;
      while(tmp.size() < 6){
        tmp += " ";
      }
      str += tmp;
    }
    a.insert(str);
  }
  cout << a.size() << endl;
}
