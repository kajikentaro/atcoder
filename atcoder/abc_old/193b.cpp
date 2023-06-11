#include<bits/stdc++.h>
#include<atcoder/modint>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
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
    int ans = 1e9;
    rep(i,n){
        int a,p,x;
        cin >> a >> p >> x;
        if(a >= x)continue;
        chmin(ans, p);
    }
    if(ans == 1e9){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}
