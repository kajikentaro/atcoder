#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
int grid[3000][3000] = {};
vector<vector<mint>> dp(3000,vector<mint>(3000));
vector<vector<mint>> birth_down(3000,vector<mint>(3000));
vector<vector<mint>> birth_left(3000,vector<mint>(3000));
vector<vector<mint>> birth_cross(3000,vector<mint>(3000));
int myadd(int i,int j,int a,int b){
    if(grid[a][b] == 0){
        dp[a][b] += dp[i][j];
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int h,w;
    cin >> h >> w;
    rep(i,h)rep(j,w){
        char tmp;
        cin >> tmp;
        if(tmp=='#'){
            grid[i][j] = 1;
        }
    }
    dp[0][0] = 1;
    birth_down[0][0] = 0;
    birth_left[0][0] = 0;
    rep(i,h){
        rep(j,w){
            if(myadd(i,j,i+1,j)){
                birth_down[i][j+1] = birth_down[i][j+1];
            }
            if(myadd(i,j,i,j+1)){
                birth_left[i+1][j] = birth_left[i+1][j];
            }
            if(myadd(i,j,i+1,j+1)){
                birth_cross[i+1][j+1] = birth_cross[i+1][j+1];
            }
        }
    }
    cout << dp[h-1][w-1].val() << endl;
}