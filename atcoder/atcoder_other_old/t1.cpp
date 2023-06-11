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
    #define int long long
    int n,l,k;
    cin >> n >> l >> k;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    ll ac = 0;
    ll inf = 1e9;
    ll wa = inf;
    while(wa - ac != 1){
        int wj = (wa + ac) / 2;
        int pre_cut = 0;
        int cut_cnt = 0;
        rep(i,n){
            if(a[i] - pre_cut >= wj){
                pre_cut = a[i];
                cut_cnt++;
            }
        }
        if(l - pre_cut < wj)cut_cnt--;
        if(cut_cnt >= k)ac = wj;
        else wa = wj;
    }
    cout << ac << endl;
}