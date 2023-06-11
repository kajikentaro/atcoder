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
string x;
ll inf = (ll)4e18 + 10;
ll calc(ll n){
    ll ans = 0;
    ll e = 1;
    rep(i,x.size()){
        if(ans > inf / n)return inf;
        ans *= n;
        ans += x[i] - '0';
    }
    return ans;
}
vector<ll> keta;
int main(){
    ll m;
    cin >> x >> m;
    keta.push_back(1);
    if(x.size() == 1){
        if(x[0] - '0' <= m){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
        return 0;
    }

    ll ac,max_x;
    max_x = ac = *max_element(x.begin(), x.end()) - '0';
    ll wa = inf;
    while(1){
        if(wa - ac == 1)break;
        ll wj = (ac + wa) / 2;
        if(calc(wj) <= m){
            ac = wj;
        }else{
            wa = wj;
        }
    }
    cout << ac - max_x << endl;
}
