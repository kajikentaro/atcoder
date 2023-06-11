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
  int n;
  cin >> n;
  set<string> history;
  int max_point = 0;
  int max_idx = -1;
  rep(i,n){
    string s;
    int t;
    cin >> s >> t;
    if(history.count(s))continue;
    history.insert(s);
    if(chmax(max_point, t)){
      max_idx = i;
    }
  }
  cout << max_idx + 1 << endl;
}