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
    vector<vector<ll>> cls_sum(2,vector<ll>(n));
    vector<int> point(n);
    vector<int> cls(n);
    rep(i,n)cin >> cls[i] >> point[i];
    rep(i,n)cls[i]--;
    rep(i,n){
        cls_sum[cls[i]][i] += point[i];
        if(i==0)continue;
        cls_sum[0][i] += cls_sum[0][i-1];
        cls_sum[1][i] += cls_sum[1][i-1];
    }
    int q;
    cin >> q;
    rep(i,q){
        int l,r;
        cin >> l >> r;
        l-=2;r--;
        if(l < 0)cout << cls_sum[0][r] << " " << cls_sum[1][r] << endl;
        else cout << cls_sum[0][r] - cls_sum[0][l] << " " << cls_sum[1][r] - cls_sum[1][l] << endl;
    }
}
