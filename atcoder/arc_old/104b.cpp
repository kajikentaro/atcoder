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
    vector<int> s(n);
    rep(i,n){
        char in;
        cin >> in;
        const char series[] = {'A','T','C','G'};
        rep(j,4)if(series[j] == in)s[i] = j;
    }
    vector<vector<int>> sum(n,vector<int>(4));
    sum[0][s[0]]++;
    rep(i,n){
        if(i==0)continue;
        rep(j,4){
            sum[i][j] = sum[i-1][j];
            if(s[i] == j)sum[i][j]++;
        }
    }
    ll ans = 0;
    rep(i,n)rep(j,i){
        vector<int> local_sum(4);
        rep(k,4){
            local_sum[k] = sum[i][k];
            if(j==0)continue;
            local_sum[k] -= sum[j-1][k];
        }
        if(local_sum[0] == local_sum[1] && local_sum[2] == local_sum[3])ans++;
    }
    cout << ans << endl;
}
