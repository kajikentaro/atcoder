#include<bits/stdc++.h>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define orep(x,y) for(int x=1;x<=y;x++)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
int main(){
  string x;
  cin >> x;
  vector<int> keta(10);
  for(char a : x){
    keta[a - '0']++;
  }
  for(int i=1;i<10;i++){
    if(keta[i]){
      keta[i]--;
      cout << i;
      break;
    }
  }
  rep(i,10){
    while(keta[i]){
      keta[i]--;
      cout << i;
    }
  }
  cout << endl;
}
