#include<bits/stdc++.h>
#define rep(a,b) for(int a=0;a<b;a++)
using namespace std;
int main(){
    int h,w,k;
    cin >> h >> w >> k;
    vector<vector<char>> c(h,vector<char>(w));
    rep(i,h)rep(j,w)cin >> c[i][j];
    int ans = 0;
    rep(i,pow(2,h)){
        rep(j,pow(2,w)){
            int tmp_k = 0;
            rep(ii,h){
                if(i & 1 << ii)continue;
                rep(jj,w){
                    if(j & 1 << jj)continue;
                    if(c[ii][jj] == '#')tmp_k++;
                }
            }
            if(tmp_k == k){
                ans++;
            }
        }
    }
    cout << ans << endl;
}