//abc191c.cpp
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

#define add(a,b) P(a.first + b.first, a.second + b.second)
using P = pair<int,int>;
vector<vector<char>> s;
P rotate(P input, int dir){
    if(dir==0)return input;
    return rotate(P{input.second, -input.first},--dir);
}
int main(){
    int h,w;
    cin >> h >> w;
    s.resize(h,vector<char>(w));
    P start = {-1,-1};
    rep(i,h)rep(j,w){
        cin >> s[i][j];
        if(s[i][j] == '#' && start == P(-1,-1))start = {i,j};
    }
    P check_block_list[] = {{-1,-1},{-1,0}};
    int now_dir = 0;
    P cursor = start;
    int ans = 0;
    while(1){
        rep(i,3){
            if(i==2){
                now_dir = (now_dir + 1) % 4;
                ans++;
                break;
            }
            P check_block_path = add(rotate(check_block_list[i],now_dir),cursor);
            if(s[check_block_path.first][check_block_path.second] == '#'){
                if(i==0){
                    cursor = check_block_path;
                    now_dir = (now_dir + 3) % 4;
                    ans++;
                    break;
                }
                if(i==1){
                    cursor = check_block_path;
                    break;
                }
            }
        }
        if(cursor == start && now_dir == 0)break;
    }
    cout << ans << endl;
}