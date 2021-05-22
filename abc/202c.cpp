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
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep(i,n){
        cin >> c[i];
        c[i]--;
        c[i] = b[c[i]];
    }
    map<int,P> info;
    rep(i,n){
        info[a[i]].first++;
        info[c[i]].second++;
    }
    ll ans = 0;
    for(auto i : info){
        auto t = i.second;
        ans += (ll)t.first * t.second;
    }
    cout << ans << endl;
}
