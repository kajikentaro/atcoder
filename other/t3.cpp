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
    int h,w;
    cin >> h >> w;
    vector<vector<int>> a(h,vector<int>(w));
    rep(i,h)rep(j,w)cin >> a[i][j];
    vector<int> h_sum(h), w_sum(w);
    rep(i,h)rep(j,w)h_sum[i] += a[i][j];
    rep(i,h)rep(j,w)w_sum[j] += a[i][j];
    rep(i,h){
        rep(j,w){
            int ans = h_sum[i] + w_sum[j] - a[i][j];
            cout << ans << " ";
        }
        cout << endl;
    }
}
