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
ll n,k;
vector<vector<ll>> a;
bool can(ll wj){
    vector<vector<ll>> b(n,vector<ll>(n));
    vector<vector<ll>> c(n,vector<ll>(n));
    rep(i,n)rep(j,n){
        if(a[i][j] <= wj)b[i][j] = 1;
    }
    rep(i,n){
        c[i][0] = b[i][0];
        rep(j,n){
            if(j == 0)continue;
            c[i][j] = c[i][j-1] + b[i][j];
        }
    }
    ll base = k * k -  (k * k) / 2;
    rep(i,n-k+1){
        rep(j,n-k+1){
            ll wa = 0;
            ll x_right = j + k - 1;
            rep(p,k){
                ll y =  i + p;
                if(j-1 >= 0) wa += c[y][x_right] - c[y][j - 1];
                else wa += c[y][x_right];
            }
            if(wa >= base)return true;
        }
    }
    return false;
}
int main(){
    cin >> n >> k;
    a.resize(n,vector<ll>(n));
    rep(i,n)rep(j,n)cin >> a[i][j];
    ll wa = 0;
    ll ac = 1e9 + 10;
    while(ac - wa != 1){
        ll wj = (ac + wa) / 2;
        if(can(wj)){
            ac = wj;
        }else{
            wa = wj;
        }
    }
    cout << ac << endl;
}
