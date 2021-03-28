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
using P = pair<int,int>;

vector<vector<char>> s;
int now_dir = 0;
P cursor;
P rotate(P input, int dir){
    if(dir==0)return input;
    return rotate(P{input.second, -input.first},--dir);
}
bool check_front_block(){
    P front_block_relative = rotate(P(-1,0), now_dir);
    P front_block = P(front_block_relative.first + cursor.first, front_block_relative.second + cursor.second);
    if(s[front_block.first][front_block.second] == '#')return true;
    return false;
}
bool check_front_right_block(){
    P front_block_relative = rotate(P(-1,1), now_dir);
    P front_block = P(front_block_relative.first + cursor.first, front_block_relative.second + cursor.second);
    if(s[front_block.first][front_block.second] == '#')return true;
    return false;
}
P go_front(){
    P go_relative = rotate(P(0,-1), now_dir);
    return P(cursor.first + go_relative.first, cursor.second + go_relative.second);
}
P go_front_right(){
    P go_relative = rotate(P(-1,1), now_dir);
    return P(cursor.first + go_relative.first, cursor.second + go_relative.second);
}
int main(){
    int h,w;
    cin >> h >> w;
    s.resize(h,vector<char>(w));
    P start = {-1,-1};
    rep(i,h){
        string input;
        cin >> input;
        rep(j,w){
            s[i][j] = input[j];
            if(s[i][j] == '#' && start == P(-1,-1))start = {i,j-1};
        }
    }
    cursor = start;
    int ans = 0;
    while(1){
        if(check_front_block()){
            ans++;
            now_dir = (now_dir + 3) % 4;
        }else if(check_front_right_block()){
            cursor = go_front();
        }else{
            cursor = go_front_right();
            ans++;
            now_dir = (now_dir + 1) % 4;
        }
        if(cursor == start && now_dir == 0)break;
    }
    cout << ans << endl;
}