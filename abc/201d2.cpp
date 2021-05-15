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
vector<vector<int>> point;
const int inf = 1e9;
//+ = takahashi
string func(){
    int h,w;
    cin >> h >> w;
    point.resize(h,vector<int>(w));
    vector<string> m(h);
    rep(i,h)cin >> m[i];
    rep(i,h){
        rep(j,w){
            if(i==0 && j==0)continue;
            if((i + j) % 2 == 1){
                int score = -inf;
                //takahashi turn
                if(i - 1 >= 0)chmax(score, point[i-1][j]);
                if(j - 1 >= 0)chmax(score, point[i][j-1]);
                point[i][j] = score + (m[i][j] == '+' ? 1 : -1);
            }else{
                //aoki turn
                int score = inf;
                if(i - 1 >= 0)chmin(score, point[i-1][j]);
                if(j - 1 >= 0)chmin(score, point[i][j-1]);
                point[i][j] = score + (m[i][j] == '+' ? -1 : 1);
            }
        }
    }
    if(point[h-1][w-1] == 0){
        return "Draw";
    }
    if(point[h-1][w-1] > 0){
        return "Takahashi";
    }
    return "Aoki";
}
int main(){
    cout << func() << endl;
}
