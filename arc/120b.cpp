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
ll func(){
    ll h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h)cin >> s[i];
    vector<ll> R_cnt(h+w);
    vector<ll> B_cnt(h+w);
    vector<ll> dot_cnt(h+w);
    ll ma = 0;
    rep(i,h)rep(j,w){
        ll dist = i + j;
        if(s[i][j] == '.')dot_cnt[dist]++;
        if(s[i][j] == 'R')R_cnt[dist]++;
        if(s[i][j] == 'B')B_cnt[dist]++;
        chmax(ma, dist);
    }
    ll free = 0;
    rep(i,ma + 1){
        if(R_cnt[i] * B_cnt[i] != 0)return 0;
        if(R_cnt[i] == 0 && B_cnt[i] == 0)free++;
    }
    mint ans = 1;
    rep(i,free){
        ans *= 2;
    }
    return ans.val();
}
int main(){
    cout << func() << endl;
}