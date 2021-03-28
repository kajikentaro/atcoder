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
    int h,w;
    cin >> h >> w;
    vector<vector<char>> grid(h,vector<char>(w));
    vector<vector<mint>> dp(h,vector<mint>(w));
    dp[0][0] = 1;
    rep(i,h)rep(j,w)cin >> grid[i][j];
    int directions[2][2] = {{0,1},{1,0}};
    rep(i,h)rep(j,w){
        dp[i][j] = dp[i][j];
        for(auto d : directions){
            int r = i + d[0];
            int c = j + d[1];
            if(r < 0 || c < 0 || r >= h || c >= w)continue;
            if(grid[r][c] == '#')continue;
            dp[i+d[0]][j+d[1]] += dp[i][j];
        }
    }
    cout << dp[h-1][w-1].val() << endl;

}
