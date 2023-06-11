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
  string s;
  string a = "oxx";
  string b = "xxo";
  string c = "xox";
  bool aa = true;
  bool bb = true;
  bool cc = true;
  cin >> s;
  rep(i,s.length()){
    if(s[i] != a[i%3])aa = false;
    if(s[i] != b[i%3])bb = false;
    if(s[i] != c[i%3])cc = false;
  }
  if(aa || bb || cc){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}