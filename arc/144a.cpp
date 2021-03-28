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
int gcd(int x, int y) {
    if(x % y == 0) {
        return y;
    } else {
        return gcd(y, x % y); 
    }
}
int lcm(int a, int b){
  return a*b / gcd(a, b);
}
int func(){
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n){
        cin >> x[i];
    }
    rep(i,1e6){
        if(i <= 1)continue;
        bool flag = true;
        rep(j,n){
            int g = gcd(x[j],i);
            if(g == 1){
                flag = false;
                break;
            }
        }
        if(flag){
            return i;
        }
    }
}
int main(){
    cout << func() << endl;
}