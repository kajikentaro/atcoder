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
  int n,q;
  cin >> n >> q;
  vector<int> dict(n);
  vector<int> ball(n);
  rep(i,n){
    dict[i] = i;
    ball[i] = i;
  }
  rep(i,q){
    int x;
    cin >> x;
    x--;
    int idx = dict[x];
    int value = ball[idx];
    int target_idx = idx + 1;
    if(target_idx >= n)target_idx = idx - 1;
    int target_value = ball[target_idx];

    swap(ball[idx], ball[target_idx]);
    swap(dict[value], dict[target_value]);
  }
  rep(i,n){
    cout << ball[i] + 1 << " ";
  }
  cout << endl;
}