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
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    int ans = 0;
    rep(i,n){
        int max_v = 0;
        int min_a = a[i];
        rep(j,n){
        if(i + j >= n)break;
            int now_a = a[i+j];
            chmin(min_a, now_a);
            chmax(max_v, (j+1) * min_a);
        }
        chmax(ans, max_v);
    }
    cout << ans << endl;
}
