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
    const int inf = 1e9;
    int bottom_max = -inf;
    rep(i,n){
        int tmp;
        cin >> tmp;
        chmax(bottom_max, tmp);
    }
    int up_min = inf;
    rep(i,n){
        int tmp;
        cin >> tmp;
        chmin(up_min, tmp);
    }
    int ans = max(up_min - bottom_max + 1,0);
    cout << ans << endl;
}
