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
string func(){
  string s[2];
  cin >> s[0] >> s[1];
  int c = 0;
  rep(i,2)rep(j,2)if(s[i][j] =='#')c++;
  if(c >= 3){
    return "Yes";
  }else if(c == 2){
    if(s[0][0] == '#' && s[1][1] == '#')return "No";
    if(s[0][1] == '#' && s[1][0] == '#')return "No";
    return "Yes";
  }
  return "No";
}
int main(){
  cout << func() << endl;
}