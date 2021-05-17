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
const int inf = 1e9;
string func(){
    int h,w;
    cin >> h >> w;
    vector<string> m(h);
    vector<vector<int>> dp(h,vector<int>(w));
    //takahashi +
    rep(i,h)cin >> m[i];
    rrep(i,h)rrep(j,w){
        if((i + j) % 2 == 1){
            //Aoki choice
            int score = m[i][j] == '+' ? 1 : -1;//青木が選ぶということはこの位置のスコアは高橋のもの。
            dp[i][j] = inf;
            if(i==h-1 && j==w-1)dp[i][j] = 0;
            if(i+1 <= h-1)chmin(dp[i][j], dp[i+1][j]);
            if(j+1 <= w-1)chmin(dp[i][j], dp[i][j+1]);
            dp[i][j] += score;
        }else{
            //Takahashi choice
            int score = m[i][j] == '+' ? -1 : 1;
            dp[i][j] = -inf;
            if(i==h-1 && j==w-1)dp[i][j] = 0;
            if(i+1 <= h-1)chmax(dp[i][j], dp[i+1][j]);
            if(j+1 <= w-1)chmax(dp[i][j], dp[i][j+1]);
            if(i == 0 && j == 0)continue;
            dp[i][j] += score;
        }
    }
    if(h == 1 && w == 1)return "Draw";
    if(dp[0][0] == 0)return "Draw";
    if(dp[0][0] > 0)return "Takahashi";
    if(dp[0][0] < 0)return "Aoki";
}
int main(){
    cout << func() << endl;
}