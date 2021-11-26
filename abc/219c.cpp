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
  string x;
  cin >> x >> n;

  map<char,char> alpha;
  rep(i,x.size()){
    alpha[x[i]] = (char)('a' + i);
  }

  vector<pair<string,string>> dict;
  rep(i,n){
    string s;
    cin >> s;
    string new_s = "";
    rep(j,s.size()){
      new_s += alpha[s[j]];
    }
    dict.emplace_back(new_s, s);
  }
  sort(dict.begin(), dict.end());
  rep(i,n){
    cout << dict[i].second << endl;
  }
}