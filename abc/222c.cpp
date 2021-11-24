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
struct Human{
  int win,no;
  string hands;
  int ans;
};
int judge(char a, char b){
  if(a == 'G' && b == 'C')return 1;
  if(a == 'C' && b == 'P')return 1;
  if(a == 'P' && b == 'G')return 1;
  return 0;
}
int main(){
  int n,m;
  cin >> n >> m;
  vector<Human> human(2*n);
  rep(i,2*n){
    human[i].win = 0;
    human[i].no = i;
    cin >> human[i].hands;
  }
  auto cmp1 = [&](Human& a, Human& b){
    if(a.win == b.win){
      return a.no < b.no;
    }
    return a.win > b.win;
  };
  rep(i,m){
    rep(j,n){
      Human& ha = human[2*j];
      Human& hb = human[2*j+1];
      ha.win += judge(ha.hands[i], hb.hands[i]);
      hb.win += judge(hb.hands[i], ha.hands[i]);
    }
    sort(human.begin(), human.end(), cmp1);
  }
  rep(i,2*n){
    cout << human[i].no + 1 << endl;
  }
}