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
    int h,w,x,y;
    cin >> h >> w >> x >> y;
    x--;y--;
    vector<string> s(h);
    rep(i,h){
        cin >> s[i];
    }
    int ans = 0;
    P dir[] = {{0,1},{1,0},{-1,0},{0,-1}};
    for(auto d : dir){
        P now = {x,y};
        while(now.first >= 0 && now.first <= h-1 && now.second >= 0 && now.second <= w-1){
            if(s[now.first][now.second] == '#')break;
            ans++;
            now.first += d.first;
            now.second += d.second;
        }
    }
    cout << ans - 3 << endl;
}
