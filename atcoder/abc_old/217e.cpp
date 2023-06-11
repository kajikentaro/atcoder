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
  int q;
  cin >> q;
  priority_queue<int,vector<int>,greater<int>> sort_que;
  int n;
  queue<int> pre_que;
  rep(i,q){
    int qq;
    cin >> qq;
    if(qq == 1){
      int x;
      cin >> x;
      pre_que.push(x);
    }
    if(qq == 2){
      if(sort_que.size()){
        cout << sort_que.top() << endl;
        sort_que.pop();
      }else{
        cout << pre_que.front() << endl;
        pre_que.pop();
      }
    }
    if(qq == 3){
      while(pre_que.size()){
        sort_que.push(pre_que.front());
        pre_que.pop();
      }
    }
  }
}
