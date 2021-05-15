#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(ll x=0;x<y;x++)
#define rrep(x,y) for(ll x=y-1;x>=0;x--)
#define orep(x,y) for(ll x=1;x<=y;x++)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using P = pair<ll,ll>;
vector<vector<ll>> poll;
const ll inf = 1e9;
//+ = takahashi
string func(){
    ll h,w;
    cin >> h >> w;
    poll.resize(h,vector<ll>(w));
    vector<string> m(h);
    if(h==1&&w==1)return "Draw";
    rep(i,h)cin >> m[i];
    rrep(i,h){
        rrep(j,w){
            if(i==0&&j==0)break;
            if(i==h-1 && j==w-1){
                if((i+j) % 2 == 1)poll[i][j] = (m[i][j] == '+' ? 1 : -1);
                else poll[i][j] = (m[i][j] == '+' ? -1 : 1);
                continue;
            }
            if((i + j) % 2 == 1){
                ll score = -inf;
                //takahashi turn
                if(i + 1 < h)chmax(score, poll[i+1][j]);
                if(j + 1 < w)chmax(score, poll[i][j+1]);
                poll[i][j] = score + (m[i][j] == '+' ? 1 : -1);
            }else{
                //aoki turn
                ll score = inf;
                if(i + 1 < h)chmin(score, poll[i+1][j]);
                if(j + 1 < w)chmin(score, poll[i][j+1]);
                poll[i][j] = score + (m[i][j] == '+' ? -1 : 1);
            }
        }
    }
    ll score = -inf;
    if(h > 1)chmax(score, poll[1][0]);
    if(w > 1)chmax(score, poll[0][1]);
    if(score == 0){
        return "Draw";
    }
    if(score > 0){
        return "Takahashi";
    }
    return "Aoki";
}
int main(){
    cout << func() << endl;
}
