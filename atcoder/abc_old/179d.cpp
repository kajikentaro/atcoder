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
using mint = modint998244353;
using P = pair<int,int>;
struct A{
    int n;
    bool start;
    A(int n,bool start):n(n), start(start){}
    A(){}
};
int main(){
    ll n,k;     
    cin >> n >> k;
    vector<A> s(2*k);
    rep(i,k){
        ll l,r;
        cin >> l >> r;
        s.emplace_back(l,true);
        s.emplace_back(r,false);
    }
    vector<vector<A>> dp(n+1);
    dp[1] = 1;
    orep(i,n){
        for(auto ss : s){
            ll new_cursor = i + ss;
            if(new_cursor > n)continue;
            dp[new_cursor] += dp[i];
        }
    }
    cout << dp[n].val() << endl;
}