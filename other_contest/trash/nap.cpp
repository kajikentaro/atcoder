#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
vector<vector<int>> dp;
int get(int x,int y){
    if(y<0)return -1e9;
    if(x<0)return 0;
    return dp[x][y];
}
int main(){
    int n,W;
    cin >> n >> W;
    dp.resize(n+1,vector<int>(W+1));
    vector<int> v(n);
    vector<int> w(n);
    rep(i,n){
        cin >> v[i] >> w[i];
    }

    rep(i,n)rep(j,W+1){
        dp[i][j] = max(get(i-1,j),get(i-1,j-w[i])+v[i]);
    }
    rep(i,n){
        rep(j,W+1){
            printf("%3d ",dp[i][j]);
        }
        cout << endl;
    }
}