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
    int h,w;
    cin >> h >> w;
    vector<vector<int>> s(h,vector<int>(w));
    rep(i,h){
        string in;
        cin >> in;
        rep(j,w){
            if(in[j] == '#')s[i][j] = 1;
            else s[i][j] = 0;
        }
    }
    vector<vector<int>> grid(h+1,vector<int>(w+1));
    int ans = 0;
    rep(i,h+1)rep(j,w+1){
        if(i == 0||j == 0||i == h||j == w)continue;
        int block_count = s[i][j] + s[i-1][j-1]  + s[i-1][j]  +s[i][j-1];
        if(block_count % 2 == 1)ans++;
    }
    cout << ans << endl;
}
