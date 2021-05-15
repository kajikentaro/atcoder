#include<bits/stdc++.h>
#define MAX 2010
#define rep(x,y) for(int x=0;x<y;x++)
using namespace std;
struct P{
    int h,w;
    P(int h,int w):h(h),w(w){}
    P(){}
    void set(int h,int w){
        this->h = h;
        this->w = w;
    }
};
char dist[MAX][MAX];
int grid[MAX][MAX] = {};
int main(){
    int h,w;
    cin >> h >> w;
    rep(i,h)rep(j,w){
        cin >> grid[i][j];
    }
    P s,g;
    vector<vector<P>> warp(26);
    rep(i,h)rep(j,w){
        dist[MAX][MAX] = MAX;
        if(grid[i][j] == 'S')s = P(i,j);continue;
        if(grid[i][j] == 'G')g = P(i,j);continue;
        if(grid[i][j] == '.')continue;
        warp[grid[i][j] - 'a'].emplace_back(i,j);
    }
    queue<P> q;
    q.emplace(s.h,s.w);//TODO
    grid[s.h][s.w] = 0;
    int dh[] = {0,1,0,-1};
    int dw[] = {1,0,-1,0};
    while(q.size() != 0){
        P now = q.front();
        q.pop();
        rep(i,4){
            int nh = dh[i] + now.h;
            int nw = dw[i] + now.w;
            char new_grid = grid[nh][nw];
            int new_dist = grid[now.h][now.w]+1;

            if(nh < 0 || nw < 0 || nh >= h || nw >=w)continue;
            if(new_grid == '#')continue;
            if(grid[nh][nw] > new_dist){
                grid[nh][nw] = new_dist;
                q.emplace(nh,nw);
                if('a' <= new_grid && new_grid <= 'z'){
                    for (auto wa : warp[new_grid - 'a']){
                        dist[wa.h][wa.w] = new_dist;
                        warp[new_grid].resize(0);
                    }
                }
            }
        }
    }
    return 0;
}