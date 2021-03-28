#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define orep(x,y) for(int x=1;x<=y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define mint modint1000000007
#define ll long long
using namespace std;
using namespace atcoder;   
int main(){
    string s,t;
    cin >> s >> t;
    int sn,tn;
    sn = s.size();
    tn = t.size();
    vector<vector<int>> dp(sn+1,vector<int>(tn+1));
    dp[0][0] = 0;
    rep(i,sn+1)rep(j,tn+1){
        if(i+1 <= sn && dp[i+1][j] < dp[i][j]){
            dp[i+1][j] = dp[i][j];
        }
        if(j+1 <= tn && dp[i][j+1] < dp[i][j]){
            dp[i][j+1] = dp[i][j];
        }
        if(i+1 <= sn && j+1 <= tn && s[i] == t[j] && dp[i+1][j+1] < dp[i][j] + 1){
            dp[i+1][j+1] = dp[i][j] + 1;
        }
    }
    int ans_n = dp[sn][tn];
    string ans = "";
    for(int i=0;i<ans_n;){
        if(s[sn-1] == t[tn-1]){
            i++;
            ans += s[sn-1];
            sn--;
            tn--;
        }else{
            if(tn-1 >= 0 && dp[sn][tn-1] > dp[sn-1][tn]){
                tn--;
            }else{
                sn--;
            }
        }
    }
    string ans2 = "";
    rrep(i,ans.size()){
        ans2 += ans[i];
    }
    cout << ans2 << endl;
}
