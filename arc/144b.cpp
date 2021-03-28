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
int main(){
    int n;
    cin >> n;
    vector<int> f(n);
    rep(i,n)cin >> f[i];
    rep(i,n)f[i]--;
    vector<int> dp(n);
    int gather = 0;
    rep(i,n){
        if(dp[i] == 1)continue;
        set<int> s;
        int now = i;
        while(1){
            if(s.find(now) != s.end()){
                gather++;
                break;
            }
            if(dp[now]){
                break;
            }
            dp[now] = 1;
            s.insert(now);

            now = f[now];
        }
    }
    mint ans = 1;
    rep(i,gather){
        ans *= 2;
    }
    cout << (ans - 1).val() << endl;
}
