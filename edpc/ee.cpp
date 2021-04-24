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
    int d;
    string n;
    cin >> d >> n;
    mint dp[10010][10][2] = {};
    dp[0][0][1] = 1;
    n = '0' + n;
    rep(i,n.size()-1){
        rep(a,10){
            if(a > n[i] - '0'){
                continue;
            }else if(a == n[i] - '0'){
                rep(b,d)dp[i+1][(a+b)%d][1] += dp[i][b][1];
            }else{
                rep(b,d)dp[i+1][(a+b)%d][0] += dp[i][b][1];
            }
        }
        rep(a,10){
            rep(b,d)dp[i+1][(a+b)%d][0] += dp[i][b][0];
        }
    }
    cout << (dp[n.size() - 1][0][0] + dp[n.size() - 1][0][1] - 1).val() << endl;
}
